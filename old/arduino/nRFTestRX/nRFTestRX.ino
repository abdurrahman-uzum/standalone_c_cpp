#include <Enrf24.h>
#include <nRF24L01.h>
#include <string.h> // atoi() 
#include <SPI.h>

Enrf24 nRF(4, 10, 2);  // CE , CSN/CS/SS , IRQ 

const byte address1[] = { 0xDE, 0xAD, 0xBE, 0x0F, 0x01 };  //0xDE, 0xAD, 0xBE, 0x0F, 0x01
char data1[33];



  
void setup() 
{
  SPI.begin(); // SPI başlat
  SPI.setDataMode(SPI_MODE0); 
  SPI.setBitOrder(MSBFIRST); 

  // datarate 250000/1000000/2000000, channel 0/125
  nRF.begin(1000000,125); 

  
  nRF.enableRX();  // Dinlemeye başla

  Serial.begin(9600);
}

void loop()
{
 nRF.setRXaddress(address1);
 nRF.read(data1);
 Serial.println(data1);

    
  
}
