/*
Led.cpp - LED library for Arduino

Copyright (c) 2013 Matt Parish. All rights reserved.
Last modified: 07/04/2013
*/

#include "Led.h"

Led::Led(unsigned int pin) {

    _pin = pin;
    _prevMillis = millis();
    _state = HIGH;

    pinMode(_pin, OUTPUT);

    // Start with the LED turned on
    digitalWrite(_pin, _state);
}

bool Led::isLit() {

    if(_state == HIGH) {
        return true;
    } else {
        return false;
    }
}

void Led::toggle() {

    switch(_state) {
    case HIGH: _state = LOW; break;
    case LOW: _state = HIGH; break;
    default: _state = HIGH;
    }

    digitalWrite(_pin, _state);
}

void Led::blink(unsigned int milliseconds) {

    unsigned long currMillis = millis();
  
    // If the specified time interval has passed
    if(currMillis - _prevMillis > milliseconds) {
        toggle();
    
        _prevMillis = currMillis;
    }
}

void Led::blink(unsigned int onMillis, unsigned int offMillis) {

    unsigned long currMillis = millis();

    switch(_state) {

    case HIGH:

        // If the specified on interval has passed
        if(currMillis - _prevMillis > onMillis) {

            toggle();

            _prevMillis = currMillis;
        }
        break;

    case LOW:

        // If the specified off interval has passed
        if(currMillis - _prevMillis > offMillis) {

            toggle();

            _prevMillis = currMillis;
        }
        break;
    default: break;
    }
}
