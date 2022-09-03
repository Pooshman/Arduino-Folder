 int ledPin = 7;
 int buttonUp=2;
 int buttonDown=5;
 int upVal;
 int downVal;
 int analogVal=0;
 int dt=50;
 int stepVal= 5;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(2000000);
  pinMode(buttonUp, INPUT);
  pinMode(buttonDown, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  upVal = digitalRead(buttonUp);
  downVal = digitalRead(buttonDown);
  Serial.print("Up Button: ");
  Serial.print(upVal);
  Serial.print(", Down Button: ");
  Serial.print(downVal);
  Serial.print(", Analog Value: ");
  Serial.println(analogVal);
  delay(dt);
  if (upVal==0 && downVal == 1) {if (analogVal<255) {analogVal +=stepVal;analogWrite(ledPin, analogVal);}}
  if (upVal==1 && downVal == 0) {if (analogVal>0) {analogVal -=stepVal;analogWrite(ledPin, analogVal);}}
  
  
}
