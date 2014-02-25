/*
Left servo turns CW three seconds, stops 1 second,
then CCW three seconds.
*/

#include <Servo.h>

Servo servoLeft;

void setup() {
  // Attach right servo to pin 11
  servoLeft.attach(12);
  
  // Set right servo to turn CW
  servoLeft.writeMicroseconds(1300);
  
  // Turn for three seconds
  delay(3000);
  
  // Stop the servo
  servoLeft.writeMicroseconds(1500);
  
  // Stay stopped for 1 second
  delay(1000);
  
  // Set right servo to turn CCW
  servoLeft.writeMicroseconds(1700);
  
  // Turn for three seconds
  delay(3000);
  
  // Stop and detach the right servo
  servoLeft.detach();
}

void loop() {
  // Nothing to repeat
}
