//========================================================================
// Globals
//========================================================================

// Globals.
const int LED_PIN = 13; // Our blue LED connected to digital pin 13.
int led_state = 0; // Current state of the LED: 0 => off; 1 => on.

// 1022: max reading I've seen so far (touching the nails together).
// 770: both nails submerged in soft water.
// 700: freshly watered plant.
// const int SENSOR_PIN = A0; // Moisture sensor (wire wrapped around a couple nails).
const int SENSOR_PIN = A1; // I broke off part of the wire I plugged into A0!

int moisture_level = 0; // The moisture level detected on the sensor pin.

char buffer[120] = ""; // Line buffer.


//========================================================================
// Main Loop
//========================================================================

// Does any one-time init before the main loop runs.
void setup() {
  pinMode(LED_PIN, OUTPUT); // Set the digital pin to output mode.
  pinMode(SENSOR_PIN, INPUT); // Not sure if this is necessary for analog pins.
  Serial.begin(9600); // Set serial port speed to 9600 baud.
}

// Monitors moisture sensor and updates LED forever until Arduino is powered off or catastrophically fails.
void loop() {
  moisture_level = analogRead(SENSOR_PIN);
  
  sprintf(buffer, "Moisture level: %d\n", moisture_level);
  Serial.print(buffer);
  Serial.println(led_state);

  displayMoistureLevel();
  
  delay(1000); // Wait 1 second.                           
} // loop()


//========================================================================
// LED Functions
//========================================================================

// Displays the moisture level on the LED.
void displayMoistureLevel() {
  // If plant is properly hydrated, do nothing.
  // If somewhat thirsty, blink LED.
  // If quite thirsty, leave LED solid.
  if (moisture_level >= 700) {
    turnOffLed();
  }
  else if (moisture_level >= 200) {
    toggleLed();
  }
  else {
    turnOnLed();
  }
}

// Turns the LED off.
void turnOffLed() {
  digitalWrite(LED_PIN, LOW); // Turn LED off.    
  led_state = 0;
}

// Turns the LED on.
void turnOnLed() {
  digitalWrite(LED_PIN, HIGH); // Turn LED on.
  led_state = 1;
}

// Toggles the LED between off and on.
void toggleLed() {
  if (led_state != 0) {
    turnOffLed();
  }
  else {
    turnOnLed();
  }
}


