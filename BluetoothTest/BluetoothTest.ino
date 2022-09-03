char incomingVal = 0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(13, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
if (Serial.available()>0){
  
  incomingVal = Serial.read();
  Serial.println(incomingVal);
  if (incomingVal == '1') {
    Serial.println("success");
    digitalWrite(13, HIGH);
   }
  else if (incomingVal == '0') {
  digitalWrite(13, LOW);
  }

}
}
