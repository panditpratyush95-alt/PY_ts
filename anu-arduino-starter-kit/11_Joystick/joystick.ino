/*
 * Component 11 — Joystick Module
 * ANU Electronics — Arduino Starter Kit
 *
 * Hardware:
 *   Joystick VCC  → 5V
 *   Joystick GND  → GND
 *   Joystick VRX  → A0  (X-axis analog)
 *   Joystick VRY  → A1  (Y-axis analog)
 *   Joystick SW   → Pin 2 (push button, active LOW)
 *
 * Centre position: ~512 for both axes.
 * Move up/down/left/right to deflect from centre.
 */

#define JOY_X   A0
#define JOY_Y   A1
#define JOY_SW   2   // Push button

void setup() {
  pinMode(JOY_SW, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("Joystick ready. Move stick or press button.");
  Serial.println("X\tY\tButton\tDirection");
}

// ── Interpret joystick direction ─────────────────────────────────────────────
String getDirection(int x, int y) {
  if (y < 300)      return "UP";
  if (y > 700)      return "DOWN";
  if (x < 300)      return "LEFT";
  if (x > 700)      return "RIGHT";
  return "CENTRE";
}

void loop() {
  int xVal = analogRead(JOY_X);
  int yVal = analogRead(JOY_Y);
  int btn  = digitalRead(JOY_SW);   // LOW = pressed

  String dir = getDirection(xVal, yVal);

  Serial.print(xVal);
  Serial.print("\t");
  Serial.print(yVal);
  Serial.print("\t");
  Serial.print(btn == LOW ? "PRESSED" : "open");
  Serial.print("\t");
  Serial.println(dir);

  delay(200);
}
