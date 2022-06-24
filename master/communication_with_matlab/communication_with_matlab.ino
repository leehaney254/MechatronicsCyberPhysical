String message;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()>0)
  {
    message = Serial.readStringUntil("/n");
    Serial.print("I have recieved message : ");
    Serial.print(message);
  }
}
