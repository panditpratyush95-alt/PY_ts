/*
 * Component 06 — 7-Segment Display (Common Cathode, Single Digit)
 * ANU Electronics — Arduino Starter Kit
 *
 * Hardware (Common Cathode):
 *   Connect each segment (a–g, dp) via 220Ω resistor to Arduino pins.
 *   Connect COM (GND) pin to GND.
 *
 *   Segment → Arduino Pin:
 *     a → Pin 2    b → Pin 3    c → Pin 4    d → Pin 5
 *     e → Pin 6    f → Pin 7    g → Pin 8    dp → Pin 9 (optional)
 *
 *   7-Segment layout:
 *        aaa
 *       f   b
 *       f   b
 *        ggg
 *       e   c
 *       e   c
 *        ddd
 *
 * Counts 0–9 in a loop.
 */

// Pin assignments: a, b, c, d, e, f, g
const int SEG_PINS[7] = { 2, 3, 4, 5, 6, 7, 8 };

// Digit patterns: each row = segments a,b,c,d,e,f,g (1=ON, 0=OFF)
// Common Cathode: HIGH = segment ON
const byte DIGITS[10][7] = {
  //a  b  c  d  e  f  g
  { 1, 1, 1, 1, 1, 1, 0 },  // 0
  { 0, 1, 1, 0, 0, 0, 0 },  // 1
  { 1, 1, 0, 1, 1, 0, 1 },  // 2
  { 1, 1, 1, 1, 0, 0, 1 },  // 3
  { 0, 1, 1, 0, 0, 1, 1 },  // 4
  { 1, 0, 1, 1, 0, 1, 1 },  // 5
  { 1, 0, 1, 1, 1, 1, 1 },  // 6
  { 1, 1, 1, 0, 0, 0, 0 },  // 7
  { 1, 1, 1, 1, 1, 1, 1 },  // 8
  { 1, 1, 1, 1, 0, 1, 1 },  // 9
};

// ── Display a digit 0–9 ───────────────────────────────────────────────────────
void showDigit(int num) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(SEG_PINS[i], DIGITS[num][i]);
  }
}

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(SEG_PINS[i], OUTPUT);
  }
  Serial.begin(9600);
  Serial.println("7-Segment Display counting 0–9.");
}

void loop() {
  for (int n = 0; n <= 9; n++) {
    showDigit(n);
    Serial.println("Displaying: " + String(n));
    delay(700);
  }
}
