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
  char buttons[7];
  
  int j1x = analogRead(A1);


  int j2y = analogRead(A6);

  
  int pot1 = analogRead(A3);

  
  bool b1 = digitalRead(3);
  bool b2 = digitalRead(5);
  bool b3 = digitalRead(6);
  bool b4 = digitalRead(7);
  bool b5 = digitalRead(8);
  bool b6 = digitalRead(9);
  bool tgs1 = digitalRead(0);
  

  if (b1) { buttons[0] = 'A'; }
  if (!b1) { buttons[0] = 'B'; }

  if (b2) { buttons[1] = 'C'; }
  if (!b2) { buttons[1] = 'D'; }

  if (b3) { buttons[2] = 'E'; }
  if (!b3) { buttons[2] = 'F'; }

  if (b4) { buttons[3] = 'G'; }
  if (!b4) { buttons[3] = 'H'; }

  if (b5) { buttons[4] = 'I'; }
  if (!b5) { buttons[4] = 'J'; }

  if (b6) { buttons[5] = 'K'; }
  if (!b6) { buttons[6] = 'L'; }

  if (tgs1) { buttons[6] = 'M'; }
  if (!tgs1) { buttons[6] = 'N'; }

  
  nRF.setTXaddress(address1);
  nRF.print(j1x);
  nRF.flush();
  delay(10);

  nRF.setTXaddress(address5);
  nRF.print(j2y);
  nRF.flush();

  nRF.setTXaddress(address7);
  nRF.print(pot1);
  nRF.flush();

/*
  nRF.setTXaddress(address8);
  nRF.print(buttons);
  nRF.flush();
*/
  

  
  



















  
}
