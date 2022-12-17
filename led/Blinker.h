#ifndef LED_BLINKER_H
#define LED_BLINKER_H

#include <Arduino.h>
#include "Led.h"

class Blinker {
  private: 
    Led led;
    unsigned long lastTimeBlinked;
    unsigned long blinkDelay;

    void toggleLed();

  public:
    Blinker(){}//do not use
    Blinker(Led &led);
    Blinker(Led &led, unsigned long blinkDelay);

    void initLed();

    void update();

  //getters and setters
    unsigned long getBlinkDelay(){
      return blinkDelay;
    };
    void setBlinkDelay(unsigned long blinkDelay){
      this->blinkDelay = blinkDelay;
    };
};


#endif
