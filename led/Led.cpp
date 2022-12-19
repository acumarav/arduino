#include "Led.h"

  Led::Led(byte pin){
    this->pin = pin;
    state = LOW;
  }

  void Led::init(){
    pinMode(pin, OUTPUT);
  }

  void Led::init(byte defaultState){
    init();
    if(defaultState == HIGH){
      on();
    }else{
      off();
    }
  }

  void Led::on(){
    state = HIGH;
    digitalWrite(pin, HIGH);
  }
  void Led::on(byte brightness){
    state = HIGH;
    analogWrite(pin, brightness);
  }

  void Led::off(){
    state = LOW;
    digitalWrite(pin, LOW);
  }

  void Led::toggle(){
    if(state == LOW){
      on();
    } else {
      off();
    }    
  }

  bool Led::isPoweredOn(){
    return (state == HIGH);
  }
