#include <Enrf24.h>
#include <nRF24L01.h>
#include <SPI.h>

Enrf24 nRF(4, 10, 2);  // CE , CSN/CS/SS , IRQ 


const byte address1[] = { 0xDE, 0xAD, 0xBE, 0x0F, 0x01 };  //0xDE, 0xAD, 0xBE, 0x0F, 0x01






void setup() 
{
  

  SPI.begin();
  SPI.setDataMode(SPI_MODE0); 
  SPI.setBitOrder(MSBFIRST); 
  
  // datarate 250000/1000000/2000000, channel 0/125
  
  nRF.begin(1000000,125);  

  

}


void loop() 
{
  
  int j1x = map(analogRead(A2), 0, 1023, 100, 999); // mid: 538


  int j2y = map(analogRead(A6), 0, 1023, 100, 999); // mid: 536/7
  

  int pot1 = map(analogRead(A3), 0, 1023, 100, 999);

  bool b1 = digitalRead(3);
  bool b2 = digitalRead(5);
  bool b3 = digitalRead(6);
  bool b4 = digitalRead(7);
  bool b5 = digitalRead(8);
  bool b6 = digitalRead(9);
  bool tgs1 = digitalRead(0);

  char buttons [7];
  if (b1) { buttons[0] = '1'; }
  if (!b1) { buttons[0] = '0'; }
  if (b2) { buttons[1] = '1'; }
  if (!b2) { buttons[1] = '0'; }
  if (b3) { buttons[2] = '1'; }
  if (!b3) { buttons[2] = '0'; }
  if (b4) { buttons[3] = '1'; }
  if (!b4) { buttons[3] = '0'; }
  if (b5) { buttons[4] = '1'; }
  if (!b5) { buttons[4] = '0'; }
  if (b6) { buttons[5] = '1'; }
  if (!b6) { buttons[5] = '0'; }
  if (tgs1) { buttons[6] = '1'; }
  if (!tgs1) { buttons[6] = '0'; }

 

  
  nRF.setTXaddress(address1);
  nRF.print(j1x);
  nRF.print(j2y);
  nRF.print(pot1);
  nRF.print(buttons);
  nRF.flush();
  

  
  



















  
}
