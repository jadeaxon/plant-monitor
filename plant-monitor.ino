// Globals.
const int LED_PIN = 13; // Our blue LED connected to digital pin 13.

// Does any one-time init before the main loop runs.
void setup() {
  pinMode(LED_PIN, OUTPUT); // Set the digital pin to output mode.
}

// Monitors moisture sensor and updates LED forever until Arduino is powered off or catastrophically fails.
void loop() {
  // Test blinking the LED.
  digitalWrite(LED_PIN, HIGH);   
  delay(1000);                  
  digitalWrite(LED_PIN, LOW);    
  delay(1000);                  
}




