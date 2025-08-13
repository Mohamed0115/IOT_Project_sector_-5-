# IOT_Project_sector_-5-
LATER
#SectorB5 IoT Project 🌐✨
Mentored by: Omar Barakat
#🌟 Project Overview
The SectorB5 IoT Project is an exciting venture into the world of Internet of Things (IoT) technology! 🎉 This project leverages an ESP32 microcontroller to create a smart system that integrates an IR sensor and an LED, controlled and monitored via the IoT MQTT Panel app. 🚀 The system demonstrates real-time communication using the MQTT protocol, allowing users to toggle the LED remotely and detect objects using the IR sensor. 🌱 Perfect for learning IoT fundamentals and building interactive smart devices! 🛠️  
#🛠️ Components

1 IR Sensor - Detects the presence of objects.  
1 Red LED - Indicates the system's status or responds to commands.  
5 Male-Male Jumper Wires - Ensures secure connections between components.  
1 ESP32 - The brain of the project, handling Wi-Fi and MQTT communication.  
1 Breadboard - Provides a platform for prototyping the circuit.

#🔌 Wiring

Connect the IR sensor to GPIO 36 on the ESP32.  
Connect the red LED to GPIO 22 on the ESP32 with appropriate current-limiting resistors.  
Use male-male jumper wires to establish connections on the breadboard, ensuring a stable and organized setup.

#📡 MQTT Topics

/sectorb5/msbah/1: Sends "object" or "noobject" based on IR sensor detection.  
/sectorb5/msbah/2: Sends "yes" or "no" to indicate object presence.  
/sectorb5/msbah/3: Receives "on" or "off" commands to control the LED.

#⚙️ How It Works
The system connects to a Wi-Fi network and the public MQTT broker at broker.emqx.io. 🌐 The ESP32 subscribes to the /sectorb5/msbah/3 topic to receive LED control commands ("on" or "off"). 📡 The IR sensor continuously monitors for objects, publishing the status to /sectorb5/msbah/1 and /sectorb5/msbah/2 every 500ms. 🔄 When an object is detected (IR reads 0), it sends "object" and "yes"; otherwise, it sends "noobject" and "no". 🎯 The LED toggles based on the received MQTT commands, creating an interactive IoT experience! 🌈  
#📱 Mobile App Setup (IoT MQTT Client)
Steps to Make Setup on Mobile:

Download and install the IoT MQTT Panel app from your app store. 📲  
Open the app and add a new MQTT client configuration. ⚙️  
Enter the broker details: broker.emqx.io with port 1883. 🌐  
Subscribe to /sectorb5/msbah/1 and /sectorb5/msbah/2 to monitor sensor data. 👀  
Publish to /sectorb5/msbah/3 with "on" or "off" to control the LED. 🔧  
Save the configuration and connect to start interacting with the project! 🎉

#🎥 Demo & Results

A video showcasing the project in action is available! Watch the LED toggle and sensor data update in real-time. 📹  
Screenshots or additional videos can be added here to highlight the setup and results. 🖼️

#🧠 Learnings

Gained hands-on experience with ESP32 programming and IoT communication. 📚  
Mastered MQTT protocol for real-time data exchange. 🌐  
Learned to integrate hardware components like IR sensors and LEDs on a breadboard. 🛠️  
Developed skills in setting up and configuring mobile IoT apps. 📱  
Understood the importance of stable wiring and efficient code optimization. 💡
