/*
Eyes.h - Robot eyes library for Arduino.

Copyright (c) 2013 Matt Parish. All rights reserved.
*/

#ifndef Eyes_h
#define Eyes_h

#include "Led.h"

#define EYE_LEFT 1
#define EYE_RIGHT 2

class Eyes {
public:

    /** Eyes(unsigned int leftPin, unsigned int rightPin)
    *   Default constructor.
    *   The eyes are lit when created.
    *   @param leftPin The pin on which the left eye runs.
    *   @param rightPin The pin on which the right eye runs.
    **/
    Eyes(unsigned int leftPin, unsigned int rightPin);

    /** ~Eyes()
    *   Deconstructor
    *   Cleans up memory used by this instance of Eyes.
    **/
    ~Eyes();

    /** void toggle()
    *   Toggles the state of the eyes (on or off).
    **/
    void toggle();

    /** void toggleLeft()
    *   Toggles the state of the left eye (on or off).
    **/
    void toggleLeft();

    /** void toggleRight()
    *   Toggles the state of the right eye (on or off).
    **/
    void toggleRight();

    /** void blink(unsigned int interval)
    *   Blinks the eyes together with the same on/off time interval.
    *   @param milliseconds The interval (in milliseconds) at which to blink.
    **/
    void blink(unsigned int milliseconds);
    
    /** void blink(unsigned int onMillis, unsigned int offMillis)
    *   Blinks the eyes together with separate on/off time intervals.
    *   @param onTime The amount of time (in milliseconds) to keep the eyes on.
    *   @param offTime The amount of time (in milliseconds) to keep the eyes off.
    **/
    void blink(unsigned int onMillis, unsigned int offMillis);

    /** void wink(unsigned int eye, unsigned int milliseconds)
    *   Winks an eye for the given amount of time.
    *   @param eye The eye to wink (LEFT or RIGHT)
    *   @param milliseconds The amount of time to keep the eye off.
    **/
    void wink(unsigned int eye, unsigned int milliseconds);

private:
    Led* _left;
    Led* _right;

    /** void winkLeft(unsigned int milliseconds)
    *   Winks the left eye for the given amount of time.
    *   @param milliseconds The amount of time to keep the eye off.
    **/
    void winkLeft(unsigned int milliseconds);

    /** void winkRight(unsigned int milliseconds)
    *   Winks the right eye for the given amount of time.
    *   @param milliseconds The amount of time to keep the eye off.
    **/
    void winkRight(unsigned int milliseconds);
};

#endif
