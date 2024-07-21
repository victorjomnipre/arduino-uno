#include<Servo.h>

Servo myServo;
const int x = A0;
const int y = A1;
const int servoTrig = 9;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(servoTrig);
}

void loop() {
  // put your main code here, to run repeatedly:
  int xValue = analogRead(x);
  int yValue = analogRead(y);

  int servoX_angle = map(xValue, 0, 1023, 0, 180);
  int servoY_angle = map(yValue, 0, 1023, 0, 180);

  myServo.write(servoY_angle);
  delay(15);
}
