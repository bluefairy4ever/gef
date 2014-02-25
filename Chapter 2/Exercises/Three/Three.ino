/*
BOE-Bot Chapter 2 Exercise 3:
Write a setup function that makes one servo turn the same direction for 3 seconds. 
The other servo should turn the opposite direction for the first 1.5 seconds and 
the same direction for the second 1.5 seconds.  Then, make both servos stop.
*/

#include <Servo.h>

Servo servoLeft, servoRight;

void setup() {
  // Set servo left to run on pin 13
  servoLeft.attach(13);
  
  // Set servo right to run on pin 12
  servoRight.attach(12);
  
  // Run the left servo CCW
  servoLeft.write(1700);
  
  // Run the right servo CW
  servoRight.write(1300);
  
  // Run for 1.5 seconds
  delay(1500);
  
  // Turn the right servo around to run CCW
  servoRight.write(1700);
  
  // Run for the last 1.5 seconds
  delay(1500);
  
  // Stop both servos
  servoLeft.detach();
  servoRight.detach();
}

void loop() {
  // Nothing to repeat
}
