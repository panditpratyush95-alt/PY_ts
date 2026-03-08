/*
 * Component 15 — Relay Module (5V, 1-Channel)
 * ANU Electronics — Arduino Starter Kit
 *
 * Hardware:
 *   Relay VCC → 5V
 *   Relay GND → GND
 *   Relay IN  → Pin 8
 *
 *   Load wiring (e.g. a lamp):
 *     AC Live → COM terminal of relay
 *     NC (Normally Closed) → load when relay OFF
 *     NO (Normally Open)   → load when relay ON
 *
 * Most relay modules are ACTIVE LOW:
 *   digitalWrite LOW  → relay coil energised → NO contact closes → load ON
 *   digitalWrite HIGH → relay coil off       → NC contact closes → load OFF
 *
 * ⚠️ SAFETY: Only switch mains voltage if you are qualified to do so.
 *    Use low-voltage loads (LEDs, fans, 12V) for learning purposes.
 */

#define RELAY_PIN 8
#define BTN_PIN   2

// Active LOW relay: LOW = relay ON, HIGH = relay OFF
#define RELAY_ON  LOW
#define RELAY_OFF HIGH

bool relayState = false;
bool prevBtn    = HIGH;

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(BTN_PIN,   INPUT_PULLUP);
  digitalWrite(RELAY_PIN, RELAY_OFF);   // Start with relay OFF
  Serial.begin(9600);
  Serial.println("Relay Module ready.");
  Serial.println("Press button to toggle relay.");
}

void loop() {
  bool btn = digitalRead(BTN_PIN);

  // Detect button press (HIGH → LOW edge)
  if (btn == LOW && prevBtn == HIGH) {
    relayState = !relayState;
    digitalWrite(RELAY_PIN, relayState ? RELAY_ON : RELAY_OFF);
    Serial.println(relayState ? "🔌 Relay ON  (load connected)" : "⭕ Relay OFF (load disconnected)");
    delay(50);   // Debounce
  }

  prevBtn = btn;
  delay(20);
}
