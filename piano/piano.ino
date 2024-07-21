int btn1 = 3;
int btn2 = 4;
int btn3 = 5;
int btn4 = 6;
int btn5 = 7;
int buzzer = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);
  pinMode(btn4, INPUT);
  pinMode(btn5, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int b1 = digitalRead(btn1);
  int b2 = digitalRead(btn2);
  int b3 = digitalRead(btn3);
  int b4 = digitalRead(btn4);
  int b5 = digitalRead(btn5);

  if(b1 == 1){
    tone(buzzer, 300, 100);
  }
  if(b2 == 1){
    tone(buzzer, 400, 100);
  }
  if(b3 == 1){
    tone(buzzer, 500, 100);
  }
  if(b4 == 1){
    tone(buzzer, 600, 100);
  }
  if(b5 == 1){
    tone(buzzer, 700, 100);
  }

  delay(15);
}
