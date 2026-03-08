/*
 * Component 10 — Vibration Sensor (SW-420)
 * ANU Electronics — Arduino Starter Kit
 *
 * Hardware:
 *   Vibration Sensor VCC → 5V
 *   Vibration Sensor GND → GND
 *   Vibration Sensor DO  → Pin 2
 *   LED                  → Pin 13 via 220Ω → GND
 *   Buzzer               → Pin 3 → GND
 *
 * The SW-420 outputs HIGH when vibration is detected.
 * Sensitivity is adjustable via the onboard potentiometer.
 */

#define VIB_PIN  2
#define LED_PIN 13
#define BUZ_PIN  3

unsigned long lastVibTime = 0;
const unsigned long ALERT_DURATION = 2000;  // Keep alert on for 2 sec after vibration

void setup() {
  pinMode(VIB_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZ_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Vibration Sensor ready.");
  Serial.println("Tap or shake to trigger.");
}

void loop() {
  int vib = digitalRead(VIB_PIN);

  if (vib == HIGH) {   // Vibration detected
    lastVibTime = millis();
    Serial.println("📳 Vibration detected!");
  }

  // Hold LED + buzzer on for ALERT_DURATION after last vibration
  if (millis() - lastVibTime < ALERT_DURATION) {
    digitalWrite(LED_PIN, HIGH);
    tone(BUZ_PIN, 1500);
  } else {
    digitalWrite(LED_PIN, LOW);
    noTone(BUZ_PIN);
  }

  delay(50);
}
