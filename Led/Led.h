/*
Led.h - LED library for Arduino

Copyright (c) 2013 Matt Parish. All rights reserved.
Last modified: 07/04/2013
*/

#ifndef Led_h
#define Led_h

#include "Arduino.h"

class Led {
public:
    /** Led(unsigned int pin)
    *   Default Constructor.
    *   An LED is lit when created.
    *   @param pin The pin on which the LED runs.
    **/
    Led(unsigned int pin);
    
    /** bool isLit()
    *   @return true if the LED is lit, false otherwise.
    **/
    bool isLit();

    /** void toggle()
    *   Toggles the state of the LED (on or off).
    **/
    void toggle();

    /** void blink(unsigned int interval)
    *   Blinks the LED with the same on/off time interval.
    *   @param milliseconds The interval (in milliseconds) at which to blink.
    **/
    void blink(unsigned int milliseconds);

    /** void blink(unsigned int onMillis, unsigned int offMillis)
    *   Blinks the LED with separate on/off time intervals.
    *   @param onTime The amount of time (in milliseconds) to keep the LED on.
    *   @param offTime The amount of time (in milliseconds) to keep the LED off.
    **/
    void blink(unsigned int onMillis, unsigned int offMillis);

private:
    unsigned int _pin;

    unsigned long _prevMillis;
    unsigned int _state;
};

#endif
