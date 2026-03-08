/*
 * Project — Touchless Doorbell (IR Sensor + Buzzer + LCD)
 * ANU Electronics — Arduino Starter Kit
 *
 * Hardware:
 *   IR Sensor VCC → 5V
 *   IR Sensor GND → GND
 *   IR Sensor OUT → Pin 2 (active LOW when hand detected)
 *   Active Buzzer → Pin 3 → GND
 *   LED           → Pin 13 via 220Ω → GND
 *   I2C LCD SDA   → A4
 *   I2C LCD SCL   → A5
 *
 * How it works:
 *   Wave your hand in front of the IR sensor to ring the doorbell.
 *   A short melody plays and the visitor count increments.
 *   The LCD shows the last ring time (seconds since power-on).
 */

#include <LiquidCrystal_I2C.h>

#define IR_PIN   2
#define BUZ_PIN  3
#define LED_PIN 13

// Note frequencies
#define C5 523
#define E5 659
#define G5 784
#define C6 1047

LiquidCrystal_I2C lcd(0x27, 16, 2);

int  visitorCount = 0;
bool prevState    = HIGH;

// ── Doorbell melody ──────────────────────────────────────────────────────────
void playDoorbell() {
  int notes[]    = { E5, G5, E5, C6 };
  int durations[] = { 150, 150, 150, 300 };
  for (int i = 0; i < 4; i++) {
    tone(BUZ_PIN, notes[i], durations[i]);
    delay(durations[i] + 30);
  }
  noTone(BUZ_PIN);
}

void updateLCD() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Visitors: ");
  lcd.print(visitorCount);
  lcd.setCursor(0, 1);
  lcd.print("Last: ");
  lcd.print(millis() / 1000);
  lcd.print("s ago");
}

void setup() {
  pinMode(IR_PIN,  INPUT);
  pinMode(BUZ_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  lcd.init();
  lcd.backlight();
  Serial.begin(9600);

  lcd.setCursor(0, 0); lcd.print("Touchless Bell");
  lcd.setCursor(0, 1); lcd.print("Wave to ring!");
  Serial.println("Touchless Doorbell ready. Wave hand to ring.");
}

void loop() {
  bool current = digitalRead(IR_PIN);

  // Trigger on falling edge (hand detected → LOW)
  if (current == LOW && prevState == HIGH) {
    visitorCount++;

    Serial.print("🔔 DING DONG! Visitor #");
    Serial.println(visitorCount);

    // Flash LED + play melody
    digitalWrite(LED_PIN, HIGH);
    lcd.clear();
    lcd.setCursor(0, 0); lcd.print("  DING DONG!  ");
    lcd.setCursor(0, 1); lcd.print("Visitor #"); lcd.print(visitorCount);

    playDoorbell();

    digitalWrite(LED_PIN, LOW);
    delay(1000);
    updateLCD();
  }

  prevState = current;
  delay(80);
}
