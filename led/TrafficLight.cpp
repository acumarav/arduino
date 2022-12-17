#include "TrafficLight.h"


void TrafficLight::init(){
  redLed.init();
  yellowLed.init();
  greenBlinker.initLed();
  button.init();  
  potentiometer.init();

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

void TrafficLight::switchState(String newState){
  this->state = newState;
  Serial.println("STATE:" +state);

  if(newState == "RED"){
    redLed.on();
    yellowLed.off();
    greenLed.off();  
  }
  if(newState == "YELLOW"){
    yellowLed.on();
    redLed.off();
    greenLed.off();   
  }
  if(newState == "GREEN"){
    greenLed.on();
    redLed.off();
    yellowLed.off();   
  }
   if(newState == "BLINK"){
    greenBlinker.update();
    redLed.off();
    yellowLed.off(); 
  }
//  switch(newState){
//    case "RED":
//      redLed.on();
//      Serial.println("RED ON");
//      break;
//    case "YELLOW":
//      yellowLed.on();
//       Serial.println("YELLOW ON");
//      break;
//    case "GREEN":
//     greenLed.on();
//     Serial.println("GREEN ON");
//     break;
//    case "BLINK":
//    default:
//     Serial.println("BAD VALUE");
//    break;
//    ;
//  }
  
}

boolean TrafficLight::isStarted(){
  return (transitionStart > 0);
}
