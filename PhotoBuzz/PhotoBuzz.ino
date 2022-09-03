int lightPin = A5;
int buzzPin = 2;
int lightVal;
int delayVal;
void setup() {
  // put your setup code here, to run once:
  pinMode(lightPin, INPUT);
  pinMode(buzzPin, OUTPUT);
  Serial.begin(2000000);
}

void loop() {
  // put your main code here, to run repeatedly:
  lightVal = analogRead(lightPin);
  //Serial.println(lightVal);
  delayVal = (9./665.)*lightVal-((9.*45.)/665.)+1;
  Serial.println(delayVal);
  digitalWrite(buzzPin, HIGH);
  delay(delayVal);
  digitalWrite(buzzPin, LOW);
  delay(delayVal);
}
