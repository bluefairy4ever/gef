/*
Generate signal to make the Right servo turn full speed
counter-clockwise.
*/

#include <Servo.h>

Servo servoRight;

void setup() {
  // Attach Right siganl to pin 11
  servoRight.attach(11);
  // 180 degree CCW angle
  servoRight.write(180);
}

void loop() {
  // Nothing needs repeating
}
