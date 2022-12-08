#define RED_LED_PIN 11
#define YELLOW_LED_PIN 10
#define GREEN_LED_PIN 9

#define BUTTON_PIN 2


#include "Led.h"
#include "PushButton.h"

PushButton button(BUTTON_PIN, true, true);

Led redLed(RED_LED_PIN);
Led yellowLed(YELLOW_LED_PIN);
Led greenLed(GREEN_LED_PIN);

Led stub(7);

void setup(){
  Serial.begin(115200);
  
  redLed.init();
  yellowLed.init();
  greenLed.init();
  
  stub.init();
  button.init();
}


void loop(){
  unsigned long second = millis()/1000;
  if(second %  2 == 0){
    stub.on();
  } else {
    stub.off();
  }

if(button.isPressed()){
  Serial.println("Button is pressed");
  redLed.on();
  yellowLed.off();
  greenLed.on();
} else {
  Serial.println("Button is NOT pressed");
  redLed.off();
  yellowLed.on();
  greenLed.off();
  
}
  
}
