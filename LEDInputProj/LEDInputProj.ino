int bluePin = 2;
int greenPin = 5;
int redPin = 10;
String pinChoice;
int numBlinks;
int delayTime = 250;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(2000000);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
}

void loop() {
  Serial.println("Enter pin choice (red,green,blue followed by pin ex.redPin): ");
  while (Serial.available() == 0) {}
  pinChoice = Serial.readString();
  Serial.println("Enter number of blinks: ");
  while (Serial.available() == 0) {}
  numBlinks = Serial.parseInt();
  if (pinChoice == "redPin") {
  for (int i=0; i<numBlinks; ++i) {
    digitalWrite(redPin, HIGH);
    delay(delayTime);
    digitalWrite(redPin, LOW);
    delay(delayTime);
  }}
  else if (pinChoice == "greenPin") {
    for (int i=0; i<numBlinks; ++i) {
    digitalWrite(greenPin, HIGH);
    delay(delayTime);
    digitalWrite(greenPin, LOW);
    delay(delayTime);
    }}
  else if (pinChoice == "bluePin") {
    for (int i=0; i<numBlinks; ++i) {
    digitalWrite(bluePin, HIGH);
    delay(delayTime);
    digitalWrite(bluePin, LOW);
    delay(delayTime);}}}
