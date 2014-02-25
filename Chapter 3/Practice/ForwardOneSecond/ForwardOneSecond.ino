/*
Move forward 9 seconds, turn left 90 degrees, turn right 90 degrees,
then backward 9 seconds with ramping and blinking eyes afterward.
*/

#include <Servo.h>
#include <Eyes.h>

const unsigned int SERVO_STILL_MS = 1500;
const int SERVO_MAX_MS_OFFSET = 150;
const int FORWARD_MS_ADJUSTMENT = 0;
const int REVERSE_MS_ADJUSTMENT = 0;

const float SPEED_IN = 6;
const float SPEED_CM = 15.24;

static unsigned long rampUpTime = 0, rampDownTime = 0;
const unsigned int LEFT_EYE_PIN = 13;
const unsigned int RIGHT_EYE_PIN = 10;
const unsigned int LED_INTERVAL = 1000;
unsigned long prevMillis = 0;
unsigned int ledState = HIGH;

Servo servoLeft, servoRight;
Eyes eyes(LEFT_EYE_PIN, RIGHT_EYE_PIN);

unsigned long rampUpForward();
unsigned long rampDownForward();
unsigned long rampUpReverse();
unsigned long rampDownReverse();
unsigned long rampUpLeft();
unsigned long rampDownLeft();
unsigned long rampUpRight();
unsigned long rampDownRight();
void turnLeft(int milliseconds, int maxMsOffset);
void turnRight(int milliseconds, int maxMsOffset);
void turnLeft90();
void turnRight90();
void forward(int milliseconds);
void reverse(int milliseconds);
void stopServos();

int getDelayTime(float travelDistance);

void setup() {
  Serial.begin(9600);
  
  // Play startup tone for one second
  tone(4, 3000, 1000);
  delay(1000);
  
  // Set the pins for the servos
  servoLeft.attach(12);
  servoRight.attach(11);
  
  stopServos();
    
  // Move forward 9 seconds
  forward(9000);
  
  delay(2000);
  
  // Turn right 90 degrees
  turnRight90();
  eyes.wink(EYE_RIGHT, 1000);
  
  delay(2000);
  
  // Turn left 90 degrees
  turnLeft90();
  eyes.wink(EYE_LEFT, 1000);
  
  delay(2000);
  
  // Move backward 9 seconds
  reverse(9000);
    
  // Stop and detach both servos
  servoLeft.detach();
  servoRight.detach();
}

void loop() {
  // Blink the led eyes
  eyes.blink(3000, 500);
}

unsigned long rampUpForward() {
  unsigned long startMillis = millis();
  
  Serial.println("Ramp up beginning.");
  
  // Ramp up to full speed forward
  for(int msOffset = 0; msOffset <= SERVO_MAX_MS_OFFSET; msOffset += 2) {
    servoLeft.writeMicroseconds(1500 + msOffset);
    servoRight.writeMicroseconds(1500 - msOffset);
    Serial.println(msOffset);
    delay(20);
  }
  
  // Software adjustment for straightening
  servoRight.writeMicroseconds(SERVO_STILL_MS - SERVO_MAX_MS_OFFSET - FORWARD_MS_ADJUSTMENT);
  
  // Return the time it took to ramp up
  return millis() - startMillis;
}

unsigned long rampDownForward() {
  unsigned long startMillis = millis();
  
  Serial.println("Ramp down beginning.");
  
  // Ramp downfrom full speed forward
  for(int msOffset = SERVO_MAX_MS_OFFSET; msOffset >= 0; msOffset -= 2) {
    servoLeft.writeMicroseconds(1500 + msOffset);
    servoRight.writeMicroseconds(1500 - msOffset);
    Serial.println(msOffset);
    delay(20);
  }

  // Return the time it took to ramp down
  return millis() - startMillis;
}

void forward(int milliseconds) {
  Serial.print("Beginning movement forward.");  
  
  tone(4, 2000, 500);
  
  long fullSpeedMilliseconds = milliseconds - 2 * rampUpForward();
  
  if(fullSpeedMilliseconds > 0) {
    delay(fullSpeedMilliseconds);
  }
  
  tone(4, 2000, 500);
  rampDownForward();
}

unsigned long rampUpReverse() {
  unsigned long startMillis = millis();
  
  Serial.println("Ramp up beginning.");
  
  // Ramp up to full speed reverse
  for(int msOffset = 0; msOffset >= -SERVO_MAX_MS_OFFSET; msOffset -= 2) {
    servoLeft.writeMicroseconds(1500 + msOffset);
    servoRight.writeMicroseconds(1500 - msOffset);
    Serial.println(msOffset);
    delay(20);
  }
  
  // Software adjustment for straightening
  servoLeft.writeMicroseconds(SERVO_STILL_MS - SERVO_MAX_MS_OFFSET - REVERSE_MS_ADJUSTMENT);
  
  // Return the time it took to ramp up
  return millis() - startMillis;
}

unsigned long rampDownReverse() {
  unsigned long startMillis = millis();
  
  Serial.println("Ramp down beginning.");
  
  // Ramp down from full speed reverse
  for(int msOffset = -SERVO_MAX_MS_OFFSET; msOffset <= 0; msOffset += 2) {
    servoLeft.writeMicroseconds(1500 + msOffset);
    servoRight.writeMicroseconds(1500 - msOffset);
    Serial.println(msOffset);
    delay(20);
  }

  // Return the time it took to ramp down
  return millis() - startMillis;
}

void reverse(int milliseconds) {
  Serial.print("Beginning movement in reverse.");  
  
  tone(4, 2000, 500);
  
  long fullSpeedMilliseconds = milliseconds - 2 * rampUpReverse();
  
  if(fullSpeedMilliseconds > 0) {
    delay(fullSpeedMilliseconds);
  }
  
  tone(4, 2000, 500);
  rampDownReverse();
}

unsigned long rampUpLeft(int maxMsOffset) {
  unsigned long startMillis = millis();
  
  Serial.println("Ramp up beginning.");
  
  // Ramp up to full speed left
  for(int msOffset = 0; msOffset <= maxMsOffset; msOffset += 2) {
    servoLeft.writeMicroseconds(1500 - msOffset);
    servoRight.writeMicroseconds(1500 - msOffset);
    Serial.println(msOffset);
    delay(20);
  }
  
  // Return the time it took to ramp up
  return millis() - startMillis;  
}

unsigned long rampDownLeft(int maxMsOffset) {
  unsigned long startMillis = millis();
  
  Serial.println("Ramp down beginning.");
  
  // Ramp down from full speed left
  for(int msOffset = maxMsOffset; msOffset >= 0; msOffset -= 2) {
    servoLeft.writeMicroseconds(1500 - msOffset);
    servoRight.writeMicroseconds(1500 - msOffset);
    Serial.println(msOffset);
    delay(20);
  }
  
  // Return the time it took to ramp up
  return millis() - startMillis;   
}

unsigned long rampUpRight(int maxMsOffset) {
  unsigned long startMillis = millis();
  
  Serial.println("Ramp up beginning.");
  
  // Ramp up to full speed left
  for(int msOffset = 0; msOffset <= maxMsOffset; msOffset += 2) {
    servoLeft.writeMicroseconds(1500 + msOffset);
    servoRight.writeMicroseconds(1500 + msOffset);
    Serial.println(msOffset);
    delay(20);
  }
    
  // Return the time it took to ramp up
  return millis() - startMillis;    
}

unsigned long rampDownRight(int maxMsOffset) {
  unsigned long startMillis = millis();
  
  Serial.println("Ramp down beginning.");
  
  // Ramp down from full speed left
  for(int msOffset = maxMsOffset; msOffset >= 0; msOffset -= 2) {
    servoLeft.writeMicroseconds(1500 + msOffset);
    servoRight.writeMicroseconds(1500 + msOffset);
    Serial.println(msOffset);
    delay(20);
  }
    
  // Return the time it took to ramp up
  return millis() - startMillis;     
}

void turnLeft(int milliseconds, int maxMsOffset) {
  Serial.print("Beginning left turn.");  
  
  tone(4, 2000, 500);
  
  long fullSpeedMilliseconds = milliseconds - 2 * rampUpLeft(maxMsOffset);
  
  if(fullSpeedMilliseconds > 0) {
    delay(fullSpeedMilliseconds);
  }
  
  tone(4, 2000, 500);
  rampDownLeft(maxMsOffset);
}

void turnRight(int milliseconds, int maxMsOffset) {
  Serial.print("Beginning right turn.");  
  
  tone(4, 2000, 500);
  
  long fullSpeedMilliseconds = milliseconds - 2 * rampUpRight(maxMsOffset);
  
  if(fullSpeedMilliseconds > 0) {
    delay(fullSpeedMilliseconds);
  }
  
  tone(4, 2000, 500);
  rampDownRight(maxMsOffset);
  
}

void turnLeft90() {
  turnLeft(0, 72);
}

void turnRight90() {
  turnRight(0, 66);
}

void stopServos() {
  servoLeft.writeMicroseconds(1500);
  servoRight.writeMicroseconds(1500);
}

int getDelayTime(float travelDistanceInches) {
  return floor( floor(travelDistanceInches / SPEED_IN * 100) * 10);
}
