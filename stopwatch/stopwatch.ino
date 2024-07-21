#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
const int startBtn = 2;
const int stopBtn = 3;
const int resetBtn = 4;
const int startLED = 9;
const int stopLED = 10;
const int resetLED = 11;

bool isRunning = false;
unsigned long startTime = 0;
unsigned long elapsedTime = 0;

void setup() {
  lcd.init();
  lcd.backlight();

  pinMode(startBtn, INPUT_PULLUP);
  pinMode(stopBtn, INPUT_PULLUP);
  pinMode(resetBtn, INPUT_PULLUP);

  pinMode(startLED, OUTPUT);
  pinMode(stopLED, OUTPUT);
  pinMode(resetLED, OUTPUT);

  lcd.setCursor(0, 0);
  lcd.print("   Stopwatch");
  lcd.setCursor(0, 1);
  lcd.print("  00:00:00:00");
}

void loop() {
  if (digitalRead(startBtn) == LOW) {
    if (!isRunning) {
      startTime = millis() - elapsedTime;
      isRunning = true;
      digitalWrite(startLED, HIGH);
      digitalWrite(stopLED, LOW);
      digitalWrite(resetLED, LOW);
    }
    delay(200); // Added debounce delay for start button
  }

  if (digitalRead(stopBtn) == LOW) {
    if (isRunning) {
      elapsedTime = millis() - startTime;
      isRunning = false;
      digitalWrite(startLED, LOW);
      digitalWrite(stopLED, HIGH);
      digitalWrite(resetLED, LOW);
    }
    delay(200); // Added debounce delay for stop button
  }

  if (digitalRead(resetBtn) == LOW) {
    elapsedTime = 0;
    isRunning = false;
    lcd.setCursor(0, 1);
    lcd.print("  00:00:00:00");
    digitalWrite(startLED, LOW);
    digitalWrite(stopLED, LOW);
    digitalWrite(resetLED, HIGH);
    delay(200); // Added debounce delay for reset button
  }

  if (isRunning) {
    update();
  }
}

void update() {
  unsigned long currentTime = millis();
  elapsedTime = currentTime - startTime;

  int hours = ((elapsedTime / 1000) / (60 * 60));
  int minutes = ((elapsedTime / 1000) % (60 * 60)) / 60;
  int seconds = (elapsedTime / 1000) % 60;
  int milliseconds = (elapsedTime % 1000) / 10;

  // Only update the parts of the display that change
  lcd.setCursor(0, 1);
  lcd.print("  ");
  lcd.print(hours < 10 ? "0" : "");
  lcd.print(hours);
  lcd.print(":");
  lcd.print(minutes < 10 ? "0" : "");
  lcd.print(minutes);
  lcd.print(":");
  lcd.print(seconds < 10 ? "0" : "");
  lcd.print(seconds);
  lcd.print(":");
  lcd.print(milliseconds);
}
