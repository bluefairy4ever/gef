/*
Generate signals to make both servos turn full speed
clockwise.
*/

#include <Servo.h>

Servo servoLeft;
Servo servoRight;

void setup() {
  // Attach left siganl to pin 12
  servoLeft.attach(12);
  // Attach right siganl to pin 11
  servoRight.attach(11);
  // 0 degree CW angle
  servoLeft.write(0);
  servoRight.write(0);
}

void loop() {
  // Nothing needs repeating
}
