int led1 = 8;
int led2 = 9;
int led3 = 10;
int fade = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  fade = 1000;
  digitalWrite(led1, HIGH);
  delay(fade);
  digitalWrite(led1, LOW);
  delay(fade);
  digitalWrite(led2, HIGH);
  delay(fade);
  digitalWrite(led2, LOW);
  delay(fade);
  digitalWrite(led3, HIGH);
  delay(fade);
  digitalWrite(led3, LOW);
  delay(fade);
}
