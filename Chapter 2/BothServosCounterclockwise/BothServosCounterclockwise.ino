/*
Generate signals to make both servos turn full speed
counter-clockwise.
*/

#include <Servo.h>

Servo servoLeft;
Servo servoRight;

void setup() {
  // Attach left siganl to pin 12
  servoLeft.attach(12);
  // Attach right siganl to pin 11
  servoRight.attach(11);
  // 180 degree CCW angle
  servoLeft.write(180);
  servoRight.write(180);
}

void loop() {
  // Nothing needs repeating
}
