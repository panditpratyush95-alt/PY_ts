# 🚀 Getting Started with Your ANU Electronics Arduino Starter Kit

Welcome! Follow this guide to go from unboxing to your first running sketch in under 10 minutes.

---

## Step 1 — Install Arduino IDE

1. Go to **[arduino.cc/en/software](https://arduino.cc/en/software)**
2. Download **Arduino IDE 2.x** for your operating system
3. Install it (run `.exe` on Windows, drag to Applications on Mac, run `install.sh` on Linux)

---

## Step 2 — Connect Your Arduino Uno

1. Plug the **USB cable** into the Arduino Uno and your computer
2. The **green power LED** on the board should light up
3. Open Arduino IDE — you'll see a blank sketch

---

## Step 3 — Select Board & Port

1. **Tools → Board → Arduino AVR Boards → Arduino Uno**
2. **Tools → Port** → select the port that appeared when you plugged in:
   - Windows: `COM3`, `COM4`, etc.
   - macOS: `/dev/tty.usbmodemXXXX`
   - Linux: `/dev/ttyACM0`

> If no port appears on Windows, install the **CH340 driver** (search "CH340 driver download").

---

## Step 4 — Install Libraries

Go to **Sketch → Include Library → Manage Libraries** and install:

| Library Name | Publisher |
|---|---|
| DHT sensor library | Adafruit |
| LiquidCrystal I2C | Frank de Brabander |

The **Servo** and **Stepper** libraries are built-in — no install needed.

---

## Step 5 — Upload Your First Sketch

1. In this repository, open **`01_LED_Blink/led_blink.ino`**
2. Click the **Upload button (→)** in the top-left of Arduino IDE
3. Wait for "Done uploading" in the status bar
4. The LED on **Pin 13** of your Arduino should blink on and off every second! 🎉

---

## Step 6 — Read the Full Tutorial

Open the HTML manual in your browser for full wiring diagrams, explanations and all project guides:

```
docs/arduino_tutorial_part1.html
```

Just **double-click** the file — it opens in any browser, no internet needed.

---

## 🔧 Common Problems

| Problem | Solution |
|---------|---------|
| Port not visible | Try a different USB cable (must be data cable, not charge-only) |
| `avrdude: stk500_recv()` error | Hold the **RESET** button and click Upload, release when you see "Uploading..." |
| LCD shows nothing / blocks | Run `File → Examples → Wire → i2c_scanner` — change address in sketch to match |
| PIR sensor not triggering | Wait 30–60 seconds after power-on for calibration |
| `DHT.h: No such file` | Install the Adafruit DHT library via Library Manager |

---

## 📞 Support

If you have any issues with your kit, please contact:

**ANU Electronics** · [anuelectronics.com](https://anuelectronics.com)

---

*Happy Making! 🛠️*
