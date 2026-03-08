/*
 * Component 16 — Servo Motor (SG90)
 * ANU Electronics — Arduino Starter Kit
 *
 * Hardware:
 *   Servo Red   (VCC)    → 5V
 *   Servo Brown (GND)    → GND
 *   Servo Orange (Signal)→ Pin 9 (PWM~)
 *
 * Library: Built-in Servo library (no install needed)
 *
 * Sweep sketch: moves 0° → 180° → 0° continuously.
 * Optional: connect trimpot to A0 for manual angle control.
 */

#include <Servo.h>

#define SERVO_PIN  9
#define POT_PIN   A0

Servo myServo;

void setup() {
  myServo.attach(SERVO_PIN);
  Serial.begin(9600);
  Serial.println("Servo Motor ready.");
  Serial.println("Mode: Sweep 0-180°");
  Serial.println("Uncomment pot section for manual control.");
}

void loop() {
  // ── Auto Sweep ──────────────────────────────────────────────────────────────
  for (int angle = 0; angle <= 180; angle += 5) {
    myServo.write(angle);
    Serial.print("Angle: "); Serial.println(angle);
    delay(50);
  }
  for (int angle = 180; angle >= 0; angle -= 5) {
    myServo.write(angle);
    Serial.print("Angle: "); Serial.println(angle);
    delay(50);
  }

  // ── Manual Trimpot Control (uncomment to use) ──────────────────────────────
  // int pot   = analogRead(POT_PIN);
  // int angle = map(pot, 0, 1023, 0, 180);
  // myServo.write(angle);
  // Serial.print("Pot: "); Serial.print(pot);
  // Serial.print("  Angle: "); Serial.println(angle);
  // delay(20);
}
