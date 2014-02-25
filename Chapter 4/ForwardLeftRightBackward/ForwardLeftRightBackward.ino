/*
Movement with ramping.
*/

#include <Servo.h>

Servo servoLeft, servoRight;

void stopServos();
void rampUpForward();
void rampDownForward();
void rampUpBackward();
void rampDownBackward();
void moveForward(int microSeconds);
void moveBackward(int microSeconds);

void setup() {
  // Play startup tone for one second
  tone(4, 3000, 1000);
  delay(1000);
  
  // Set the pins for the servos
  servoLeft.attach(12);
  servoRight.attach(11);
  
  // Full speed forward for two seconds
  moveForward(2000);
  
  // Turn left in place for .6 seconds
  servoLeft.writeMicroseconds(1400);      // CW
  servoRight.writeMicroseconds(1400);      // CW
  delay(560);                              // .6s
  
  stopServos();
  delay(2000);
  
  // Turn right in place for .6 seconds
  servoLeft.writeMicroseconds(1600);      // CCW
  servoRight.writeMicroseconds(1600);      // CCW
  delay(560);                              // .6s
  
  stopServos();
  delay(2000);
  
  // Full speed backward for two seconds
  moveBackward(2000);
  
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

void rampUpForward() {
  int speedLeft, speedRight;
  
  // Set initial values to full stop offset
  speedLeft = speedRight = 0;
    
  while(speedLeft <= 200) {
    
    // Ramps servoLeft to 1700
    servoLeft.writeMicroseconds(1500+speedLeft);
    speedLeft += 2;
    
    // Ramps servoRight to 1370
    // 1370 is a software adjustment for moving forward
    if(speedRight <= 130) {
      servoRight.writeMicroseconds(1500-speedRight);
      speedRight += 2;
    }
    delay(20);
  }
}

void rampDownForward() {
  int speedLeft, speedRight;
  
  // Set initial values to full speed forward offset
  speedLeft = 200;
  speedRight = 130;
  
  // Ramp down to full stop
  while(speedLeft >= 0) {
    
    // Ramp servoLeft to 1500
    servoLeft.writeMicroseconds(1500+speedLeft);
    speedLeft -= 2;    
    
    // Ramp servoRight to 1500
    // If statement compensates for software adjustment
    if(speedRight != 0) {
      servoRight.writeMicroseconds(1500-speedRight);
      speedRight -= 2;
    }
    
    delay(20);
  }
}

void moveForward(int microSeconds) {
  rampUpForward();
  delay(microSeconds);
  rampDownForward();
}

void rampUpBackward() {
  int speedLeft, speedRight;
  
  // Set initial values to full stop offset
  speedLeft = speedRight = 0;
    
  while(speedRight >= -200) {
        
    // Ramps servoLeft to 1390
    // 1390 is a software adjustment for moving forward
    if(speedLeft >= -110) {
      servoLeft.writeMicroseconds(1500+speedLeft);
      speedLeft -= 2;
    }
    
    // Ramps servoRight to 1700
    servoRight.writeMicroseconds(1500-speedRight);
    speedRight -= 2;
    
    delay(20);
  }  
}

void rampDownBackward() {
  int speedLeft, speedRight;
  
  // Set initial values to full speed forward offset
  speedLeft = -110;
  speedRight = -200;
  
  // Ramp down to full stop
  while(speedRight <= 0) {
    
    // Ramp servoLeft to 1500
    // If statement compensates for software adjustment
    if(speedLeft != 0) {
      servoLeft.writeMicroseconds(1500+speedLeft);
      speedLeft += 2;
    }
    
    // Ramp servoRight to 1500
    servoRight.writeMicroseconds(1500-speedRight);
    speedRight += 2;    
    
    
    delay(20);
  }
}

void moveBackward(int microSeconds) {
  rampUpBackward();
  delay(microSeconds);
  rampDownBackward();
}
