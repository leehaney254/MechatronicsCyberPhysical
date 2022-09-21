/*
 * spi communication with stm32 as master
 * ss   D10
 * clock  D13
 * miso   D12
 * mosi   D11
 * clock 8bytes/sec
 */

 //include spi file
 #include <SPI.h>
 
 //define variables
 #define MISO 12
 volatile unsigned int recievedMessae;

void setup() {
  // put your setup code here, to run once:
  pinMode(MISO,OUTPUT);
  //turn on spi in slave mode
  SPCR |= _BV(SPE);
  //read spi as interrupts
  SPI.attachInterrupt();
}

void loop() {
  // put your main code here, to run repeatedly:

}
