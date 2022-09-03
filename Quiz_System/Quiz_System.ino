#define button1 6
#define button2 8
#define button3 12
#define button4 2
#define buzzerPin 4
#define LED1 7
#define LED2 9
#define LED3 13
#define LED4 3
#define uint unsigned char
uint flag = 0;
uint b1State, b2State, b3State, b4State = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode (buzzerPin, OUTPUT);
  pinMode (LED1, OUTPUT);
  pinMode (LED2, OUTPUT);
  pinMode (LED3, OUTPUT);
  pinMode (LED4, OUTPUT);

  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);

  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);

  b4State = digitalRead(button4);

  if (b4State == 0) {
    if (b4State == 0) {
      flag = 1;
      digitalWrite(LED4, HIGH);
      delay(200);
    }
  }
  if (1 == flag) {
    b1State = digitalRead(button1);
    b2State = digitalRead(button2);
    b3State = digitalRead(button3);

    if (b1State == 0) {
      flag = 0;
      digitalWrite(LED4, LOW);
      Alarm();
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      while(digitalRead(button4));
    }
    if (b2State == 0) {
      flag = 0;
      digitalWrite(LED4, LOW);
      Alarm();
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, LOW);
      while(digitalRead(button4));
    }
    if (b3State == 0) {
      flag = 0;
      digitalWrite(LED4, LOW);
      Alarm();
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, HIGH);
      while(digitalRead(button4));
    }
  }
}

void Alarm() {
  for (int i=0;i<100;i++) {
    digitalWrite (buzzerPin, HIGH);
    delay(2);
    digitalWrite(buzzerPin, LOW);
    delay(2); 
  }
}
