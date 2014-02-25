/*
Generate signal to make the servo stay still for centering.
*/

#include <Servo.h>

Servo servoRight;

void setup() {
  // Attach left siganl to pin 13
  servoRight.attach(11);
  // 90 degree stay still angle
  servoRight.writeMicroseconds(1500);
}

void loop() {
  // Nothing needs repeating
}
