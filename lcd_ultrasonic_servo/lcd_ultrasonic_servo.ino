#include <Servo.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo sg90;

int servoTrig = 8;
int u_sonicEcho = 10;
int u_sonicTrig = 9;
float distance;
float duration;
bool isTriggered = false;

void setup() {
  // put your setup code here, to run once:
  sg90.attach(servoTrig);
  Serial.begin(9600);
  sg90.write(0);

  lcd.init();               
  lcd.backlight();
  lcd.clear();
  lcd.print("Hello...");

  pinMode(u_sonicTrig, OUTPUT); // config trigger pin to output mode
  pinMode(u_sonicEcho, INPUT);  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(u_sonicTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(u_sonicTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(u_sonicTrig, LOW);

  duration = pulseIn(u_sonicEcho, HIGH);
  distance = (duration * 0.0343) / 2;

  if(distance < 10 && !isTriggered) {
    lcd.clear();
    lcd.setCursor(0, 0);
    //lcd.print("   miss u na!");
    lcd.print("Object detected!!");

    lcd.setCursor(0, 1);
    //lcd.print("    regs <3");
    lcd.print("Distance: ");
    lcd.print(distance);
    lcd.print("cm");

    sg90.write(180);
    delay(3000);
    sg90.write(0);
    isTriggered = true;

  }
  else if(distance >= 21) {
    sg90.write(0);
    isTriggered = false;
  }
  delay(50);
}
