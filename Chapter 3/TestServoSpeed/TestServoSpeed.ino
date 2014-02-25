/*
Send a character from the Serial Monitor to the Arduino to make
it run the left servo for 6 seconds. Starts with 1375 pulses and
increases by 25 us with each repetition, up to 1625 us. This
sketch is useful for graphing speed vs. pulse width.
*/

#include <Servo.h>

Servo servoLeft, servoRight;

void setup() {
  // Play the startup tone for one second
  tone(4, 3000, 1000);
  delay(1000);
  
  // Set data rate to 9600 bps
  Serial.begin(9600);
  
  // Attach left servo to pin 12
  servoLeft.attach(12);
}

void loop() {
  // Loop counts with pulseWidth from 1300 to 1700 in increments
  // of 10.
  
  for(int pulseWidth=1300; pulseWidth<=1700; pulseWidth+=10) {
    // Display pulseWidth
    Serial.print("pulseWidth = ");
    Serial.println(pulseWidth);
    
    // Prompt user for continue
    Serial.println("Press a key and click");
    Serial.println("Send to start servo...");
    
    // Wait for continue
    while(Serial.available() == 0);
    Serial.read();
    
    Serial.println("Runing...");
    
    // Set pin 12 servo speed to pulseWidth
    servoLeft.writeMicroseconds(pulseWidth);
    // Run for 6 seconds
    delay(6000);
    
    // Stop pin 12 servo
    servoLeft.writeMicroseconds(1500);
  }
}
