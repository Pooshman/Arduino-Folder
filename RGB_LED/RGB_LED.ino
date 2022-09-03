int bluePin = 11;
int redPin = 7;
int greenPin = 2;
int dt = 250;
String myColor;
void setup() {
  // put your setup code here, to run once:
    Serial.begin(2000000);
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
}

void loop() {
  Serial.println("Choose color");
  //while (Serial.available() == 0) {}
  //myColor = Serial.readString();
  //if (myColor == "yellow") {
 
  analogWrite(redPin, 255);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 255);
  
  //}

}
