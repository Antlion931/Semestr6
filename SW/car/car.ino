#include "LiquidCrystal_I2C.h"
#include "Wheels.h"
#include "TimerOne.h"

#include <Arduino.h>
#include <IRremote.hpp> 

const uint16_t IRB_ONE = 0x45;
const uint16_t IRB_TWO = 0x46;
const uint16_t IRB_THREE = 0x47;
const uint16_t IRB_FOUR = 0x44;
const uint16_t IRB_FIVE = 0x40;
const uint16_t IRB_SIX = 0x43;
const uint16_t IRB_SEVEN = 0x7;
const uint16_t IRB_EIGHT = 0x15;
const uint16_t IRB_NINE = 0x9;
const uint16_t IRB_STAR = 0x16;
const uint16_t IRB_ZERO = 0x19;
const uint16_t IRB_HASH = 0xD;
const uint16_t IRB_UP = 0x18;
const uint16_t IRB_LEFT = 0x8;
const uint16_t IRB_RIGHT = 0x5A;
const uint16_t IRB_DOWN = 0x52;
const uint16_t IRB_OK = 0x1C;

byte LCDAddress = 0x27;

const int DIOD = 13;

const int IN1 = 7;
const int IN2 = 6;
const int IN3 = 5;
const int IN4 = 4;

const int EnA = 11;
const int EnB = 3;

const int IR_RECEIVE_PIN = 2;

typedef int cm;

LiquidCrystal_I2C lcd(LCDAddress, 16, 2);
Wheels* wheels = Wheels::getInstance();

void setup() {

  IrReceiver.begin(IR_RECEIVE_PIN);

  Serial.begin(9600);

  lcd.init();
  lcd.backlight();

  wheels->attachLeft(IN1, IN2, EnA);
  wheels->attachRight(IN4, IN3, EnB);
  wheels->setSpeedLeft(100);
  wheels->setSpeedRight(100);
  wheels->setDiod(DIOD);
  wheels->setDashboard(&lcd);
  wheels->back();
}

void loop() { 
      if (IrReceiver.decode()) {

        /*
         * Print a summary of received data
         */
        if (IrReceiver.decodedIRData.protocol == UNKNOWN) {
            Serial.println(F("Received noise or an unknown (or not yet enabled) protocol"));
            // We have an unknown protocol here, print extended info
            IrReceiver.printIRResultRawFormatted(&Serial, true);
            IrReceiver.resume(); // Do it here, to preserve raw data for printing with printIRResultRawFormatted()
        } else {
            IrReceiver.resume(); // Early enable receiving of the next IR frame
            IrReceiver.printIRResultShort(&Serial);
        }
        Serial.println();

        switch (IrReceiver.decodedIRData.command) {
          case IRB_UP:
            wheels->forward();
            break;
          case IRB_LEFT:
            wheels->forwardLeft();
            break;
          case IRB_RIGHT:
            wheels->forwardRight();
            break;
          case IRB_DOWN:
            wheels->back();
            break;
          case IRB_OK:
            wheels->stop();
            break;
          case IRB_ONE:
            wheels->setSpeed(100);
            break;
          case IRB_TWO:
            wheels->setSpeed(150);
            break;
          case IRB_THREE:
            wheels->setSpeed(200);
            break;
        }
    }
}

