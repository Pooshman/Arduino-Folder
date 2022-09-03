int sPin = 50;
int xPin = A0;
int yPin = A1;
int xVal;
int yVal;
int sVal;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(xPin, INPUT);
pinMode(xPin, INPUT);
pinMode(sPin, INPUT);
digitalWrite(sPin, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
  xVal = analogRead(xPin);
  yVal = analogRead(yPin);
  sVal = digitalRead(sPin);
  Serial.print("X: ");
  Serial.print(xVal);
  Serial.print(" Y: ");
  Serial.print(yVal);
  Serial.print(" Switch: ");
  Serial.println(sVal);
  delay(200);
}
