#ifndef PUSH_BUTTON_H
#define PUSH_BUTTON_H

#include <Arduino.h>




class PushButton {
  private:
    byte pin;
    byte state;

    bool isPullUp;
    bool internalPullUpActivated;
    unsigned long lastTimeStateChanged;
    unsigned long debounceDelay;

    void readState();

  public:
    PushButton(){} //do not use
    PushButton(byte pin, bool isPullUp, bool internalPullUpActivated);

    void init();
    
    bool isPressed();

};
#endif
