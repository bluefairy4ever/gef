/*
Generate signal to make the left servo turn full speed
clockwise.
*/

#include <Servo.h>

Servo servoLeft;

void setup() {
  // Attach left siganl to pin 12
  servoLeft.attach(12);
  // 0 degree CW angle
  servoLeft.write(0);
}

void loop() {
  // Nothing needs repeating
}
