String message;

void setup() {
  //Setting boud rate with teensy is not necessary as it communicates at max usb speed
  Serial.begin(115200);
  while(!Serial && millis()<1000){}                 //waits until connection is established with pc to begin serial printing
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()>0)
  {
    message = Serial.readStringUntil("/n");
    Serial.print("I have recieved message : ");
    Serial.println(message);
    SerialUSB1.print(message);
  }
  
}
