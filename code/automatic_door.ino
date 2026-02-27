/*
  Project: Dual-Level IoT Smart Home Automation
  Module: Automatic Door System
  Board: Arduino Uno
*/

const int irSensorPin = 8;
const int motorPin1   = 3;
const int motorPin2   = 4;

void setup() {
  pinMode(irSensorPin, INPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);

  Serial.begin(9600);
  Serial.println("Automatic Door System Initialized");
}

void loop() {

  int sensorValue = digitalRead(irSensorPin);

  if (sensorValue == LOW) {   // Person detected
    Serial.println("Object Detected - Opening Door");

    // Open Door
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    delay(2900);

    // Stop
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    delay(3000);

    Serial.println("Closing Door");

    // Close Door
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    delay(2900);

    // Stop
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    delay(3000);
  }
  else {
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
  }
}