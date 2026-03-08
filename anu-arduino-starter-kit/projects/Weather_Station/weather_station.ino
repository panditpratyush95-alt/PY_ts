/*
 * Project — Weather Station (DHT11 + LCD)
 * ANU Electronics — Arduino Starter Kit
 *
 * Hardware:
 *   DHT11 VCC  → 5V
 *   DHT11 DATA → Pin 7
 *   DHT11 GND  → GND
 *   I2C LCD SDA→ A4
 *   I2C LCD SCL→ A5
 *
 * Library: DHT sensor library by Adafruit
 *          LiquidCrystal I2C by Frank de Brabander
 *
 * Displays temperature (°C & °F), humidity, heat index,
 * and a comfort level on the LCD. Prints full data to Serial Monitor.
 */

#include <DHT.h>
#include <LiquidCrystal_I2C.h>

#define DHT_PIN  7
#define DHT_TYPE DHT11

DHT dht(DHT_PIN, DHT_TYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Custom degree symbol
byte degChar[8] = { 0b01110,0b01010,0b01110,0b00000,0b00000,0b00000,0b00000,0b00000 };

int displayMode = 0;   // Cycle through display screens

void setup() {
  Serial.begin(9600);
  dht.begin();

  lcd.init();
  lcd.backlight();
  lcd.createChar(0, degChar);

  lcd.setCursor(0, 0); lcd.print("  Weather Station ");
  lcd.setCursor(0, 1); lcd.print("  ANU Electronics ");
  delay(2000);
  lcd.clear();

  Serial.println("Weather Station ready.");
  Serial.println("Temp(C)\tTemp(F)\tHumidity\tHeat Index\tComfort");
}

// ── Comfort level based on temp + humidity ────────────────────────────────────
String getComfort(float t, float h) {
  if (t < 10)                     return "Cold";
  if (t >= 10 && t < 18)          return "Cool";
  if (t >= 18 && t < 24 && h < 60) return "Comfortable";
  if (t >= 24 && t < 30)          return "Warm";
  if (t >= 30)                    return "Hot";
  return "Humid";
}

void loop() {
  delay(2500);

  float temp    = dht.readTemperature();
  float tempF   = dht.readTemperature(true);
  float hum     = dht.readHumidity();

  if (isnan(temp) || isnan(hum)) {
    Serial.println("Sensor read failed. Check wiring.");
    lcd.clear();
    lcd.setCursor(0, 0); lcd.print("Sensor Error!");
    return;
  }

  float heatIdx = dht.computeHeatIndex(temp, hum, false);
  String comfort = getComfort(temp, hum);

  // ── Serial output ─────────────────────────────────────────────────────────
  Serial.print(temp, 1); Serial.print("°C\t");
  Serial.print(tempF, 1); Serial.print("°F\t");
  Serial.print(hum, 1); Serial.print("%\t\t");
  Serial.print(heatIdx, 1); Serial.print("°C\t\t");
  Serial.println(comfort);

  // ── LCD display — alternate screens ──────────────────────────────────────
  lcd.clear();
  displayMode = (displayMode + 1) % 3;

  if (displayMode == 0) {
    // Screen 1: Temp
    lcd.setCursor(0, 0); lcd.print("Temp: ");
    lcd.print(temp, 1); lcd.write(byte(0)); lcd.print("C");
    lcd.setCursor(0, 1); lcd.print("     ");
    lcd.print(tempF, 1); lcd.write(byte(0)); lcd.print("F");
  } else if (displayMode == 1) {
    // Screen 2: Humidity + Heat Index
    lcd.setCursor(0, 0); lcd.print("Humidity: ");
    lcd.print(hum, 1); lcd.print("%");
    lcd.setCursor(0, 1); lcd.print("HeatIdx:");
    lcd.print(heatIdx, 1); lcd.write(byte(0)); lcd.print("C");
  } else {
    // Screen 3: Comfort
    lcd.setCursor(0, 0); lcd.print("Comfort Level:");
    lcd.setCursor(0, 1); lcd.print(comfort);
  }
}
