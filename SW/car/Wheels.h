/* 
 * prosta implementacja klasy obsługującej 
 * silniki pojazdu za pośrednictwem modułu L298
 *
 * Sterowanie odbywa się przez:
 * 1)  powiązanie odpowiednich pinów I/O Arduino metodą attach() 
 * 2)  ustalenie prędkości setSpeed*()
 * 3)  wywołanie funkcji ruchu
 *
 * TODO:
 *  - zabezpieczenie przed ruchem bez attach()
 *  - ustawienie domyślnej prędkości != 0
 */


#include <Arduino.h>
#include "LiquidCrystal_I2C.h"


#ifndef Wheels_h
#define Wheels_h

class Wheels {
    public: 

        /*
         *  pinForward - wejście "naprzód" L298
         *  pinBack    - wejście "wstecz" L298
         *  pinSpeed   - wejście "enable/PWM" L298
         */
        void attachRight(int pinForward, int pinBack, int pinSpeed);
        void attachLeft(int pinForward, int pinBack, int pinSpeed);
        void attach(int pinRightForward, int pinRightBack, int pinRightSpeed,
                    int pinLeftForward, int pinLeftBack, int pinLeftSpeed);
        /*
         *  funkcje ruchu
         */
        void forward();
        void forwardLeft();
        void forwardRight();
        void back();
        void backLeft();
        void backRight();
        void stop();
        void stopLeft();
        void stopRight();

        /*
         *  ustawienie prędkości obrotowej (przez PWM)
         *   - minimalna efektywna wartość 60
         *      może zależeć od stanu naładowania baterii
         */
        void setSpeed(uint8_t);
        void setSpeedRight(uint8_t);
        void setSpeedLeft(uint8_t);

        void setDiod(int);
        int getDiod();

        void setDashboard(LiquidCrystal_I2C*);

        static Wheels* getInstance();

        uint32_t getSpeedRight();
        uint32_t getSpeedLeft();

    private: 
        Wheels();
        static Wheels* instance;
        LiquidCrystal_I2C* dashboard = nullptr;
        void updateDashboard();

        int speedLeft;
        int speedRight;

        int pinsRight[3];
        int pinsLeft[3];
        int diod;

        void timerUpdate();

};

enum MotorState {
  Forward,
  Backward,
  Stop,
};

void set_Dashboard(LiquidCrystal_I2C* dashboard, int speedLeft, int speedRight, MotorState left, MotorState right);


#endif
