# Rock-Sentinals

### AI-Assisted Multi-Sensor Conveyor Belt Defect Detection and Inspection

<p align="center">
  <img src="media/prototype-images/complete-prototype.jpg" width="800">
</p>

<p align="center">
  <b>Smart India Hackathon 2026 Project</b>
</p>

---

## 📌 Overview

The **Smart Conveyor Inspection System** is an intelligent conveyor belt monitoring and inspection prototype designed for mining and industrial conveyor applications.

The current prototype combines:

* IR-based sensing
* Vibration-based condition detection
* Audible alerting using buzzers
* ESP32-based sensor interfacing
* Webcam-based visual inspection
* YOLOv8-based AI detection

The prototype demonstrates how multiple sensing mechanisms can work together to identify abnormal conveyor conditions and support automated visual inspection.

The system is being developed toward a larger industrial architecture incorporating **Teensy 4.1, PLC-based control, thermal imaging, defect localization, and drone-assisted inspection**.

---

# 🎯 Problem Statement

Mining conveyor belts operate continuously under demanding mechanical and environmental conditions.

Defects such as abnormal belt conditions, mechanical disturbances, and other faults may require timely detection to reduce downtime and maintenance risks.

Traditional inspection can depend heavily on manual observation and periodic checking.

This project explores a **multi-modal condition sensing approach** where physical sensors provide early indications of abnormal conditions and computer vision provides additional visual inspection.

---

# 💡 Proposed Solution

The system follows a two-stage inspection approach:

### Stage 1 — Sensor-Based Detection

Physical sensors continuously observe the conveyor prototype.

The current implementation includes:

* Two IR sensors
* One vibration sensor
* Buzzers for alert generation
* ESP32 for sensor interfacing

### Stage 2 — AI-Based Visual Inspection

A webcam observes the conveyor belt and provides visual data to the YOLOv8-based AI pipeline.

This creates a combined sensing workflow:

```text
IR Sensing
     │
     ├──────────────┐
     │              │
     ▼              ▼
Abnormality      Buzzer Alert
Detection
     │
     │
Vibration Sensing
     │
     ▼
Abnormal Vibration
     │
     ▼
Buzzer Alert


             PARALLEL VISUAL INSPECTION
                       │
                       ▼
                    Webcam
                       │
                       ▼
                    YOLOv8
                       │
                       ▼
               Visual Detection
```

---

# 🔧 Current Prototype

## Hardware

| Component        | Quantity | Purpose                            |
| ---------------- | -------: | ---------------------------------- |
| ESP32            |        1 | Prototype controller               |
| IR Sensor        |        2 | Detect changes/abnormal conditions |
| Vibration Sensor |        1 | Detect abnormal vibration          |
| Buzzer           |       3* | Audible alert                      |
| Webcam           |        1 | Visual inspection                  |

> *The exact number of buzzers can be updated according to the final wiring implementation.*

---

# 📡 IR Sensor Detection

Two IR sensors are currently integrated into the prototype.

Their outputs are monitored by the ESP32.

When an abnormal condition is detected, the corresponding buzzer is activated to provide an immediate local alert.

```text
IR Sensor 1 ──► ESP32 ──► Buzzer 1
IR Sensor 2 ──► ESP32 ──► Buzzer 2
```

### Demonstration

<p align="center">
  <img src="media/prototype-images/ir-sensor-1.jpg" width="400">
  <img src="media/prototype-images/ir-sensor-2.jpg" width="400">
</p>

---

# 📳 Vibration Detection

A vibration sensor is used to monitor mechanical vibration from the conveyor prototype.

The ESP32 reads the vibration signal and triggers an audible alert when the defined detection condition is reached.

```text
Vibration Sensor
       │
       ▼
     ESP32
       │
       ▼
   Vibration
   Condition
       │
       ▼
    Buzzer
```

<p align="center">
  <img src="media/prototype-images/vibration-sensor.jpg" width="600">
</p>

---

# 🔊 Audible Alert System

Buzzers provide immediate local notification when the sensing layer detects an abnormal condition.

This allows the prototype to demonstrate a simple real-time alert mechanism.

```text
Sensor
  ↓
Condition Detected
  ↓
ESP32
  ↓
Buzzer
  ↓
Local Alert
```

---

# 📷 Webcam-Based Inspection

A webcam is used as the visual sensing device for the current prototype.

The camera continuously provides visual information that can be analyzed by the computer vision pipeline.

<p align="center">
  <img src="media/prototype-images/webcam-setup.jpg" width="600">
</p>

---

# 🤖 YOLOv8 AI Model

The prototype incorporates a **YOLOv8-based computer vision pipeline** for visual defect detection.

The general workflow is:

```text
Webcam
   ↓
Image / Video Frame
   ↓
YOLOv8 Model
   ↓
Object / Defect Detection
   ↓
Detection Result
```

The AI module is intended to complement sensor-based detection by providing visual information about the observed conveyor region.

---

# 🔄 Complete Current Prototype Flow

```text
                CONVEYOR BELT
                     │
        ┌────────────┼────────────┐
        │            │            │
        ▼            ▼            ▼
     IR Sensor    IR Sensor   Vibration
        1            2          Sensor
        │            │            │
        └──────┬─────┴──────┬─────┘
               │            │
               ▼            ▼
             ESP32       ESP32 Logic
               │            │
               ▼            ▼
           Buzzer Alerts

                  + 

               Webcam
                  │
                  ▼
               YOLOv8
                  │
                  ▼
           Visual Detection
```

---

# 🧠 Multi-Modal Detection Concept

The key concept of the prototype is combining different sensing modalities.

Instead of depending only on a camera or a single physical sensor, the system combines:

### Physical sensing

* IR
* Vibration

### Visual sensing

* Webcam
* YOLOv8

### Alerting

* Buzzer

This architecture provides multiple sources of information about conveyor condition.

---

# 🏗️ Current vs Planned Architecture

## Current Prototype

```text
IR Sensors
     │
Vibration Sensor
     │
     ▼
   ESP32
     │
     ├──► Buzzers
     │
     └──► Prototype Monitoring

Webcam
   │
   ▼
 YOLOv8
```

## Planned Expanded System

```text
                    CONVEYOR BELT
                          │
                          ▼
                MULTI-MODAL SENSORS
                          │
          ┌───────────────┼────────────────┐
          │               │                │
          ▼               ▼                ▼
       Teensy 4.1         PLC        Additional Sensors
          │
          └───────────────┬────────────────┘
                          ▼
                  CONDITION ANALYSIS
                          │
                          ▼
                   DEFECT LOCATION
                          │
                          ▼
                        DRONE
                          │
                 ┌────────┴────────┐
                 ▼                 ▼
            RGB CAMERA       THERMAL CAMERA
                 │                 │
                 └────────┬────────┘
                          ▼
                        YOLOv8
                          │
                          ▼
                  INSPECTION RESULT
                          │
                          ▼
                  MONITORING SYSTEM
```

---

# 🚁 Future Drone-Assisted Inspection

A future version of the system will incorporate a drone for secondary visual inspection.

The intended workflow is:

```text
Sensor-Based Anomaly
        ↓
Defect Localization
        ↓
Inspection Location
        ↓
Drone Deployment
        ↓
Target Area
        ↓
RGB + Thermal Imaging
        ↓
AI-Based Analysis
```

The drone subsystem is currently part of the planned expanded architecture and is not represented as completed hardware in the current prototype.

---

# 🌡️ Future Thermal Inspection

A thermal camera is planned for integration into the expanded inspection system.

Thermal imaging can provide additional information about temperature-related anomalies that may not be visible in normal RGB imagery.

Planned workflow:

```text
Thermal Camera
      ↓
Thermal Image
      ↓
Thermal Analysis
      ↓
Anomaly Identification
```

---

# ⚙️ Future Industrial Controller

The current prototype uses an **ESP32** for experimental sensor interfacing.

The planned industrial architecture will transition toward:

### Teensy 4.1

For high-speed edge-side sensor acquisition and processing.

### PLC

For industrial control and system integration.

The migration will allow the prototype architecture to evolve toward an industrial implementation.

---

# 📁 Repository Structure

```text
smart-conveyor-inspection/
│
├── prototype/
│   ├── hardware/
│   │   ├── esp32/
│   │   ├── ir-sensors/
│   │   ├── vibration-sensor/
│   │   ├── buzzers/
│   │   └── webcam/
│   │
│   ├── firmware/
│   │   ├── ir/
│   │   └── vibration/
│   │
│   └── ai/
│       └── yolov8/
│
├── docs/
│   ├── architecture/
│   ├── hardware/
│   └── research/
│
├── media/
│   ├── prototype-images/
│   ├── wiring/
│   ├── videos/
│   └── diagrams/
│
├── data/
│   └── sample/
│
└── future/
    ├── teensy-4.1/
    ├── plc/
    ├── thermal-camera/
    └── drone/
```

---

# 📊 Development Status

| Module                       | Status         |
| ---------------------------- | -------------- |
| Conveyor prototype           | 🟢 Implemented |
| ESP32 interfacing            | 🟢 Implemented |
| IR Sensor 1                  | 🟢 Implemented |
| IR Sensor 2                  | 🟢 Implemented |
| IR alert mechanism           | 🟢 Implemented |
| Vibration sensing            | 🟢 Implemented |
| Vibration alert              | 🟢 Implemented |
| Webcam integration           | 🟢 Implemented |
| YOLOv8 visual detection      | 🟢 Prototype   |
| Teensy 4.1                   | 🔵 Planned     |
| PLC integration              | 🔵 Planned     |
| Additional condition sensors | 🔵 Planned     |
| Thermal camera               | 🔵 Planned     |
| Defect localization          | 🔵 Planned     |
| Drone inspection             | 🔵 Planned     |
| Centralized dashboard        | 🔵 Planned     |

---

# 🎥 Prototype Demonstration

Demonstration videos will be added to:

```text
media/videos/
```

Recommended demonstrations:

1. IR Sensor 1 detection
2. IR Sensor 2 detection
3. Vibration detection
4. Buzzer alert
5. Webcam inspection
6. YOLOv8 detection
7. Complete prototype demonstration

---

# 📷 Prototype Gallery

Project photographs will be maintained in:

```text
media/prototype-images/
```

Suggested documentation photographs:

* Complete conveyor prototype
* ESP32
* IR sensor placement
* Vibration sensor placement
* Buzzer setup
* Webcam setup
* Complete wiring
* Complete system

---

# 🔬 Research Areas

The project is based around research and development in:

* Conveyor belt condition monitoring
* Industrial IoT
* Multi-modal sensing
* Predictive maintenance
* Vibration monitoring
* Computer vision
* YOLO object detection
* Thermal inspection
* Edge computing
* Industrial PLC systems
* Drone-assisted inspection

Research references will be maintained in:

```text
docs/research/research-references.md
```

---

# 🚧 Roadmap

### Phase 1 — Prototype

* [x] Conveyor prototype
* [x] IR sensing
* [x] Vibration sensing
* [x] Buzzer alerts
* [x] ESP32 integration
* [x] Webcam integration
* [x] YOLOv8 prototype

### Phase 2 — Industrial Architecture

* [ ] Teensy 4.1 integration
* [ ] PLC integration
* [ ] Additional sensing modalities
* [ ] Improved sensor calibration
* [ ] Defect localization

### Phase 3 — Advanced Inspection

* [ ] Thermal camera
* [ ] Drone integration
* [ ] Drone-based visual inspection
* [ ] RGB + thermal analysis
* [ ] Automated inspection workflow

### Phase 4 — Monitoring Platform

* [ ] Backend
* [ ] Firebase
* [ ] Web dashboard
* [ ] Historical inspection data
* [ ] Real-time system status

---

# 🤝 Contribution

Contributions and suggestions are welcome.

Please document hardware, firmware, AI, and software changes clearly before submitting them.

---

# 📄 License

This project is licensed under the MIT License.

---

# 🏆 Project

**Smart India Hackathon 2026**

**Domain:** Mining / Industrial Automation / Smart Inspection

---

<p align="center">
  <b>Smart Conveyor Inspection System</b><br>
  Multi-Modal Sensing • AI Vision • Automated Inspection
</p>
