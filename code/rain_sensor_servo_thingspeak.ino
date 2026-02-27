/*
  Project: Dual-Level IoT Smart Home Automation
  Module: Rain Detection with Servo & ThingSpeak
  Board: ESP32
*/

#include <ESP32Servo.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>

WiFiClient client;
Servo myServo;

// ===== WiFi Credentials =====
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

// ===== ThingSpeak =====
unsigned long myChannelNumber = 3048154;
const char* myWriteAPIKey = "YOUR_WRITE_API_KEY";

// ===== Pin Configuration =====
const int rainDigitalPin = 2;
const int rainAnalogPin  = 34;
const int servoPin       = 13;

// ===== Servo Control Pulses =====
int stopPulse     = 1500;
int forwardPulse  = 1700;
int backwardPulse = 1300;

// ===== Settings =====
const int moveTime = 8000;
const int rainThreshold = 1500;

bool isInside = false;

void setup() {
  Serial.begin(115200);

  pinMode(rainDigitalPin, INPUT);
  myServo.attach(servoPin);
  myServo.writeMicroseconds(stopPulse);

  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi Connected");
  ThingSpeak.begin(client);
}

void loop() {

  int digitalValue = digitalRead(rainDigitalPin);
  int analogValue  = analogRead(rainAnalogPin);

  Serial.print("Analog Value: ");
  Serial.println(analogValue);

  bool isRaining = (analogValue < rainThreshold);

  if (isRaining && !isInside) {

    Serial.println("Rain Detected! Moving Protection System...");

    ThingSpeak.setField(1, analogValue);
    ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);

    myServo.writeMicroseconds(forwardPulse);
    delay(moveTime);
    myServo.writeMicroseconds(stopPulse);

    isInside = true;
  }
  else if (!isRaining && isInside) {

    Serial.println("Rain Stopped! Resetting System...");

    myServo.writeMicroseconds(backwardPulse);
    delay(moveTime);
    myServo.writeMicroseconds(stopPulse);

    isInside = false;
  }

  delay(300);
}