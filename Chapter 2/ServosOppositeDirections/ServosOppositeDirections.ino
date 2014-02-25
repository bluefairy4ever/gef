/*
Generate a servo full speed counterclockwise signal for pin 13
and full speed clockwise signal for pin 12.
*/

#include <Servo.h>

Servo servoLeft;
Servo servoRight;

void setup() {
  // Attach left siganl to pin 13
  servoLeft.attach(13);
  // Attach right siganl to pin 12
  servoRight.attach(12);
  // 1.7 ms CCW signal
  servoLeft.writeMicroseconds(1700);
  // 1.3 ms CW signal
  servoRight.writeMicroseconds(1300);
}

void loop() {
  // Nothing needs repeating
}
