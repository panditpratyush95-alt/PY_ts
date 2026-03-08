/*
 * Component 12 — IR Sensor (Obstacle Detection)
 * ANU Electronics — Arduino Starter Kit
 *
 * Hardware:
 *   IR Sensor VCC → 5V
 *   IR Sensor GND → GND
 *   IR Sensor OUT → Pin 2 (active LOW when object detected)
 *   LED           → Pin 13 via 220Ω → GND
 *   Buzzer        → Pin 3 → GND
 *
 * Detection range adjustable via onboard potentiometer (2–30 cm typical).
 * OUT = LOW when obstacle detected, HIGH when clear.
 */

#define IR_PIN   2
#define LED_PIN 13
#define BUZ_PIN  3

int objectCount = 0;
bool prevState  = HIGH;

void setup() {
  pinMode(IR_PIN,  INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZ_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("IR Sensor ready.");
  Serial.println("Place object in front to detect.");
}

void loop() {
  int current = digitalRead(IR_PIN);

  if (current == LOW) {     // Object detected
    digitalWrite(LED_PIN, HIGH);
    tone(BUZ_PIN, 1000);

    // Count on new detection (LOW edge)
    if (prevState == HIGH) {
      objectCount++;
      Serial.print("🚨 Object detected! Count: ");
      Serial.println(objectCount);
    }
  } else {
    digitalWrite(LED_PIN, LOW);
    noTone(BUZ_PIN);
    if (prevState == LOW) {
      Serial.println("✅  Object removed.");
    }
  }

  prevState = current;
  delay(100);
}
