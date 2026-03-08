/*
 * Component 04 — Trimpot / Potentiometer
 * ANU Electronics — Arduino Starter Kit
 *
 * Hardware:
 *   Trimpot left pin  → 5V
 *   Trimpot middle pin (wiper) → A0
 *   Trimpot right pin → GND
 *   LED Anode → Pin 9 (PWM~) via 220Ω → GND
 *
 * Turns the trimpot to control LED brightness via PWM.
 * Also prints the raw ADC value and mapped brightness to Serial Monitor.
 */

#define POT_PIN  A0
#define LED_PIN   9   // Must be a PWM pin (~)

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Trimpot → LED brightness control started.");
  Serial.println("Rotate the pot and watch the LED dim/brighten.");
}

void loop() {
  int raw        = analogRead(POT_PIN);           // 0–1023
  int brightness = map(raw, 0, 1023, 0, 255);    // Map to 0–255 for PWM

  analogWrite(LED_PIN, brightness);

  Serial.print("ADC: ");
  Serial.print(raw);
  Serial.print("  |  Brightness: ");
  Serial.print(brightness);
  Serial.print("/255  (");
  Serial.print(map(brightness, 0, 255, 0, 100));
  Serial.println("%)");

  delay(200);
}
