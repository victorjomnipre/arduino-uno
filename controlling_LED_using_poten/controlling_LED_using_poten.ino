const int ledPin = 9;
const int potenAnalogPin = A0;
int potenValue, ledValue;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  potenValue = analogRead(potenAnalogPin);
  ledValue = map(potenValue, 0, 1023, 0, 255);
  analogWrite(ledPin, ledValue);

  Serial.print("Potentiometer value: ");
  Serial.println(potenValue);
  Serial.print(" | LED value: ");
  Serial.println(ledValue);
}
