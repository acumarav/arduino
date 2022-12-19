#include "Potentiometer.h"

Potentiometer::Potentiometer(byte pin){
  this->pin=pin;
}

int Potentiometer::getValue(){
  return analogRead(pin);
  
}
