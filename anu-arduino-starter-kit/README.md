# ⚡ ANU Electronics — Arduino Starter Kit

> **Complete Arduino learning kit for students, makers & engineers.**
> From your first LED blink to real-world automation projects — everything included.

[![Arduino](https://img.shields.io/badge/Platform-Arduino%20Uno-00979D?style=flat&logo=arduino)](https://arduino.cc)
[![License](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
[![Components](https://img.shields.io/badge/Components-17-green.svg)](#-components)
[![Projects](https://img.shields.io/badge/Projects-5-orange.svg)](#-projects)

---

## 📦 What's in This Repository

| Folder | Contents |
|--------|----------|
| `01_LED_Blink` … `17_Stepper_Motor` | Arduino sketches for all 17 kit components |
| `projects/` | 5 complete real-world project sketches |
| `docs/` | Full interactive HTML tutorial manuals |

---

## 🚀 Quick Start

### 1. Set Up Arduino IDE
1. Download **Arduino IDE 2.x** from [arduino.cc/en/software](https://arduino.cc/en/software)
2. Connect your Arduino Uno via USB
3. **Tools → Board → Arduino Uno**
4. **Tools → Port** → select your COM port (Windows) or `/dev/ttyACM0` (Linux/Mac)

### 2. Install Required Libraries
Go to **Sketch → Include Library → Manage Libraries** and install:

| Library | Search For | Used In |
|---------|-----------|---------|
| DHT sensor library | `DHT sensor library` by Adafruit | DHT11 Sensor, Weather Station |
| LiquidCrystal I2C | `LiquidCrystal I2C` by Frank de Brabander | I2C LCD, Projects |
| Servo | Built-in | Servo Motor |
| Stepper | Built-in | Stepper Motor |

### 3. Open and Upload a Sketch
1. Open any `.ino` file (e.g. `01_LED_Blink/led_blink.ino`)
2. Click **Upload (→)**
3. Open **Serial Monitor** (Tools → Serial Monitor, 9600 baud) to see output

---

## 💡 Components

| # | Component | Sketch | Key Pins |
|---|-----------|--------|----------|
| 01 | LED Blink | `led_blink.ino` | Pin 13 |
| 02 | Push Button | `push_button.ino` | Pin 2, 13 |
| 03 | Buzzer | `buzzer.ino` | Pin 3 |
| 04 | Trimpot / Potentiometer | `trimpot.ino` | A0, Pin 9 (PWM) |
| 05 | RGB LED | `rgb_led.ino` | Pins 9, 10, 11 (PWM) |
| 06 | 7-Segment Display | `seven_segment.ino` | Pins 2–8 |
| 07 | I2C LCD Display (16×2) | `i2c_lcd.ino` | A4 (SDA), A5 (SCL) |
| 08 | LDR Light Sensor | `ldr_sensor.ino` | A0, Pin 9 |
| 09 | Flame Sensor | `flame_sensor.ino` | Pin 2, A0 |
| 10 | Vibration Sensor | `vibration_sensor.ino` | Pin 2 |
| 11 | Joystick | `joystick.ino` | A0, A1, Pin 2 |
| 12 | IR Sensor | `ir_sensor.ino` | Pin 2 |
| 13 | Ultrasonic HC-SR04 | `ultrasonic.ino` | Pin 9 (TRIG), Pin 10 (ECHO) |
| 14 | DHT11 Temperature & Humidity | `dht11.ino` | Pin 7 |
| 15 | Relay Module | `relay.ino` | Pin 8 |
| 16 | Servo Motor (SG90) | `servo.ino` | Pin 9 (PWM) |
| 17 | Stepper Motor (28BYJ-48) | `stepper.ino` | Pins 8–11 |

---

## 🛠️ Projects

| Project | Components | What It Does |
|---------|-----------|--------------|
| 🌃 **Auto Street Light** | LDR + Relay + LCD | Automatically turns light ON at night, OFF at day |
| 🔒 **Security System** | PIR + Buzzer + LCD + LEDs | Arm/disarm alarm with intruder detection |
| 🌦️ **Weather Station** | DHT11 + LCD | Displays temp, humidity & heat index |
| 🅿️ **Car Parking Sensor** | HC-SR04 + RGB LEDs + Buzzer + LCD | 4-zone distance alert with colour indicators |
| 🚪 **Touchless Doorbell** | IR Sensor + Buzzer + LCD | Wave to ring — counts visitors |

---

## 📖 Documentation

The `docs/` folder contains two complete interactive HTML manuals:

| File | Contents |
|------|----------|
| `arduino_tutorial_part1.html` | Full step-by-step tutorial: Introduction, IDE setup, programming basics, all 17 components, all 5 projects, resistor colour code reference |
| `ANU_Electronics_Complete_Manual.html` | Bug-in-Circuit IoT Kit manual: ESP32, 12 IoT projects, ThingSpeak cloud, circuit debugging |

**To view:** Download and open the `.html` file in any web browser — no internet required.

---

## 📌 Arduino Uno Pin Reference

```
                    ┌──────────────────────┐
              RESET │                      │ Vin
               3.3V │                      │ GND
                5V  │   Arduino Uno R3     │ GND
                GND │                      │ 5V
                GND │      ATmega328P      │ A0 ← Analog / ADC
               Vin  │                      │ A1
                    │                      │ A2
               D0 ← │ RX  (Serial)         │ A3
               D1 → │ TX  (Serial)         │ A4 ← I2C SDA
               D2 ← │ INT0                 │ A5 ← I2C SCL
             ~ D3 ← │ INT1 / PWM           │
               D4   │                      │ D13 → Built-in LED
             ~ D5   │ PWM                  │ D12
             ~ D6   │ PWM                  │ D11 ~ PWM / SPI MOSI
               D7   │                      │ D10 ~ PWM / SPI SS
               D8   │ SPI SS (alt)         │ D9  ~ PWM
                    └──────────────────────┘
   ~ = PWM capable pin
```

**Key specs:** 5V logic · 16 MHz · 14 digital pins · 6 analog pins · 40 mA max per pin

---

## ⚠️ Safety & Tips

- Always use a **220Ω resistor** in series with any LED
- Power stepper motors from an **external 5V supply** — not the Arduino's 5V pin
- **Never connect relay mains wiring** unless you are qualified; use 5–12V DC loads for learning
- Wait **30–60 seconds** after power-on for the **PIR sensor** to calibrate before testing
- If your **I2C LCD** shows nothing, run `File → Examples → Wire → i2c_scanner` to find the correct address (common addresses: `0x27` or `0x3F`)
- Avoid using **GPIO 0 and 1** (RX/TX) for other purposes — they're used by the Serial Monitor

---

## 🛒 Get the Kit

Sold by **ANU Electronics** · [anuelectronics.com](https://anuelectronics.com)

Each kit includes the Arduino Uno R3, all components listed above, breadboard, jumper wires, USB cable, and a printed quick-start card.

---

## 📄 License

This repository is licensed under the [MIT License](LICENSE).
You are free to use, modify, and distribute these sketches for personal and educational purposes.

---

*ANU Electronics · Arduino Starter Kit · Made for learners, by makers.*
