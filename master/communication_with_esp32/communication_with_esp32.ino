
void setup() {
  //wait untill connection between board and teensy is established
  while(!Serial && millis() < 1000){};
  Serial.println("Serial monitor started succesfully");
}

void loop() {
  if (Serial.available() > 0)
  {
    
  }
  
}
