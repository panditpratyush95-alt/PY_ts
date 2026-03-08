/*
 * Component 08 — LDR (Light Dependent Resistor) Sensor
 * ANU Electronics — Arduino Starter Kit
 *
 * Hardware:
 *   LDR one leg → 5V
 *   LDR other leg → A0 AND one end of 10KΩ resistor
 *   10KΩ resistor other end → GND
 *   (Voltage divider: LDR on top, 10KΩ on bottom)
 *
 *   LED Anode → Pin 9 (PWM~) via 220Ω → GND
 *
 * Behaviour:
 *   Bright light → low ADC value → LED dims
 *   Dark         → high ADC value → LED brightens (auto night light)
 */

#define LDR_PIN  A0
#define LED_PIN   9   // PWM pin

// Threshold below which LED turns on (auto night light)
#define DARK_THRESHOLD 600

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("LDR Light Sensor started.");
  Serial.println("Cover sensor to see LED brighten.");
}

void loop() {
  int ldrValue   = analogRead(LDR_PIN);              // 0 (bright) – 1023 (dark)
  int brightness = map(ldrValue, 0, 1023, 0, 255);   // Map inversely for night light
  // For auto night-light, invert: brighter when darker
  int ledPWM     = map(ldrValue, 0, 1023, 255, 0);   // Dark → LED ON, Bright → LED OFF

  analogWrite(LED_PIN, ledPWM);

  String lightLevel;
  if      (ldrValue < 300)  lightLevel = "BRIGHT";
  else if (ldrValue < 600)  lightLevel = "DIM";
  else                       lightLevel = "DARK";

  Serial.print("LDR ADC: ");
  Serial.print(ldrValue);
  Serial.print("  | Level: ");
  Serial.print(lightLevel);
  Serial.print("  | LED PWM: ");
  Serial.println(ledPWM);

  delay(300);
}
