#include <Arduino.h>

#include "Wheels.h"


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

Wheels::Wheels() { 
  this->is_going_back = false;
}

Wheels* Wheels::getInstance() {
  if (instance == nullptr) {
    instance = new Wheels();
  }

  return instance;
}

uint32_t Wheels::getSpeedRight() {
    return this->speedRight;
}

uint32_t Wheels::getSpeedLeft() {
    return this->speedLeft;
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
    this->speedRight = s;
    analogWrite(this->pinsRight[2], this->speedRight);
}

void Wheels::setSpeedLeft(uint8_t s)
{
    this->speedLeft = s;
    analogWrite(this->pinsLeft[2], this->speedLeft);
}

void Wheels::setSpeed(uint8_t s)
{
    setSpeedLeft(s);
    setSpeedRight(s);
    updateDashboard();
}

void Wheels::attach(int pRF, int pRB, int pRS, int pLF, int pLB, int pLS)
{
    this->attachRight(pRF, pRB, pRS);
    this->attachLeft(pLF, pLB, pLS);
}

void Wheels::forwardLeft() 
{
      if (this->is_going_back) {
      this->is_going_back = false;
    }
    SET_MOVEMENT(pinsLeft, HIGH, LOW);
    this->updateDashboard();
}

void Wheels::forwardRight() 
{
      if (this->is_going_back) {
      this->is_going_back = false;
    }
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
      if (this->is_going_back) {
      this->is_going_back = false;
    }
    this->forwardLeft();
    this->forwardRight();
    this->updateDashboard();
}

void Wheels::back()
{
    this->backLeft();
    this->backRight();
    this->updateDashboard();

    if (!this->is_going_back) {
        this->is_going_back = true;
    }
}

bool Wheels::isGoingBack() {
  return this->is_going_back;
}

void Wheels::stopLeft()
{
      if (this->is_going_back) {
      this->is_going_back = false;
    }
    SET_MOVEMENT(pinsLeft, LOW, LOW);
    this->updateDashboard();
}

void Wheels::stopRight()
{
      if (this->is_going_back) {
      this->is_going_back = false;
    }
    SET_MOVEMENT(pinsRight, LOW, LOW);
    this->updateDashboard();
}

void Wheels::stop()
{
    if (this->is_going_back) {
      this->is_going_back = false;
    }
    this->stopLeft();
    this->stopRight();
    this->updateDashboard();
}

void Wheels::setDashboard(LiquidCrystal_I2C* dashboard) {
  this->dashboard = dashboard;
  this->updateDashboard();
}

String reverseString(String *original) {
  String result = "";

  for(int i = 1; i <= original->length(); i++) {
    result += original->charAt(original->length() - i);
  }

  return result;
}

// Dashboard is lcd with 16x2 size
void set_Dashboard(LiquidCrystal_I2C* dashboard, int speedLeft, int speedRight, MotorState left, MotorState right) {
    dashboard->clear();
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
    MotorState leftState = MotorState::Stop;

    if (digitalRead(this->pinsLeft[0]) == LOW && digitalRead(this->pinsLeft[1]) == HIGH) {
      leftState = MotorState::Backward;
    } else if (digitalRead(this->pinsLeft[0]) == HIGH && digitalRead(this->pinsLeft[1]) == LOW) {
      leftState = MotorState::Forward;
    }

    MotorState rightState = MotorState::Stop;

    if (digitalRead(this->pinsRight[0]) == LOW && digitalRead(this->pinsRight[1]) == HIGH) {
      rightState = MotorState::Backward;
    } else if (digitalRead(this->pinsRight[0]) == HIGH && digitalRead(this->pinsRight[1]) == LOW) {
      rightState = MotorState::Forward;
    }

    set_Dashboard(this->dashboard, this->getSpeedLeft(), this->getSpeedRight(), leftState, rightState);
}

