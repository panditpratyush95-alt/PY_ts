/*
 * Component 01 — LED Blinking
 * ANU Electronics — Arduino Starter Kit
 *
 * Hardware:
 *   LED Anode  → Pin 13 (or any digital pin) via 220Ω resistor
 *   LED Cathode → GND
 *
 * Note: Pin 13 has a built-in LED on most Arduino Uno boards,
 *       so you can test without any extra components.
 */

#define LED_PIN 13

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("LED Blink started.");
}

void loop() {
  digitalWrite(LED_PIN, HIGH);   // LED ON
  Serial.println("LED ON");
  delay(1000);

  digitalWrite(LED_PIN, LOW);    // LED OFF
  Serial.println("LED OFF");
  delay(1000);
}
