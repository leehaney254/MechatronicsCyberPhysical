#include <SPI.h>    //include spi library
float r, p, y;
int led = 7;
char sent[3]= {};
char *base, *shoulder, *elbow, *wristpitch, *wristroll;
char elbowSent[3] = {};
char readChar[20] = {};
int intShoulder;


void setup() {
  //Setting boud rate with teensy is not necessary as it communicates at max usb speed
  Serial.begin(115200);
  while(!Serial && millis()<1000){}                 //waits until connection is established with pc to begin serial printing
  digitalWrite(SS, HIGH); // disable Slave Select
//  //Spi configurations
  SPI.begin ();
  SPI.setClockDivider(SPI_CLOCK_DIV16);//divide the clock by 16
  SPI.beginTransaction(SPISettings(16000000, MSBFIRST, SPI_MODE3));
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //check if there is any serial data
  
  if(Serial.available())
  {

   //read the string
    String allAngles = Serial.readString();
    char allAnglesArrays[25];
   allAngles.toCharArray(allAnglesArrays,25);

  //splitt into sections
  const char *delimiter =",";

  //detokenize the angles
  base = strtok(allAnglesArrays,delimiter);
  shoulder = strtok(NULL,delimiter);
  elbow = strtok(NULL,delimiter);
  wristpitch = strtok(NULL,delimiter);
  wristroll= strtok(NULL,delimiter);

  sscanf(shoulder, "%3d", &intShoulder);


  //convert integer to char with an array of three
  sprintf(sent, "%03d", intShoulder);


  //send via spi
  digitalWrite(SS, LOW); // enable Slave Select

  SPI.transfer (sent[0]);
  SPI.transfer (sent[1]);
  SPI.transfer (sent[2]);
  digitalWrite(SS, HIGH); // disable Slave Select

//    Serial.println(base);
//    Serial.println(shoulder);
//    Serial.println(elbow);
//    Serial.println(wristpitch);
//    Serial.println(wristroll);
  }
  
}
