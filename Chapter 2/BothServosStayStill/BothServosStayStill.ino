/*
Generate signals to make both servos stay still.
*/

#include <Servo.h>

Servo servoLeft;
Servo servoRight;

void setup() {
  Serial.begin(9600);
  
  // Attach left siganl to pin 12
  servoLeft.attach(12);
  // Attach right siganl to pin 11
  servoRight.attach(11);
  // 90 degree stay still angle
  servoLeft.write(90);
  servoRight.write(90);
}


void loop() {
  Serial.print("Enter an angle: ");
  
  while(Serial.available() == 0);
  float angle = Serial.parseFloat();
  
  Serial.print("Setting angle to: ");
  Serial.println(angle);
  
  servoLeft.write(angle);
  servoRight.write(angle);
}
