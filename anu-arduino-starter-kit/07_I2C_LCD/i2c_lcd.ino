/*
 * Component 07 — I2C LCD Display (16×2)
 * ANU Electronics — Arduino Starter Kit
 *
 * Hardware:
 *   LCD VCC → 5V
 *   LCD GND → GND
 *   LCD SDA → A4
 *   LCD SCL → A5
 *
 * Library: LiquidCrystal I2C by Frank de Brabander
 *   Install via: Sketch → Include Library → Manage Libraries → search "LiquidCrystal I2C"
 *
 * Default I2C address: 0x27
 *   If the display is blank, run the I2C Scanner sketch below to find the address.
 *   Then change LiquidCrystal_I2C lcd(0x27,...) to match.
 *
 * I2C Scanner: File → Examples → Wire → i2c_scanner
 */

#include <LiquidCrystal_I2C.h>

#define LCD_ADDR 0x27
#define LCD_COLS 16
#define LCD_ROWS  2

LiquidCrystal_I2C lcd(LCD_ADDR, LCD_COLS, LCD_ROWS);

// ── Custom character: smiley face ────────────────────────────────────────────
byte smiley[8] = {
  0b00000,
  0b01010,
  0b01010,
  0b00000,
  0b10001,
  0b01110,
  0b00000,
  0b00000
};

int counter = 0;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.createChar(0, smiley);

  Serial.begin(9600);

  // Startup splash
  lcd.setCursor(0, 0);
  lcd.print("  ANU Electronics ");
  lcd.setCursor(0, 1);
  lcd.print("  Arduino Kit  ");
  lcd.write(byte(0));   // Smiley
  delay(2500);
  lcd.clear();
  Serial.println("I2C LCD ready.");
}

void loop() {
  counter++;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Hello, Arduino!");
  lcd.setCursor(0, 1);
  lcd.print("Count: ");
  lcd.print(counter);

  Serial.print("LCD count: ");
  Serial.println(counter);
  delay(1000);
}
