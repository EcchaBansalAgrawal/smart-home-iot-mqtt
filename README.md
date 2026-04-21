# 🏠 Smart Home Automation using MQTT (IoT Project)

🚀 A real-time IoT-based home automation system using Raspberry Pi, NodeMCU, and MQTT protocol to control appliances remotely.

---

## 📌 Overview

This project demonstrates a **smart home system** where users can control electrical appliances like lights using a mobile device. It uses a lightweight communication protocol (**MQTT**) for fast and efficient data transfer.

---

## 🧠 Tech Stack

* 💻 Raspberry Pi (MQTT Broker)
* 📡 NodeMCU (ESP8266)
* 🔌 Relay Module
* ☁️ Mosquitto MQTT
* 📱 Mobile App (MQTT Client)

---

## 🏗️ System Architecture

User → MQTT → Broker → NodeMCU → Relay → Appliance

---

## 🔄 Project Pipeline

1. User sends ON/OFF command via mobile app
2. MQTT message is published
3. Raspberry Pi (broker) receives message
4. NodeMCU subscribes and processes command
5. Relay switches appliance

---

## ⚙️ Features

✅ Real-time device control
✅ Wireless communication
✅ Low latency using MQTT
✅ Scalable system
✅ Easy to extend with sensors

---

## 🖥️ Hardware Setup

* NodeMCU connected to relay
* Relay connected to bulb
* Raspberry Pi running Mosquitto

📷 *Add circuit diagram in docs/*

---

## 💻 Code Explanation

### NodeMCU

* Connects to WiFi
* Connects to MQTT broker
* Subscribes to topic
* Controls relay

### Raspberry Pi

* Runs Mosquitto broker
* Handles message routing

---

## 📸 Demo

👉 Add screenshots in `/demo/screenshots`
![Image 1](demo/screenshots/image1.jpeg)
![Image 2](demo/screenshots/image2.jpeg)
![Image 3](demo/screenshots/image3.jpeg)
<video src="video 1.mp4" width="100%" controls></video>

👉 Add video demo (very important for GitHub attraction)


---

## 🚀 How to Run

### Step 1: Setup Broker (Raspberry Pi)

* Install Mosquitto
* Start broker

### Step 2: Upload Code (NodeMCU)

* Configure WiFi & MQTT
* Upload using Arduino IDE

### Step 3: Use Mobile App

* Publish ON/OFF messages

---

## 🔮 Future Improvements

* Voice control (Alexa/Google Assistant)
* Sensor integration
* Cloud IoT (AWS / Firebase)


---

## ⭐ Show Your Support

If you like this project:
⭐ Star the repo
🍴 Fork it
📢 Share it

---
