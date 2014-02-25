/*
Move the robot forward for one second
*/

#include <Servo.h>

Servo servoLeft, servoRight;

void setup() {
  // Play startup tone for one second
  tone(4, 3000, 1000);
  delay(1000);
  
  // Set the pins for the servos
  servoLeft.attach(12);
  servoRight.attach(11);
  
  // Set the direction for the servos
  servoLeft.writeMicroseconds(1390);      // CW
  servoRight.writeMicroseconds(1700);      // CCW
  
  // Move for ten second
  delay(10000);
  
  // Stop and detach both servos
  servoLeft.detach();
  servoRight.detach();
}

void loop() {
  // Nothing to repeat
}
