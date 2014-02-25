/*
Sketch that turns on/off an LED connected to pin 13
once every second.
*/

void setup() {
  // Set pin 13 to output mode
  pinMode(13, OUTPUT);
  
  // Set pin 12 to output mode
  pinMode(12, OUTPUT);
}

void loop() {
  // Turn the LED in pin 13 on
  digitalWrite(13, HIGH);
  // Turn the LED in pin 12 on
  digitalWrite(12, LOW);
  
  // Wait 0.5 seconds
  delay(500);
  
  // Turn the LED in pin 13 off
  digitalWrite(13, LOW);
  // Turn the LED in pin 12 off
  digitalWrite(12, HIGH);
  
  // Wait 0.5 seconds
  delay(500);
}
