/*
 * Component 13 — Ultrasonic Distance Sensor (HC-SR04)
 * ANU Electronics — Arduino Starter Kit
 *
 * Hardware:
 *   HC-SR04 VCC  → 5V
 *   HC-SR04 GND  → GND
 *   HC-SR04 TRIG → Pin 9
 *   HC-SR04 ECHO → Pin 10
 *
 * Measurement range: 2–400 cm
 * Accuracy: ±3 mm
 */

#define TRIG_PIN  9
#define ECHO_PIN 10

// ── Measure distance in centimetres ──────────────────────────────────────────
long measureDistanceCm() {
  // Send 10µs pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure echo pulse duration (timeout 30ms = ~5m)
  long duration = pulseIn(ECHO_PIN, HIGH, 30000);

  if (duration == 0) return -1;   // No echo received

  // Speed of sound = 0.034 cm/µs → divide by 2 for one-way
  return duration * 0.034 / 2;
}

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(9600);
  Serial.println("HC-SR04 Ultrasonic Sensor ready.");
  Serial.println("Distance (cm)\tStatus");
}

void loop() {
  long dist = measureDistanceCm();

  if (dist < 0) {
    Serial.println("Out of range\t--");
  } else {
    Serial.print(dist);
    Serial.print(" cm\t\t");

    if      (dist < 10)  Serial.println("⚠️  Very close!");
    else if (dist < 30)  Serial.println("🟡  Near");
    else if (dist < 100) Serial.println("🟢  Medium");
    else                  Serial.println("🔵  Far");
  }

  delay(500);
}
