/*
 * Component 14 — DHT11 Temperature & Humidity Sensor
 * ANU Electronics — Arduino Starter Kit
 *
 * Hardware:
 *   DHT11 VCC  → 5V
 *   DHT11 DATA → Pin 7 (with 10KΩ pull-up to 5V recommended)
 *   DHT11 GND  → GND
 *
 * Library: DHT sensor library by Adafruit
 *   Install via: Sketch → Include Library → Manage Libraries → search "DHT sensor"
 *
 * Measurement range:
 *   Temperature: 0–50°C (±2°C)
 *   Humidity:    20–90% RH (±5%)
 */

#include <DHT.h>

#define DHT_PIN  7
#define DHT_TYPE DHT11

DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  Serial.println("DHT11 Sensor ready.");
  Serial.println("Temp (°C)\tTemp (°F)\tHumidity (%)\tHeat Index");
}

void loop() {
  // DHT11 takes up to 2 seconds between readings
  delay(2000);

  float temp  = dht.readTemperature();       // Celsius
  float tempF = dht.readTemperature(true);   // Fahrenheit
  float hum   = dht.readHumidity();

  // Check for failed readings
  if (isnan(temp) || isnan(hum)) {
    Serial.println("Failed to read from DHT11! Check wiring.");
    return;
  }

  // Compute heat index
  float heatIndex = dht.computeHeatIndex(temp, hum, false);

  Serial.print(temp,  1); Serial.print("°C\t\t");
  Serial.print(tempF, 1); Serial.print("°F\t\t");
  Serial.print(hum,   1); Serial.print("%\t\t");
  Serial.print(heatIndex, 1); Serial.println("°C");
}
