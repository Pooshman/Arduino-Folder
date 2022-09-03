int buzzPin = 5;
int voltPin = A5;
int potVal;
int toneVal;
void setup() {
  // put your setup code here, to run once:
pinMode(buzzPin, OUTPUT);
pinMode(voltPin, INPUT);
Serial.begin(2000000);
}

void loop() {
  potVal = analogRead(voltPin);
  toneVal = (9940./1023.)*potVal+60;
  digitalWrite(buzzPin, HIGH);
  delayMicroseconds(toneVal);
  digitalWrite(buzzPin, LOW);
  delayMicroseconds(toneVal);
}
