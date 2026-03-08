/*
 * Component 05 — RGB LED (Common Cathode)
 * ANU Electronics — Arduino Starter Kit
 *
 * Hardware (Common Cathode RGB LED):
 *   R pin  → Pin 9  (PWM~) via 220Ω
 *   G pin  → Pin 10 (PWM~) via 220Ω
 *   B pin  → Pin 11 (PWM~) via 220Ω
 *   GND pin → GND
 *
 * For Common Anode: connect longest pin to 5V,
 * and invert values: use (255 - value) in analogWrite.
 *
 * This sketch cycles through a rainbow of colours.
 */

#define RED_PIN    9
#define GREEN_PIN 10
#define BLUE_PIN  11

// ── Set RGB colour (0–255 each channel) ─────────────────────────────────────
void setColor(int r, int g, int b) {
  analogWrite(RED_PIN,   r);
  analogWrite(GREEN_PIN, g);
  analogWrite(BLUE_PIN,  b);
}

void setup() {
  pinMode(RED_PIN,   OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN,  OUTPUT);
  Serial.begin(9600);
  Serial.println("RGB LED colour cycle started.");
}

void loop() {
  Serial.println("Red");        setColor(255,   0,   0); delay(800);
  Serial.println("Green");      setColor(  0, 255,   0); delay(800);
  Serial.println("Blue");       setColor(  0,   0, 255); delay(800);
  Serial.println("Yellow");     setColor(255, 255,   0); delay(800);
  Serial.println("Cyan");       setColor(  0, 255, 255); delay(800);
  Serial.println("Magenta");    setColor(255,   0, 255); delay(800);
  Serial.println("White");      setColor(255, 255, 255); delay(800);
  Serial.println("Orange");     setColor(255, 128,   0); delay(800);
  Serial.println("Warm White"); setColor(255, 180, 100); delay(800);
  Serial.println("Off");        setColor(  0,   0,   0); delay(500);
}
