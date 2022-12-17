#ifndef TRAFFIC_LIGHT_H
#define TRAFFIC_LIGHT_H

#include <Arduino.h>
#include "Led.h"
#include "Blinker.h"
#include "PushButton.h"
#include "Potentiometer.h"

enum LightState { RED, YELLOW, GREEN, BLINK };

class TrafficLight {
  private:
    Led redLed;
    Led yellowLed;
    Led greenLed;
    Blinker greenBlinker;
    PushButton button;
    Potentiometer potentiometer;
    unsigned long transitionStart;

    bool isStarted();
    String state;

    void switchState(String state);
    

  public:
  TrafficLight(){}//do not use
  TrafficLight(Led redLed, Led yellowLed, Led greenLed, Blinker greenBlinker, PushButton button, Potentiometer potentiometer){
    this->redLed = redLed;
    this->yellowLed = yellowLed;
    this->greenLed = greenLed;
    this->greenBlinker = greenBlinker;
    this->button = button;
    this->potentiometer = potentiometer;
  }

  void init();

  void update();
  
  //getters and setters
  String getState(){return this->state;}
  
  
};


#endif
