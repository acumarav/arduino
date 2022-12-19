#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H

#include <Arduino.h>

class Potentiometer {
  private:
    byte pin;

  public:
    Potentiometer(){}//do not use
    Potentiometer(byte pin);

    int getValue();
   
};
#endif
