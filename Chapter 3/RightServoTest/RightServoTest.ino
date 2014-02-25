/*
Right servo turns CW three seconds, stops 1 second,
then CCW three seconds.
*/

#include <Servo.h>

Servo servoRight;

void setup() {
  // Attach right servo to pin 11
  servoRight.attach(11);
  
  // Set right servo to turn CW
  servoRight.writeMicroseconds(1300);
  
  // Turn for three seconds
  delay(3000);
  
  // Stop the servo
  servoRight.writeMicroseconds(1500);
  
  // Stay stopped for 1 second
  delay(1000);
  
  // Set right servo to turn CCW
  servoRight.writeMicroseconds(1700);
  
  // Turn for three seconds
  delay(3000);
  
  // Stop and detach the right servo
  servoRight.detach();
}

void loop() {
  // Nothing to repeat
}
