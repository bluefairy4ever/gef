void setup() {
  Serial.begin(9600);
  
  // Initialize the LED pin for output
//  pinMode(13, OUTPUT);
  
  // Turn off the LED pin
  // digitalWrite(13, LOW);
}

void loop() {
  // Add code that repeats automatically here.
  Serial.println("Hello!");
  delay(1000);
}
