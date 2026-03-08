/*
 * Project — Automatic Street Light (LDR + Relay)
 * ANU Electronics — Arduino Starter Kit
 *
 * Hardware:
 *   LDR          → A0 (voltage divider with 10KΩ to GND)
 *   Relay IN      → Pin 8
 *   Street light  → connected to relay NO terminal
 *   LED indicator → Pin 13 via 220Ω → GND
 *
 * Behaviour:
 *   Day  (bright) → LDR ADC low  → relay OFF → light OFF
 *   Night (dark)  → LDR ADC high → relay ON  → light ON
 *
 * Adjust DARK_THRESHOLD to calibrate for your environment.
 */

#include <LiquidCrystal_I2C.h>

#define LDR_PIN      A0
#define RELAY_PIN     8
#define LED_PIN      13

#define DARK_THRESHOLD 600   // ADC value above which it's considered "dark"
#define RELAY_ON      LOW    // Active LOW relay
#define RELAY_OFF     HIGH

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LED_PIN,   OUTPUT);
  digitalWrite(RELAY_PIN, RELAY_OFF);

  lcd.init();
  lcd.backlight();

  Serial.begin(9600);
  Serial.println("Auto Street Light ready.");
  Serial.println("LDR ADC\t\tLight Level\tStreet Light");

  lcd.setCursor(0, 0); lcd.print("Auto Street Light");
  lcd.setCursor(0, 1); lcd.print("Starting...");
  delay(1500);
}

void loop() {
  int ldr = analogRead(LDR_PIN);

  bool isDark = (ldr > DARK_THRESHOLD);

  digitalWrite(RELAY_PIN, isDark ? RELAY_ON : RELAY_OFF);
  digitalWrite(LED_PIN,   isDark ? HIGH      : LOW);

  String level = isDark ? "DARK (Night)" : "BRIGHT (Day)";
  String light = isDark ? "ON  🌟"        : "OFF 💤";

  Serial.print(ldr); Serial.print("\t\t");
  Serial.print(level); Serial.print("\t");
  Serial.println(light);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(isDark ? "Night Mode" : "Day Mode");
  lcd.setCursor(0, 1);
  lcd.print("Light: ");
  lcd.print(isDark ? "ON " : "OFF");

  delay(1000);
}
