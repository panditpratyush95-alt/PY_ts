/*
 * Component 09 — Flame Sensor
 * ANU Electronics — Arduino Starter Kit
 *
 * Hardware:
 *   Flame Sensor VCC → 5V
 *   Flame Sensor GND → GND
 *   Flame Sensor DO  → Pin 2  (Digital Output)
 *   Flame Sensor AO  → A0     (Analog Output — optional, for sensitivity reading)
 *   Alert LED        → Pin 13 via 220Ω → GND
 *   Buzzer           → Pin 3  → GND
 *
 * Digital output: LOW = flame detected, HIGH = no flame (active LOW).
 * Analog output: lower value = stronger flame signal.
 *
 * WARNING: For demonstration only. Do NOT use as a sole safety device.
 */

#define FLAME_DO  2    // Digital output
#define FLAME_AO  A0   // Analog output
#define LED_PIN  13
#define BUZ_PIN   3

void setup() {
  pinMode(FLAME_DO, INPUT);
  pinMode(LED_PIN,  OUTPUT);
  pinMode(BUZ_PIN,  OUTPUT);
  Serial.begin(9600);
  Serial.println("Flame Sensor ready.");
  Serial.println("⚠️  WARNING: Demo use only. Not for safety-critical applications.");
}

void loop() {
  int digital  = digitalRead(FLAME_DO);
  int analog   = analogRead(FLAME_AO);

  if (digital == LOW) {   // Flame detected (active LOW)
    digitalWrite(LED_PIN, HIGH);
    tone(BUZ_PIN, 2000);
    Serial.print("🔥 FLAME DETECTED!  Analog: ");
    Serial.println(analog);
  } else {
    digitalWrite(LED_PIN, LOW);
    noTone(BUZ_PIN);
    Serial.print("✅  No flame.  Analog: ");
    Serial.println(analog);
  }

  delay(300);
}
