int readPin = 2;
int dt = 100;
int ledPin = 9;
int buttonNew;
int buttonOld=0;
int ledState=0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(2000000);
pinMode(ledPin, OUTPUT);
pinMode(readPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonNew = digitalRead(readPin);
  if (buttonNew==1 && buttonOld==0) {
    if (ledState==0) {digitalWrite(ledPin, HIGH); ledState=1;}
    else {digitalWrite(ledPin, LOW); ledState=0;}
    }
  buttonOld=buttonNew;
  delay(dt);
  
}
