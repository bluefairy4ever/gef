/*
Generate signal to make the servo stay still for centering.
*/

#include <Servo.h>

Servo servoLeft;

void setup() {
  // Attach left siganl to pin 13
  servoLeft.attach(12);
  // 90 degree stay still angle
  servoLeft.writeMicroseconds(1500);
}

void loop() {
  // Nothing needs repeating
}
