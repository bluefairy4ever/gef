/*
Send 1/100th speed servo signals for viewing with an LED.
*/

void setup() {
  // Set digital pin 13 for OUTPUT mode
  pinMode(13, OUTPUT);
}

void loop() {
  // Pin 13 = 5V; LED lit
  digitalWrite(13, HIGH);
  // Delay 0.17 seconds
  delay(2);
  // Pin 13 = 0V; LED unlit
  digitalWrite(13, LOW);
  // Delay 1.83 seconds
  delay(18);
}
