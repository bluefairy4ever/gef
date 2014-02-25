/*
Generate signal to make the Right servo turn full speed
clockwise.
*/

#include <Servo.h>

Servo servoRight;

void setup() {
  // Attach Right siganl to pin 11
  servoRight.attach(11);
  // 0 degree CW angle
  servoRight.write(0);
}

void loop() {
  // Nothing needs repeating
}
