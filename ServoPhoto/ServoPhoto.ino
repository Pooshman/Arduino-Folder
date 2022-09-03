#include <Servo.h>
int servoPin = 9;
int servoPos;
Servo Poosh;
int photoPin = A0;
int lightVal;


void setup() {
  // put your setup code here, to run once:
pinMode(photoPin, INPUT);
Serial.begin(9600);
Poosh.attach(servoPin);

}

void loop() {
  // put your main code here, to run repeatedly:
lightVal = analogRead(photoPin);
Serial.println(lightVal);
delay(200);
servoPos = ((-0.3)*(lightVal)+187.5);
Poosh.write(servoPos);
}
