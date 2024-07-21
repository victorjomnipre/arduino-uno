#include <Servo.h> // Servo library

Servo sg90;
int echo = 7;
int trig = 6;
int servopin = 8;
int distance;
int duration;
bool isTriggered = false;

void setup() {
  sg90.attach(servopin);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600); // Initialize serial communication at 9600 bits per second
  sg90.write(0); // Ensure servo starts at 0 degrees
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  distance = duration * 0.15 / 2;

  if (distance < 30 && !isTriggered) {
    sg90.write(180); // Rotate servo to 90 degrees
    delay(2000); // Wait for 4 seconds
    sg90.write(0); // Return servo to 0 degrees
    Serial.print("Object detected at distance: ");
    Serial.println(distance);
    isTriggered = true; // Set the state to triggered
  } else if (distance >= 30) {
    isTriggered = false; // Reset the state if no object is detected
  }

  delay(50); // Small delay to avoid overloading the sensor
}
