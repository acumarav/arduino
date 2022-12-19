#include "TrafficLight.h"


void TrafficLight::init(){
  updateLedsBrightBrightness();
  redLed.init();
  yellowLed.init();
  greenBlinker.initLed();
  button.init();  

  transitionStart = 0;
  switchState("RED");
  //delay(100);
  button.isPressed();

}

/*
 * 2 sec yellow
 * 2 sec green
 * 2 sec blinking
 */
void TrafficLight::update(){
  updateLedsBrightBrightness();

  if(button.isPressed() && getState()=="RED"){
    transitionStart = millis(); 
    switchState("YELLOW");  
    return;    
  } 
  if(isStarted()){
    unsigned long secs =(millis()-transitionStart )/1000;
    if(secs==2 && getState()== "YELLOW"){
      switchState("GREEN");
    }
    if(secs>4 && secs<7){
      switchState("BLINK");
    }
    if(secs>=7){
      transitionStart = 0;
      switchState("RED");
    }
    
  }
  
}

void  TrafficLight::updateLedsBrightBrightness(){
   ledsBrightness = potentiometer.getValue()/4;
}

void TrafficLight::switchState(String newState){
  this->state = newState;
  Serial.println("STATE:" +state);

  if(newState == "RED"){
    redLed.on(ledsBrightness);
    yellowLed.off();
    greenLed.off();  
  }
  if(newState == "YELLOW"){
    yellowLed.on(ledsBrightness);
    redLed.off();
    greenLed.off();   
  }
  if(newState == "GREEN"){
    greenLed.on(ledsBrightness);
    redLed.off();
    yellowLed.off();   
  }
   if(newState == "BLINK"){
    greenBlinker.update();
    redLed.off();
    yellowLed.off(); 
  }
 
}

boolean TrafficLight::isStarted(){
  return (transitionStart > 0);
}
