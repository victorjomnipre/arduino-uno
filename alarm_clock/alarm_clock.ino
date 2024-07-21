#include <LiquidCrystal_I2C.h>
#include <ThreeWire.h>
#include <RtcDS1302.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
ThreeWire myWire(7, 6, 8);
RtcDS1302<ThreeWire> Rtc(myWire);

const int buzzer = 10;
const int led = 9;


void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
  lcd.clear();

  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);

  Rtc.Begin();
  //RtcDateTime currentTime = RtcDateTime(__DATE__ , __TIME__);
  //Rtc.SetDateTime(currentTime);

}

void loop() {
  // put your main code here, to run repeatedly:
  RtcDateTime now = Rtc.GetDateTime();
  lcd.clear();

    // Display Date
  lcd.setCursor(0, 0);
  lcd.print("Date: ");
  lcd.print(now.Day());
  lcd.print("/");
  lcd.print(now.Month());
  lcd.print("/");
  lcd.print(now.Year());

  // Display Time
  lcd.setCursor(0, 1);
  lcd.print("Time: ");
  lcd.print(now.Hour());
  lcd.print(":");
  lcd.print(now.Minute());
  lcd.print(":");
  lcd.print(now.Second());

  if(now.Hour() == 21 && now.Minute() == 10){
    alarm();
  }
  if(now.Hour() == 21 && now.Minute() == 20){
    alarm();
  }
  if(now.Hour() == 21 && now.Minute() == 30){
    alarm();
  }
  delay(1000);
}

void alarm(){
  digitalWrite(buzzer, HIGH);
  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(buzzer, LOW);
  digitalWrite(led, LOW);
}
