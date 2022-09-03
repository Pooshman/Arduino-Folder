int buzzPin = 5;
void setup() {
  // put your setup code here, to run once:
  pinMode(buzzPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(buzzPin, HIGH);
  delay(1);
  digitalWrite(buzzPin, LOW);
  delay(1);
}
