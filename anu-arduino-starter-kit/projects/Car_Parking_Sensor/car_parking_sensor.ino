/*
 * Project — Car Parking Sensor (HC-SR04 + Buzzer + RGB LED)
 * ANU Electronics — Arduino Starter Kit
 *
 * Hardware:
 *   HC-SR04 TRIG  → Pin 9
 *   HC-SR04 ECHO  → Pin 10
 *   HC-SR04 VCC   → 5V
 *   HC-SR04 GND   → GND
 *   Green LED     → Pin 4 via 220Ω → GND
 *   Yellow LED    → Pin 5 via 220Ω → GND
 *   Red LED       → Pin 6 via 220Ω → GND
 *   Active Buzzer → Pin 3 → GND
 *
 * Distance zones:
 *   > 60 cm  → Green  (Safe — plenty of space)
 *   30–60 cm → Yellow (Caution — getting close)
 *   10–30 cm → Red    (Warning — very close)
 *   < 10 cm  → Red + fast beep (Stop!)
 */

#include <LiquidCrystal_I2C.h>

#define TRIG_PIN    9
#define ECHO_PIN   10
#define BUZ_PIN     3
#define GREEN_LED   4
#define YELLOW_LED  5
#define RED_LED     6

LiquidCrystal_I2C lcd(0x27, 16, 2);

// ── Measure distance ─────────────────────────────────────────────────────────
long getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long dur = pulseIn(ECHO_PIN, HIGH, 30000);
  return (dur == 0) ? 999 : dur * 0.034 / 2;
}

void setLEDs(bool g, bool y, bool r) {
  digitalWrite(GREEN_LED,  g ? HIGH : LOW);
  digitalWrite(YELLOW_LED, y ? HIGH : LOW);
  digitalWrite(RED_LED,    r ? HIGH : LOW);
}

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZ_PIN,  OUTPUT);
  pinMode(GREEN_LED,  OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED,    OUTPUT);

  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  Serial.println("Car Parking Sensor ready.");
}

void loop() {
  long dist = getDistance();

  // ── Serial output ─────────────────────────────────────────────────────────
  Serial.print("Distance: ");
  Serial.print(dist);
  Serial.print(" cm → ");

  // ── Zone logic ────────────────────────────────────────────────────────────
  lcd.clear();
  lcd.setCursor(0, 0); lcd.print("Distance: ");
  lcd.print(dist); lcd.print(" cm");

  if (dist > 60) {
    setLEDs(true, false, false);
    noTone(BUZ_PIN);
    Serial.println("✅  SAFE");
    lcd.setCursor(0, 1); lcd.print("✅  SAFE");

  } else if (dist > 30) {
    setLEDs(false, true, false);
    tone(BUZ_PIN, 800);
    delay(200); noTone(BUZ_PIN);
    Serial.println("🟡  CAUTION");
    lcd.setCursor(0, 1); lcd.print("CAUTION - Slow");

  } else if (dist > 10) {
    setLEDs(false, false, true);
    tone(BUZ_PIN, 1500);
    delay(100); noTone(BUZ_PIN);
    Serial.println("🔴  WARNING — Very Close!");
    lcd.setCursor(0, 1); lcd.print("WARNING! Close");

  } else {
    setLEDs(false, false, true);
    tone(BUZ_PIN, 2500);   // Continuous alarm
    Serial.println("🚨  STOP! Obstruction!");
    lcd.setCursor(0, 1); lcd.print("STOP!! STOP!!");
  }

  delay(300);
}
