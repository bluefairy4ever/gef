/*
Eyes.cpp - Robot eyes library for Arduino.

Copyright (c) 2013 Matt Parish. All rights reserved.
*/

#include "Eyes.h"

/** Eyes(unsigned int leftPin, unsigned int rightPin)
*   Default constructor.
*   The eyes are lit when created.
*   @param leftPin The pin on which the left eye runs.
*   @param rightPin The pin on which the right eye runs.
**/
Eyes::Eyes(unsigned int leftPin, unsigned int rightPin) {

    _left = new Led(leftPin);
    _right = new Led(rightPin);
}

/** ~Eyes()
*   Deconstructor
*   Cleans up memory used by this instance of Eyes.
**/
Eyes::~Eyes() {

    delete _left;
    delete _right;
}

/** void toggle()
*   Toggles the state of the eyes (on or off).
**/
void Eyes::toggle() {

    toggleLeft();
    toggleRight();
}

/** void toggleLeft()
*   Toggles the state of the left eye (on or off).
**/
void Eyes::toggleLeft() { _left->toggle(); }

/** void toggleRight()
*   Toggles the state of the right eye (on or off).
**/
void Eyes::toggleRight() { _right->toggle(); }

/** void blink(unsigned int interval)
*   Blinks the eyes together with the same on/off time interval.
*   @param milliseconds The interval (in milliseconds) at which to blink.
**/
void Eyes::blink(unsigned int milliseconds) {

    blink(milliseconds, milliseconds);
}
    
/** void blink(unsigned int onMillis, unsigned int offMillis)
*   Blinks the eyes together with separate on/off time intervals.
*   @param onTime The amount of time (in milliseconds) to keep the eyes on.
*   @param offTime The amount of time (in milliseconds) to keep the eyes off.
**/
void Eyes::blink(unsigned int onMillis, unsigned int offMillis) {

    _left->blink(onMillis, offMillis);
    _right->blink(onMillis, offMillis);
}

/** void wink(unsigned int eye, unsigned int milliseconds)
*   Winks an eye for the given amount of time.
*   @param eye The eye to wink (LEFT or RIGHT)
*   @param milliseconds The amount of time to keep the eye off.
**/
void Eyes::wink(unsigned int eye, unsigned int milliseconds) {

    switch(eye) {
    case EYE_LEFT: winkLeft(milliseconds); break;
    case EYE_RIGHT: winkRight(milliseconds); break;
    default: break;
    }
}

/** void winkLeft(unsigned int milliseconds)
*   Winks the left eye for the given amount of time.
*   @param milliseconds The amount of time to keep the eye off.
**/
void Eyes::winkLeft(unsigned int milliseconds) {

    _left->toggle();
    delay(milliseconds);
    _left->toggle();
}

/** void winkRight(unsigned int milliseconds)
*   Winks the right eye for the given amount of time.
*   @param milliseconds The amount of time to keep the eye off.
**/
void Eyes::winkRight(unsigned int milliseconds) {

    _right->toggle();
    delay(milliseconds);
    _right->toggle();
}
