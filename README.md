# 🤖 Arduino Line Follower Robot (LFR)

A complete Arduino-based Line Follower Robot project designed for students, hobbyists, and engineers to understand real-time sensing, control systems, and embedded robotics.

---

## 📌 Project Overview

A Line Follower Robot (LFR) is an autonomous robotic system that detects and follows a predefined path—typically a black line on a white surface or vice versa. This project demonstrates how simple sensors and logic can be combined to create intelligent motion behavior.

This project is developed by **Play With Circuit** and is structured to help you learn both practical implementation and the underlying theory.

---

## 🎯 Key Learning Outcomes

- Understanding IR-based sensing systems  
- Interfacing sensors with Arduino  
- Motor control using L293D motor driver  
- Real-time decision-making algorithms  
- Basics of autonomous robotics  

---

## ⚙️ Detailed Working Principle

The robot operates based on **light reflection properties** using IR sensors.

### 🔍 Sensor Theory

Each IR sensor consists of:
- **IR LED (Emitter)** → Emits infrared light  
- **Photodiode (Receiver)** → Detects reflected light  

Working behavior:
- **White Surface** → Reflects IR → Sensor outputs HIGH  
- **Black Surface** → Absorbs IR → Sensor outputs LOW  

This contrast allows the robot to distinguish between the path and the background.

---

## 🧠 Navigation Logic

The robot uses **two sensors (Left & Right)** to determine direction:

| Left Sensor | Right Sensor | Robot Action |
|------------|-------------|-------------|
| White      | White       | Move Forward |
| Black      | White       | Turn Left    |
| White      | Black       | Turn Right   |
| Black      | Black       | Stop         |

### 🔄 Motor Control Logic

- Forward → Both motors rotate forward  
- Left Turn → Left motor reverse, right motor forward  
- Right Turn → Left motor forward, right motor reverse  
- Stop → Both motors stop  

This simple logic creates effective path tracking.

---

## 🧰 Components Required

| Component                     | Quantity |
|------------------------------|----------|
| Arduino UNO                  | 1        |
| L293D Motor Driver Shield    | 1        |
| IR Line Sensor Module        | 2        |
| DC Geared Motors             | 4        |
| Robot Chassis + Wheels       | 1 Set    |
| Jumper Wires                 | As needed|
| Battery Pack (9V/12V)        | 1        |
| USB Cable                    | 1        |
| Black Tape (Track)           | 1        |

---

## 🔌 Circuit Diagram

![Circuit Diagram](https://playwithcircuit.com/wp-content/uploads/2024/10/Circuit-Diagram-of-Line-Following-Robot.webp)

---

## 🔗 Circuit Connections

### 🔹 IR Sensors to Arduino

| Sensor Pin | Arduino Connection |
|------------|-------------------|
| VCC        | 5V                |
| GND        | GND               |
| output pin of the left IR sensor   | A0                |
| Analog output pin of the right Line sensor  | A1                |

### 🔹 Motors to L293D Shield

| Motor Side   | Shield Port |
|--------------|------------|
| Left Motors  | M3         |
| Right Motors | M4         |

> ⚠️ Important: Disconnect external power supply while uploading code to prevent damage.

---

## 🛠️ Step-by-Step Assembly

1. **Prepare Chassis**  
   Mount all four motors securely on the chassis.

2. **Attach Wheels**  
   Fix wheels to the motors properly.

3. **Mount Sensors**  
   - Place sensors at the front  
   - Maintain ~2 cm height from ground  
   - Keep spacing ~11–11.5 cm  

4. **Install Arduino & Shield**  
   Stack the L293D motor driver shield onto Arduino and mount it on the chassis.

5. **Make Connections**  
   Connect sensors and motors as per the circuit diagram.

6. **Upload Code**  
   Use Arduino IDE to upload the program.

7. **Power the Robot**  
   Connect battery pack and start testing.

---

## 💻 Software Requirements

- Arduino IDE (Latest Version)  
- Adafruit Motor Shield Library (V1)  

---

## 🚀 Enhancements & Advanced Ideas

Take this project to the next level:

### 🔧 Performance Improvements
- Implement **PID control** for smooth tracking  
- Tune motor speed using PWM  

### 📡 Smart Features
- Add Bluetooth (HC-05) for remote monitoring  
- Integrate Wi-Fi (ESP32)  
- Add OLED display for debugging  

### 🤖 Advanced Robotics
- Add obstacle avoidance  
- Use encoder motors for precision  
- Implement AI-based path prediction  

---

## 🧪 Troubleshooting Guide

### ❌ Robot not following line
- Check sensor alignment  
- Ensure correct sensor height (~2 cm)  
- Verify sensor outputs  

### ❌ Robot moving randomly
- Check loose connections  
- Reduce ambient light interference  

### ❌ Motors not rotating
- Verify motor driver connections  
- Check power supply  

### ❌ Wrong direction movement
- Swap motor wires  
- Verify logic in code  

---

## 💡 Pro Tips

- Use **matte black tape** (avoid reflective surfaces)  
- Keep wiring neat and secure  
- Test on a flat and clean surface  
- Calibrate sensors before running  

---

## 📈 Applications

- Industrial automation  
- Warehouse robots  
- Automated guided vehicles (AGVs)  
- Educational robotics  

---

## 📄 License

This project is open-source and free to use for educational and personal purposes.

---

## 🙌 Credits

Developed by **Play With Circuit**

---
