/*
Move the robot forward for one second
*/

#include <Servo.h>

Servo servoLeft, servoRight;

void stopServos();

void setup() {
  // Play startup tone for one second
  tone(4, 3000, 1000);
  delay(1000);
  
  // Set the pins for the servos
  servoLeft.attach(12);
  servoRight.attach(11);
  
  // Pivot forward-left one second
  servoLeft.writeMicroseconds(1500);      // Stopped
  servoRight.writeMicroseconds(1300);      // CW
  delay(1000);                            // 1s
  
  stopServos();
  
  delay(2000);
  
  // Pivot forward-right one second
  servoLeft.writeMicroseconds(1700);      // CCW
  servoRight.writeMicroseconds(1500);      // Stopped
  delay(1000);                              // 1s
  
  stopServos();
  
  delay(2000);
  
  // Pivot backward-left one second
  servoLeft.writeMicroseconds(1500);      // Stopped
  servoRight.writeMicroseconds(1700);      // CCW
  delay(1000);                              // 1s
  
  stopServos();
  
  delay(2000);
  
  // Pirvot backward-right one second
  servoLeft.writeMicroseconds(1300);      // CW
  servoRight.writeMicroseconds(1500);      // Stopped
  delay(1000);                            // 1s
  
  stopServos();
  delay(50);
  
  // Stop and detach both servos
  servoLeft.detach();
  servoRight.detach();
  
  // Play end tone for one second
  tone(4, 1000, 1000);
}

void loop() {
  // Nothing to repeat
}

void stopServos() {
  servoLeft.writeMicroseconds(1500);
  servoRight.writeMicroseconds(1500);
}
