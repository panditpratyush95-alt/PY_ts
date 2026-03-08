/*
 * Project — Security System (PIR + Buzzer + LCD)
 * ANU Electronics — Arduino Starter Kit
 *
 * Hardware:
 *   PIR HC-SR501 VCC → 5V
 *   PIR HC-SR501 GND → GND
 *   PIR HC-SR501 OUT → Pin 2
 *   Buzzer           → Pin 3 → GND
 *   Red LED          → Pin 13 via 220Ω → GND
 *   Green LED        → Pin 12 via 220Ω → GND
 *   I2C LCD SDA      → A4
 *   I2C LCD SCL      → A5
 *   Arm/Disarm button→ Pin 4 (INPUT_PULLUP)
 *
 * NOTE: Wait 30–60 seconds after power-on for PIR calibration.
 */

#include <LiquidCrystal_I2C.h>

#define PIR_PIN    2
#define BUZ_PIN    3
#define BTN_PIN    4
#define RED_LED   13
#define GREEN_LED 12

LiquidCrystal_I2C lcd(0x27, 16, 2);

bool  armed         = false;
bool  alarmTriggered = false;
bool  prevBtn       = HIGH;

void updateLCD(String line1, String line2) {
  lcd.clear();
  lcd.setCursor(0, 0); lcd.print(line1);
  lcd.setCursor(0, 1); lcd.print(line2);
}

void setup() {
  pinMode(PIR_PIN,   INPUT);
  pinMode(BUZ_PIN,   OUTPUT);
  pinMode(BTN_PIN,   INPUT_PULLUP);
  pinMode(RED_LED,   OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  lcd.init();
  lcd.backlight();
  Serial.begin(9600);

  updateLCD("Security System", "Press btn to ARM");
  Serial.println("Security System ready. Press button to arm.");
  Serial.println("Waiting for PIR calibration...");
  delay(30000);
  Serial.println("PIR ready. Press button to arm.");
}

void loop() {
  bool btn = digitalRead(BTN_PIN);

  // Toggle arm/disarm on button press
  if (btn == LOW && prevBtn == HIGH) {
    armed = !armed;
    alarmTriggered = false;
    noTone(BUZ_PIN);
    if (armed) {
      Serial.println("🔒 System ARMED");
      updateLCD("🔒 ARMED", "Monitoring...");
    } else {
      Serial.println("🔓 System DISARMED");
      updateLCD("🔓 DISARMED", "Press btn to ARM");
    }
    delay(300);
  }
  prevBtn = btn;

  if (armed) {
    digitalWrite(GREEN_LED, LOW);

    if (digitalRead(PIR_PIN) == HIGH) {
      alarmTriggered = true;
    }

    if (alarmTriggered) {
      // Flashing red + alarm tone
      digitalWrite(RED_LED, (millis() / 300) % 2);
      tone(BUZ_PIN, 2500);
      updateLCD("⚠️  INTRUDER!", "Press btn to stop");
      Serial.println("🚨 INTRUDER DETECTED!");
    } else {
      digitalWrite(RED_LED, LOW);
      noTone(BUZ_PIN);
    }
  } else {
    // Disarmed: green LED steady, no buzzer
    digitalWrite(RED_LED,   LOW);
    digitalWrite(GREEN_LED, HIGH);
    noTone(BUZ_PIN);
  }

  delay(100);
}
