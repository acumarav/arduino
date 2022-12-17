#define RED_LED_PIN 11
#define YELLOW_LED_PIN 10
#define GREEN_LED_PIN 9

#define BUTTON_PIN 2
#define POTENTIOMETER_PIN A0


#include "Led.h"
#include "PushButton.h"
#include "Blinker.h"
#include "TrafficLight.h"
#include "Potentiometer.h"

//PushButton button(BUTTON_PIN, true, true);
PushButton button(BUTTON_PIN, true, true);
Potentiometer potentiometer(POTENTIOMETER_PIN);

Led redLed(RED_LED_PIN);
Led yellowLed(YELLOW_LED_PIN);
Led greenLed(GREEN_LED_PIN);

Blinker redBlinker(redLed);
Blinker yellowBlinker(yellowLed, 1000);
Blinker greenBlinker(greenLed, 250);

Led stub(7);

TrafficLight trafficLight(redLed, yellowLed, greenLed, greenBlinker, button, potentiometer);

void setup(){
  Serial.begin(115200);
  trafficLight.init();

  //test_init();  
}

void loop(){
  //test_loop();  
  trafficLight.update();

  if(button.isPressed()){
    Serial.println("Button is pressed");
  } else {
    //Serial.println("Button is NOT pressed");
  }
}



void test_init(){
  redBlinker.initLed();
  yellowBlinker.initLed();
  greenBlinker.initLed();
  
  stub.init();
  button.init();  
}

void test_loop(){
  unsigned long second = millis()/1000;
  if(second %  2 == 0){
    stub.on();
  } else {
    stub.off();
  }

  redBlinker.update();
  yellowBlinker.update();
  greenBlinker.update();

if(button.isPressed()){
  Serial.println("Button is pressed");
  redLed.on();
  yellowLed.off();
  greenLed.on();
} else {
  Serial.println("Button is NOT pressed");
  //redLed.off();
  //yellowLed.on();
  //greenLed.off();
}
  
}
