/*
Generate signal to make the servo stay still for centering.
*/

#include <Servo.h>

Servo servoLeft;
Servo servoRight;

void setup() {
  // Attach left siganl to pin 13
  servoLeft.attach(13);
  // Attach right siganl to pin 12
  servoRight.attach(12);
  
  // Set both servos to run full-speed clockwise
  servoLeft.writeMicroseconds(1300);
  servoRight.writeMicroseconds(1300);
  
  // Run them for 3 seconds
  delay(3000);
  
  // Set both servos to run full-speed clockwise
  servoLeft.writeMicroseconds(1700);
  servoRight.writeMicroseconds(1700);
  
  // Run them for 3 seconds
  delay(3000);
  
  // Stop both servos
  servoLeft.writeMicroseconds(1500);
  servoRight.writeMicroseconds(1500);
}

void loop() {
  // Nothing needs repeating
}
