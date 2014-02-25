/*
Generate signal to make the left servo turn full speed
counter-clockwise.
*/

#include <Servo.h>

Servo servoLeft;

void setup() {
  // Attach left siganl to pin 12
  servoLeft.attach(12);
  // 180 degree CCW angle
  servoLeft.write(180);
}

void loop() {
  // Nothing needs repeating
}
