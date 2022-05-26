#include <Enrf24.h>
#include <nRF24L01.h>
#include <SPI.h>

Enrf24 nRF(4, 10, 2);  // CE , CSN/CS/SS , IRQ 


const byte address1[] = { 0xDE, 0xAD, 0xBE, 0x0F, 0x01 };  //0xDE, 0xAD, 0xBE, 0x0F, 0x01

const byte address5[] = { 0xDE, 0xAD, 0xBE, 0x0F, 0x05 };

const byte address7[] = { 0xDE, 0xAD, 0xBE, 0x0F, 0x07 };
const byte address8[] = { 0xDE, 0xAD, 0xBE, 0x0F, 0x08 };



void setup() 
{
  

  SPI.begin();
  SPI.setDataMode(SPI_MODE0); 
  SPI.setBitOrder(MSBFIRST); 
  
  // datarate 250000/1000000/2000000, channel 0/125
  
  nRF.begin(1000000,124);  

  pinMode(0, INPUT);
  pinMode(1, INPUT);
  pinMode(3, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);

}


void loop() 
{
  nRF.setTXaddress(address1);
  nRF.print("Selam");
  nRF.flush();







  
}
