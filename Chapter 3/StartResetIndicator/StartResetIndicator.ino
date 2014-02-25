/*
Test the piezospeaker circuit.
*/

void setup() {
  Serial.begin(9600);
  Serial.println("Beep!");
  
  // Play tone of 3 kHz for 1 second
    tone(4, 3000, 1000);
  
  // Wait one second for tone to finish
  delay(1000);
}

void loop() {
  Serial.println("Waiting for reset...");
  delay(1000);
}
