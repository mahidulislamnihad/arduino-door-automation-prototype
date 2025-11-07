# Arduino-Based Door Automation Prototype using PIR and Ultrasonic Sensor
Arduino Uno + PIR + Ultrasonic sensor

**Author:** Mahidul Islam Nihad  
**Email:** mahidulislamnihad28@gmail.com  

A simple R&D prototype demonstrating **sensor-fusion automation** using Arduino Uno, PIR (HC-SR501), and Ultrasonic (HC-SR04) sensors for safe door control.

---

## ⚙️ Project Overview
- Motion detection via PIR sensor  
- Obstacle detection (≤ 20 cm) via Ultrasonic sensor  
- Servo motor (180°) control with 5 s open delay  
- Serial Monitor feedback for testing  

---

## 📁 Repository Structure

| Folder | Description |
|---------|-------------|
| `code/` | Arduino sketch (`automated_door.ino`) |
| `hardware/` | Circuit diagram and prototype photos |
| `docs/` | Report (PDF) and test results |

---

## 🚀 How to Run
1. Connect components as shown in `hardware/circuit-diagram.png`.  
2. Open `code/automated_door.ino` in Arduino IDE (2.3.6 or later).  
3. Select *Arduino Uno* board → Upload.  
4. Open Serial Monitor (9600 baud) to see motion and distance readings.  

---

## 📊 Results (Summary)
| Metric | Outcome |
|---------|----------|
| Motion detection range | ≈ 3–7 m |
| Distance accuracy | ± 3 mm |
| Delay | ~0.5 s due to sensor processing |
| Notes | Occasional false triggers under IR noise or heat fluctuation |

---

## 🔬 R&D Focus
This project explores low-cost **embedded sensor fusion** for automation and energy-saving systems.  
Future work:  
- Add ESP32 + MQTT for remote monitoring  
- Implement software filtering to reduce false triggers  
- Add OLED display for stand-alone feedback  

---

## 🧩 Libraries Used
`Servo.h`, `Arduino.h`

---

## 📄 License
Released under the MIT License.

---


