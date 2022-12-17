#include "Blinker.h"

Blinker::Blinker(Led &led){
  this->led = led;
  lastTimeBlinked = millis();
  blinkDelay = 500;
}

Blinker::Blinker(Led &led, unsigned long blinkDelay){
  this->led = led;
  lastTimeBlinked = millis();
  this->blinkDelay = blinkDelay;
}

void Blinker::initLed() {
  led.init();
}

void Blinker::toggleLed(){
  led.toggle();  
}

void Blinker::update(){
  unsigned long now = millis();
  if(now-lastTimeBlinked > blinkDelay) {
    toggleLed();
    lastTimeBlinked = now;
  }
}
