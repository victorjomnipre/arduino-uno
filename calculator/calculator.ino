#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

long first = 0;
long second = 0;
double total = 0;

char customKey;
char operatorChar = '\0';
bool isSecondNumber = false;

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','*'},
  {'C','0','=','/'}
};
byte rowPins[ROWS] = {4, 5, 6, 7}; // connect to the row pinouts of the keypad
byte colPins[COLS] = {0, 1, 2, 3}; // connect to the column pinouts of the keypad

// Initialize an instance of class NewKeypad
Keypad customKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS); 

void setup() {
  lcd.init(); // initialize the lcd
  lcd.backlight(); // turn on the backlight

  lcd.setCursor(0, 0);
  lcd.print("Calculator");
  lcd.setCursor(0, 1);
  lcd.print("by Shahmir Ahmed");
  delay(4000);
  lcd.clear();
  lcd.setCursor(0, 0);
}

void loop() {
  customKey = customKeypad.getKey();
  if (customKey) {
    if (customKey >= '0' && customKey <= '9') {
      if (!isSecondNumber) {
        first = first * 10 + (customKey - '0');
      } else {
        second = second * 10 + (customKey - '0');
      }
      displayCurrentOperation();
    } else if (customKey == '+' || customKey == '-' || customKey == '*' || customKey == '/') {
      if (operatorChar == '\0') {
        operatorChar = customKey;
        isSecondNumber = true;
      }
      displayCurrentOperation();
    } else if (customKey == '=') {
      calculateResult();
      displayResult();
    } else if (customKey == 'C') {
      resetCalculator();
    }
  }
}

void displayCurrentOperation() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(first);
  if (operatorChar != '\0') {
    lcd.print(" ");
    lcd.print(operatorChar);
    lcd.print(" ");
    lcd.print(second);
  }
}

void displayResult() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(first);
  lcd.print(" ");
  lcd.print(operatorChar);
  lcd.print(" ");
  lcd.print(second);
  lcd.print(" = ");
  lcd.print(total);
}

void calculateResult() {
  switch (operatorChar) {
    case '+':
      total = first + second;
      break;
    case '-':
      total = first - second;
      break;
    case '*':
      total = first * second;
      break;
    case '/':
      if (second == 0) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Invalid Operation");
        delay(2000);
        resetCalculator();
        return;
      }
      total = (float)first / (float)second;
      break;
  }
  first = 0;
  second = 0;
  operatorChar = '\0';
  isSecondNumber = false;
}

void resetCalculator() {
  first = 0;
  second = 0;
  total = 0;
  operatorChar = '\0';
  isSecondNumber = false;
  lcd.clear();
}
