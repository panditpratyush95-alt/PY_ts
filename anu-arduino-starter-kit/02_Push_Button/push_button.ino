/*
 * Component 02 — Push Button
 * ANU Electronics — Arduino Starter Kit
 *
 * Hardware:
 *   Button one leg → Pin 2
 *   Button other leg → GND
 *   LED Anode → Pin 13 via 220Ω → GND
 *
 * Uses INPUT_PULLUP — no external resistor needed on the button.
 * Button pressed = LOW, released = HIGH.
 */

#define BTN_PIN  2
#define LED_PIN 13

void setup() {
  pinMode(BTN_PIN, INPUT_PULLUP);  // Internal pull-up resistor
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Push Button ready. Press button to toggle LED.");
}

void loop() {
  int state = digitalRead(BTN_PIN);

  if (state == LOW) {             // Button pressed (pulled to GND)
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Button PRESSED  → LED ON");
  } else {
    digitalWrite(LED_PIN, LOW);
    Serial.println("Button RELEASED → LED OFF");
  }
  delay(100);
}
