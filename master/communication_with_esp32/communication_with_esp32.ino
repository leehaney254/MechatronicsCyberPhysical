#include <SoftwareSerial.h>

const byte rxPin = 2;
const byte txPin = 3;

// Set up a new SoftwareSerial object
SoftwareSerial mySerial (rxPin, txPin);

void setup() {
    mySerial.begin(115200);
}

void loop() {
  mySerial.println("Hope you recieve this");
  delay(1000);
  
}
