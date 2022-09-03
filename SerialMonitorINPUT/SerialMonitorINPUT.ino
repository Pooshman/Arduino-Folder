int myNum;
void setup() {
  // put your setup code here, to run once:
Serial.begin(2000000);
}

void loop() {
  Serial.println("Enter number: ");
  while (Serial.available() == 0){}
  myNum = Serial.parseInt();
  Serial.println(myNum);
  // put your main code here, to run repeatedly:

}
