#include "DHT.h"
#include "Servo.h"

// Define the pin for the DHT sensor
#define DHTPIN 2
#define DHTTYPE DHT11
bool keepTurning = false; // Flag to control servo movement

Servo monServo;
DHT dht(DHTPIN, DHTTYPE);

int position = 0;             // Current servo position
int direction = 1;            // Direction of movement: 1 for forward, -1 for backward
unsigned long lastMoveTime = 0; // Last time the servo was moved
const int moveInterval = 15;   // Time interval between servo steps

void setup() {
  Serial.begin(9600);
  monServo.attach(6);
  dht.begin();
}

void loop() {
  if (Serial.available() > 0) {
    char input = Serial.read();
    Serial.println(input); // Echo input for debugging

    if (input == '1') {
      Serial.println(String(dht.readTemperature()));
    } 
    else if (input == '3') {
      keepTurning = false; // Stop servo movement
    } 
    else if (input == '2') {
      keepTurning = true; // Allow servo movement
    }
  }

  if (keepTurning) {
    moveServoNonBlocking();
  }
}

void moveServoNonBlocking() {
  unsigned long currentTime = millis();

  if (currentTime - lastMoveTime >= moveInterval) {
    lastMoveTime = currentTime;

    monServo.write(position);
    position += direction;

    if (position >= 180 || position <= 0) {
      direction = -direction; // Reverse direction at limits
    }
  }
}
