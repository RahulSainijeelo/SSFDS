#define BLYNK_TEMPLATE_ID "TMPL332Z8HKpW"
#define BLYNK_TEMPLATE_NAME "Smart Smoke and Fire Detection System"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

// Blynk configuration
#define BLYNK_AUTH_TOKEN "79j7KqxhoE17zSS-XAF6qP31gUK4Rz7A"

// Wi-Fi credentials
const char* ssid = "OPPO K10";  // Replace with your Wi-Fi SSID
const char* password = "Rahul@1225";  // Replace with your Wi-Fi password

// DHT Configuration
#define DHTPIN D2      // DHT sensor pin
#define DHTTYPE DHT11  // DHT11 or DHT22
DHT dht(DHTPIN, DHTTYPE);

// Sensor Pins
#define MQ6_PIN A0     // MQ-6 analog pin
#define BUZZER_PIN D3  // Buzzer
#define LED_PIN D4     // LED (Red)

// Thresholds
const int gasThreshold = 320;             // Adjust based on sensor calibration
const float temperatureThreshold = 30.0;  // Adjust for temperature alert

void setup() {
  Serial.begin(115200);
  dht.begin();

  // Initialize Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, password);

  // Sensor and Actuator Pin Modes
  pinMode(MQ6_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  Serial.println("System started. Monitoring smoke, temperature, and humidity.");
}

void loop() {
  Blynk.run();  // Run Blynk

  // Read sensors
  int gasLevel = analogRead(MQ6_PIN);
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  if (isnan(temp) || isnan(hum)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Display sensor values in the serial monitor
  Serial.print("Gas Level (MQ-6): ");
  Serial.println(gasLevel);
  Serial.print("Temperature: ");
  Serial.println(temp);
  Serial.print("Humidity: ");
  Serial.println(hum);

  // Upload sensor data to Blynk
  Blynk.virtualWrite(V0, temp);       // Temperature on V0
  Blynk.virtualWrite(V1, hum);        // Humidity on V1
  Blynk.virtualWrite(V2, gasLevel);   // Gas Level on V2

  // Check gas and temperature thresholds
  bool danger = false;
  if (gasLevel > gasThreshold || temp > temperatureThreshold) {
    danger = true;
    digitalWrite(BUZZER_PIN, HIGH);  // Activate Buzzer
    digitalWrite(LED_PIN, HIGH);     // Turn on LED
    Serial.println("Warning! Gas or high temperature detected!");

    // Trigger a notification through Blynk
    Blynk.logEvent("fire_detected");
    Blynk.virtualWrite(V3, 1);  // Set V3 high to trigger notification via Blynk Automation
  } else {
    digitalWrite(BUZZER_PIN, LOW);  // Deactivate Buzzer
    digitalWrite(LED_PIN, LOW);     // Turn off LED
    Blynk.virtualWrite(V3, 0);      // Reset V3
  }

  delay(2000);  // Delay for readability and lower power consumption
}
