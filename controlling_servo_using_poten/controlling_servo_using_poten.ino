#include<Servo.h>

Servo myservo;
int potentiometerPin = A1;
int value;
void setup() {
  // put your setup code here, to run once:
  myservo.attach(9);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  value = analogRead(potentiometerPin);
  value = map(value, 0, 1023, 0, 180);
  myservo.write(value);
  delay(15);
}
