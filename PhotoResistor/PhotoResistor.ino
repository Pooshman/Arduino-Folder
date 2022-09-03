int lightPin = A0;
double lightVal;
int greenPin = 5;
int redPin = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(lightPin, INPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  Serial.begin(2000000);
}

void loop() {
  // put your main code here, to run repeatedly:
  lightVal = (5./1023.)*analogRead(lightPin);
  Serial.println(lightVal);
  
  while (lightVal>3.0) {digitalWrite(greenPin, HIGH);
  Serial.println(lightVal);
  lightVal = (5./1023.)*analogRead(lightPin);
}
  while (lightVal<1.0) {digitalWrite(redPin, HIGH);
  Serial.println(lightVal);
  lightVal = (5./1023.)*analogRead(lightPin);
  }
  digitalWrite(greenPin, LOW);
  digitalWrite(redPin, LOW);
  
}
