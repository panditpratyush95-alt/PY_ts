/*
 * Component 03 — Buzzer (Active & Passive)
 * ANU Electronics — Arduino Starter Kit
 *
 * Hardware:
 *   Buzzer + pin → Pin 3
 *   Buzzer - pin → GND
 *
 * Active buzzer: just set pin HIGH/LOW to beep.
 * Passive buzzer: use tone() to generate musical notes.
 *
 * This sketch demonstrates both modes — comment/uncomment as needed.
 */

#define BUZZER_PIN 3
#define BTN_PIN    2

// ── Musical note frequencies (Hz) ────────────────────────────────────────────
#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BTN_PIN, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("Buzzer ready. Press button to play melody.");
}

// ── Play a simple melody ─────────────────────────────────────────────────────
void playMelody() {
  int notes[]    = { NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4,
                     NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5 };
  int durations[] = { 300, 300, 300, 300, 300, 300, 300, 500 };

  for (int i = 0; i < 8; i++) {
    tone(BUZZER_PIN, notes[i], durations[i]);
    delay(durations[i] + 50);
  }
  noTone(BUZZER_PIN);
}

void loop() {
  if (digitalRead(BTN_PIN) == LOW) {
    Serial.println("Playing melody...");
    playMelody();
    delay(500);   // Debounce
  }

  // Simple beep example (active buzzer):
  // digitalWrite(BUZZER_PIN, HIGH); delay(500);
  // digitalWrite(BUZZER_PIN, LOW);  delay(500);
}
