# 🏠 Dual-Level IoT Smart Home Automation System  
### Integrating Human-Centric Access and Rain-Responsive Asset Protection

---

## 📌 Project Overview

This project presents a **Dual-Level IoT Smart Home Automation System** developed as part of the Diploma in Computer Science & Technology internship project.

The system integrates:

- 🚪 **Automatic Door Access System**
- 🌧 **Rain-Responsive Asset Protection System**

Using an **Arduino Uno**, sensors, and actuator mechanisms, the system creates a proactive smart environment that responds to both human presence and environmental changes.

---

## 🎯 Objectives

- Automate door access using IR-based human detection
- Protect household assets during rainfall using sensor-triggered pulley mechanism
- Demonstrate real-time sensing and actuation
- Develop a scalable low-cost IoT-based smart home prototype

---

# 🔹 Level 1: Automatic Door System

## 🧠 Working Principle

The system uses an **IR sensor** to detect human presence. When a person is detected:

1. IR sensor sends signal to Arduino
2. Arduino processes input
3. L293D motor driver activates DC motor
4. Motor rotates to open door
5. After delay / absence detection → door closes automatically

---

## ⚙️ Components Used

- Arduino Uno
- IR Sensor
- L293D Motor Driver
- DC Motor
- Power Supply
- Mechanical Door Model

---

## 🔄 Pseudocode

```text
START
Initialize IR sensor as INPUT
Initialize motor pins as OUTPUT

LOOP:
    Read IR sensor
    IF person detected:
        Rotate motor forward (open door)
        Wait predefined time
    ELSE:
        Rotate motor backward (close door)
END LOOP
```

---

# 🔹 Level 2: Rain-Responsive Protection System

## 🧠 Working Principle

The rain detection module uses a **Rain Sensor** to detect precipitation.

When rain is detected:

1. Rain sensor sends signal to Arduino
2. Arduino compares value with threshold
3. MG996R Servo motor rotates
4. Pulley mechanism activates to protect assets
5. When rain stops → system resets

---

## ⚙️ Components Used

- Arduino Board
- Rain Sensor Module
- MG996R Servo Motor
- Pulley Mechanism
- Power Supply

---

## 🔄 Pseudocode

```text
START
Initialize rain sensor as INPUT
Initialize servo motor

LOOP:
    Read rain sensor value
    IF value > threshold:
        Move servo to protection angle
    ELSE:
        Return servo to initial position
END LOOP
```

---

# 📊 System Implementation Results

## ✅ Automatic Door
- Reliable IR-based detection
- Smooth motor rotation
- Automatic open/close functionality
- No manual intervention required

## ✅ Rain Detection
- Accurate rainfall sensing
- Servo-driven pulley activation
- Automatic protective response
- Real-time environmental adaptation

---

# 💬 Discussion

### Automatic Door
- Cost-effective and simple implementation
- May be affected by ambient light interference
- Requires proper motor delay calibration

### Rain Detection
- Accurate and responsive
- Requires periodic sensor cleaning
- Threshold tuning improves reliability

---

# 🏁 Conclusion

The Dual-Level IoT Smart Home Automation System successfully integrates:

- Human-centric automated access
- Environment-responsive asset protection

The project demonstrates how low-cost microcontrollers and sensors can be effectively used to enhance convenience, safety, and automation in modern smart homes.

The system provides strong potential for:
- IoT cloud integration
- Wireless connectivity
- Mobile app control
- Smart city applications

---

# 🏫 Academic Details

**Institution:** Techno India, Salt Lake  
**Council:** West Bengal State Council of Technical Education  

**Project Team:**
- Rashmi Singh  
- Dharmistha Ghosh  
- Akshaj Hui  
- Sohan Dey  
- Soumili Bandhapayay  

**Guided By:**
- Subhajit Bhowmick  
- Rajdeep Ghatak  

---

# 📚 References

- Arduino Uno Documentation (Arduino.cc)
- L293D Motor Driver Datasheet (Texas Instruments)
- ESP32 Technical Reference Manual (Espressif Systems)
- IEEE Xplore – IoT Home Automation Research
- Embedded Systems & IoT Development Resources

---

# 🚀 Future Enhancements

- WiFi / ESP32 cloud integration
- Mobile app monitoring
- Real-time cloud dashboard
- AI-based environmental prediction
- Energy optimization algorithms

---

## 📂 Repository Structure

```
/docs → Project report, diagrams  
/code → Arduino source code  
/images → Prototype photos  
```

---

## 👨‍💻 Developed As Part of Internship Project  
Diploma in Computer Science & Technology