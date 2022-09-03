int myVoltPin=A2;
int readVal;
float V2;
int redPin = 9;
int ledVal;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode (myVoltPin, INPUT);
pinMode (redPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  readVal = analogRead(myVoltPin);
  ledVal = (255./1023.)*readVal;
  Serial.println(ledVal);
  analogWrite(redPin,ledVal);
  
  
}
