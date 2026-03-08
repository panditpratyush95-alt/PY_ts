/*
 * Component 17 — Stepper Motor (28BYJ-48 + ULN2003 Driver)
 * ANU Electronics — Arduino Starter Kit
 *
 * Hardware:
 *   ULN2003 IN1 → Pin 8
 *   ULN2003 IN2 → Pin 9
 *   ULN2003 IN3 → Pin 10
 *   ULN2003 IN4 → Pin 11
 *   ULN2003 VCC → 5V external supply (do NOT use Arduino 5V for motor)
 *   ULN2003 GND → GND (common with Arduino)
 *
 * Library: Built-in Stepper library
 *
 * 28BYJ-48 specs:
 *   Steps per revolution: 2048 (in half-step mode)
 *   Recommended speed: 10–15 RPM (higher = loses torque)
 */

#include <Stepper.h>

#define STEPS_PER_REV 2048

// Pin order: IN1, IN3, IN2, IN4 (this sequence is correct for 28BYJ-48)
Stepper motor(STEPS_PER_REV, 8, 10, 9, 11);

void setup() {
  motor.setSpeed(12);   // RPM
  Serial.begin(9600);
  Serial.println("28BYJ-48 Stepper Motor ready.");
}

void loop() {
  Serial.println("Rotating 1 full revolution CLOCKWISE...");
  motor.step(STEPS_PER_REV);
  delay(1000);

  Serial.println("Rotating 1 full revolution COUNTER-CLOCKWISE...");
  motor.step(-STEPS_PER_REV);
  delay(1000);

  Serial.println("Half revolution CW...");
  motor.step(STEPS_PER_REV / 2);
  delay(1000);

  Serial.println("Half revolution CCW...");
  motor.step(-(STEPS_PER_REV / 2));
  delay(1000);
}
