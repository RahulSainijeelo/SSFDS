# Smart Smoke and Fire Detection System

This project demonstrates a **Smart Smoke and Fire Detection System** using the NodeMCU ESP8266, MQ-6 gas and smoke sensor, DHT sensor, buzzer, LED, and the Blynk IoT platform. The system continuously monitors smoke levels, temperature, and humidity, sending alerts when thresholds are crossed. It also provides real-time data through the Blynk app.

## Features

- **Real-time monitoring** of:
  - Smoke levels (MQ-6 Sensor)
  - Temperature (DHT Sensor)
  - Humidity (DHT Sensor)
- **Alerts**:
  - Buzzer and LED activation when thresholds are exceeded.
  - Notifications via Blynk app.
- **Cloud integration** with Blynk for real-time data display and notifications.
- Adjustable thresholds for gas and temperature levels.

## Components

- **Microcontroller**: NodeMCU ESP8266
- **Sensors**:
  - MQ-6 Gas Sensor
  - DHT11/DHT22 Temperature and Humidity Sensor
- **Actuators**:
  - Buzzer
  - LED (Red)
- **Cloud Platform**: Blynk IoT
- **Power Supply**: USB or external source

## Circuit Connections

- **DHT Sensor**: Pin D2
- **MQ-6 Sensor**: Pin A0
- **Buzzer**: Pin D3
- **LED**: Pin D4

## Setup Instructions

### Hardware Setup

1. Connect the components to the NodeMCU as per the pin configuration:
   - DHT Sensor → D2
   - MQ-6 Sensor → A0
   - Buzzer → D3
   - LED (Red) → D4
2. Power the NodeMCU via USB or an external power supply.
3. Ensure the MQ-6 sensor is properly calibrated for accurate readings.

### Software Setup

1. Install the following libraries in the Arduino IDE:
   - `ESP8266WiFi.h`
   - `BlynkSimpleEsp8266.h`
   - `DHT.h`
2. Replace the placeholders in the code with your:
   - Wi-Fi SSID and password.
   - Blynk **Template ID**, **Template Name**, and **Auth Token**.
3. Upload the code to the NodeMCU.

### Blynk Setup

1. Create a new **Template** in Blynk with the ID `TMPL332Z8HKpW` and name "Smart Smoke and Fire Detection System."
2. Add the following virtual pins in the Blynk app:
   - V0: Temperature
   - V1: Humidity
   - V2: Gas Level
   - V3: Alert Status
3. Configure Blynk notifications or automations for events like `fire_detected`.

### Group Members for The Project
   - Mohammad Suhail (Roll No. 39)
   - Rahul Kumar Singh (Roll No. 55)
   - Rahul Saini (Roll No. 56)
   - Zafar Ali (Roll No. 75)

## Code

The complete code for the project is available in this repository. Below is a snippet of key parts:

```cpp
#define BLYNK_TEMPLATE_ID "TMPL332Z8HKpW"
#define BLYNK_TEMPLATE_NAME "Smart Smoke and Fire Detection System"
#define BLYNK_AUTH_TOKEN "YourAuthTokenHere"

// Libraries
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

// Configuration
#define DHTPIN D2
#define DHTTYPE DHT11
#define MQ6_PIN A0
#define BUZZER_PIN D3
#define LED_PIN D4

const int gasThreshold = 320;
const float temperatureThreshold = 30.0;

// Setup and loop code...
