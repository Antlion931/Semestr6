#include <Arduino.h>

#include "Wheels.h"
#include "TimerOne.h"

#define SET_MOVEMENT(side,f,b) digitalWrite( side[0], f);\
                               digitalWrite( side[1], b)

static Wheels* Wheels::instance;

void Wheels::setDiod(int d) {
  pinMode(diod, OUTPUT);
  this->diod = d;
}

int Wheels::getDiod() {
  return this->diod;
}

const long speed_multiplayer = 10;

Wheels::Wheels() { 
  Timer1.initialize();
}

Wheels* Wheels::getInstance() {
  if (instance == nullptr) {
    instance = new Wheels();
  }

  return instance;
}

uint8_t Wheels::getSpeedRight() {
    return pinsRight[2];
}

uint8_t Wheels::getSpeedLeft() {
    return pinsLeft[2];
}

void Wheels::attachRight(int pF, int pB, int pS)
{
    pinMode(pF, OUTPUT);
    pinMode(pB, OUTPUT);
    pinMode(pS, OUTPUT);
    this->pinsRight[0] = pF;
    this->pinsRight[1] = pB;
    this->pinsRight[2] = pS;
}


void Wheels::attachLeft(int pF, int pB, int pS)
{
    pinMode(pF, OUTPUT);
    pinMode(pB, OUTPUT);
    pinMode(pS, OUTPUT);
    this->pinsLeft[0] = pF;
    this->pinsLeft[1] = pB;
    this->pinsLeft[2] = pS;
}

void Wheels::setSpeedRight(uint8_t s)
{
    analogWrite(this->pinsRight[2], s);
}

void Wheels::setSpeedLeft(uint8_t s)
{
    analogWrite(this->pinsLeft[2], s);
}

void Wheels::setSpeed(uint8_t s)
{
    setSpeedLeft(s);
    setSpeedRight(s);
}

void Wheels::attach(int pRF, int pRB, int pRS, int pLF, int pLB, int pLS)
{
    this->attachRight(pRF, pRB, pRS);
    this->attachLeft(pLF, pLB, pLS);
}

void Wheels::forwardLeft() 
{
    SET_MOVEMENT(pinsLeft, HIGH, LOW);
    this->updateDashboard();
}

void Wheels::forwardRight() 
{
    SET_MOVEMENT(pinsRight, HIGH, LOW);
    this->updateDashboard();
}

void Wheels::backLeft()
{
    SET_MOVEMENT(pinsLeft, LOW, HIGH);
    this->updateDashboard();
}

void Wheels::backRight()
{
    SET_MOVEMENT(pinsRight, LOW, HIGH);
    this->updateDashboard();
}

void Wheels::forward()
{
    this->forwardLeft();
    this->forwardRight();
    this->updateDashboard();
}

void Wheels::back()
{
    this->backLeft();
    this->backRight();
    timerUpdate();
}

void Wheels::stopLeft()
{
    SET_MOVEMENT(pinsLeft, LOW, LOW);
    this->updateDashboard();
}

void Wheels::stopRight()
{
    SET_MOVEMENT(pinsRight, LOW, LOW);
    this->updateDashboard();
}

void Wheels::stop()
{
    Timer1.detachInterrupt();
    this->stopLeft();
    this->stopRight();
    this->updateDashboard();
}

void doBeep() {
  Wheels* w = Wheels::getInstance();

  digitalWrite(w->getDiod(), digitalRead(w->getDiod()) ^ 1);
}

void Wheels::timerUpdate() {
  Timer1.detachInterrupt();
  Timer1.attachInterrupt(doBeep, 5000000);
}

void Wheels::setDashboard(LiquidCrystal_I2C* dashboard) {
  this->dashboard = dashboard;
}

enum MotorState {
  Forward,
  Backward,
  Stop,
};




String reverseString(String *original) {
  String result = "";

  for(int i = 1; i <= original->length(); i++) {
    result += original->charAt(original->length() - i);
  }

  return result;
}



// Dashboard is lcd with 16x2 size
void set_Dashboard(LiquidCrystal_I2C* dashboard, int speedLeft, int speedRight, MotorState left, MotorState right) {
    dashboard->setCursor(0,0);

    switch (left) {
      case Forward:
          dashboard->print("F");
          break;

      case Backward:
        dashboard->print("B");
        break;
      case Stop:
        dashboard->print("S");
        break;
    }

    dashboard->setCursor(15, 0);

    switch (right) {
      case Forward:
          dashboard->print("F");
          break;

      case Backward:
        dashboard->print("B");
        break;
      case Stop:
        dashboard->print("S");
        break;
    }


    dashboard->setCursor(0, 1);
    dashboard->print(String(speedLeft));


    dashboard->rightToLeft();
    dashboard->setCursor(15, 1);

    dashboard->print(reverseString(&String(speedRight)));
    dashboard->leftToRight();
}


void Wheels::updateDashboard() {
    set_Dashboard(this->dashboard, this->getSpeedLeft(), this->getSpeedRight(), MotorState::Forward, MotorState::Stop);
}

