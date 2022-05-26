#include <Enrf24.h>
#include <nRF24L01.h>
#include <string.h> // atoi() 
#include <SPI.h>

Enrf24 nRF(4, 10, 2);  // CE , CSN/CS/SS , IRQ 

const byte address1[] = { 0xDE, 0xAD, 0xBE, 0x0F, 0x01 };  //0xDE, 0xAD, 0xBE, 0x0F, 0x01

const byte address5[] = { 0xDE, 0xAD, 0xBE, 0x0F, 0x05 };

const byte address7[] = { 0xDE, 0xAD, 0xBE, 0x0F, 0x07 };
const byte address8[] = { 0xDE, 0xAD, 0xBE, 0x0F, 0x08 };


 char data1[33];
 char data5[33];
 char data7[33]; 



 int intData1;
 int intData5;
 int intData7;

  

  
  int j1x;


  int j2y;

  
  int pot1;

  
  bool b1;
  bool b2;
  bool b3;
  bool b4;
  bool b5;
  bool b6;

  bool tgs1;

  char buttons[7];

  
void setup() 
{
  SPI.begin(); // SPI başlat
  SPI.setDataMode(SPI_MODE0); 
  SPI.setBitOrder(MSBFIRST); 

  // datarate 250000/1000000/2000000, channel 0/125
  nRF.begin(1000000,124); 

  
  nRF.enableRX();  // Dinlemeye başla

  Serial.begin(9600);
}

void loop()
{
 

    nRF.setRXaddress(address1);
      if(nRF.read(data1))
      {
        intData1 = atoi(data1);
        j1x = map(intData1, 0, 1024, -128, 128);


        delay(10);
        
      }


    nRF.setRXaddress(address5);
      if(nRF.read(data5))
      {
        intData5 = atoi(data5);
        j2y = map(intData5, 0, 1023, -128, 128);

        delay(10);
        
      }


      nRF.setRXaddress(address7);
      if(nRF.read(data7))
      {
        intData7 = atoi(data7);
        pot1 = map(intData7, 0, 1023, 0, 256);

        delay(10);
        
      }

      /*nRF.setRXaddress(address8);
      if(nRF.read(buttons))
      {
        delay(10);
        
      }*/

   
      


  Serial.print("Joystick 1: ");
  Serial.print(j1x);

  Serial.println("-----------------------------------------------------");

  Serial.print("Joystick 2: ");
  Serial.print(j2y);

  Serial.println("-----------------------------------------------------");

  Serial.print("Pot1: ");
  Serial.println(pot1);

  Serial.println("-----------------------------------------------------");

  /*Serial.print("Buttons: ");
  Serial.println(buttons);
*/
  Serial.println("-----------------------------------------------------");
  Serial.println("-----------------------------------------------------");

 

      
        
      
    







    
  
}
