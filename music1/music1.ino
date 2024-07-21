#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void fadeOutPreviousLine() {
  for (int i = 0; i < 16; ++i) {
    lcd.setCursor(i, 1);
    lcd.print(" ");
    delay(10);
  }
}

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" 'Wag mag taka");
  delay(2000);
  fadeOutPreviousLine();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" kung ako ay");
  delay(1800);
  fadeOutPreviousLine();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" 'di nahihintay");
  delay(3700);
  fadeOutPreviousLine();
  lcd.clear();
  lcd.setCursor(0, 0); 
  lcd.print(" sa ano mang");
  delay(2100);
  fadeOutPreviousLine();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" kapalit");
  delay(1800);
  fadeOutPreviousLine();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" ng inalay");
  delay(1400);
  fadeOutPreviousLine();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" kong pag-ibig");
  delay(3000);
  
  fadeOutPreviousLine();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" kulang man ang");
  delay(2500);
  fadeOutPreviousLine();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" 'yong pagtingin");
  delay(3500);
  fadeOutPreviousLine();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("'Ang lahat sa");
  delay(2300);
  fadeOutPreviousLine();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" 'yo'y ibibigay");
  delay(2500);
  fadeOutPreviousLine();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" kahit'di mo");
  delay(2000);
  fadeOutPreviousLine();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" pinapansin");
  delay(3000);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" Huwag mangamba");
  delay(2200);
  fadeOutPreviousLine();
  lcd.clear();
  fadeOutPreviousLine();
  lcd.setCursor(0, 0);
  lcd.print(" hindi kita");
  delay(1600);
  fadeOutPreviousLine();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" paghahanapan pa");
  delay(3400);
  fadeOutPreviousLine();
  lcd.clear();
  lcd.setCursor(0, 0); 
  lcd.print(" Ng anumang");
  delay(2100);
  fadeOutPreviousLine();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" kapalit");
  delay(1900);
  fadeOutPreviousLine();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" ng inalay");
  delay(1500);
  fadeOutPreviousLine();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" kong pag-ibig");
  delay(3000);
}
