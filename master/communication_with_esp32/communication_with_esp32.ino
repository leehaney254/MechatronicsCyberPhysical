
void setup() {
  //wait untill connection between board and teensy is established
//  while(!Serial && millis() < 1000){};
//  Serial.println("Serial monitor started succesfully");
    Serial1.begin(115200);
}

void loop() {
  Serial1.println("Hope you recieve this");
  delay(1000);
  
}
