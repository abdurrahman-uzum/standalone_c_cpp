#include <Enrf24.h>
#include <nRF24L01.h>
#include <string.h> // atoi() 
#include <SPI.h>

Enrf24 nRF(3, 10, 2);  // CE , CSN/CS/SS , IRQ 

const byte address1[] = { 0xDE, 0xAD, 0xBE, 0x0F, 0x01 };  //0xDE, 0xAD, 0xBE, 0x0F, 0x01

 char data1[33];

 
  int j2x;
  int j1y;
  int pot1;

  char jx[4];
  char jy[4];
  char pot[4];

  bool b1;
  bool b2;
  bool b3;
  bool b4;
  bool b5;
  bool b6;
  bool tgs1;

  

  
void setup() 
{
  SPI.begin(); // SPI başlat
  SPI.setDataMode(SPI_MODE0); 
  SPI.setBitOrder(MSBFIRST); 

  // datarate 250000/1000000/2000000, channel 0/125
  nRF.begin(1000000,125); 

  
  nRF.enableRX();  // Dinlemeye başla

  Serial.begin(9600);

  nRF.setRXaddress(address1);
}



void loop()
{
  

    
      while(nRF.read(data1)) {
      

      

      jy[0] = data1[0];
      jy[1] = data1[1];
      jy[2] = data1[2];

      jx[0] = data1[3];
      jx[1] = data1[4];
      jx[2] = data1[5];

      pot[0] = data1[6];
      pot[1] = data1[7];
      pot[2] = data1[8];

      if(data1[9] == '1') { b1=true; }
      if(data1[9] == '0') { b1=false; }

      if(data1[10] == '1') { b2=true; }
      if(data1[10] == '0') { b2=false; }

      if(data1[11] == '1') { b3=true; }
      if(data1[11] == '0') { b3=false; }

      if(data1[12] == '1') { b4=true; }
      if(data1[12] == '0') { b4=false; }

      if(data1[13] == '1') { b5=true; }
      if(data1[13] == '0') { b5=false; }

      if(data1[14] == '1') { b6=true; }
      if(data1[14] == '0') { b6=false; }

      if(data1[15] == '1') { tgs1=true; }
      if(data1[15] == '0') { tgs1=false; }

      

      j2x = atoi(jx);
      j1y = atoi(jy);
      pot1 = atoi(pot);

      

      Serial.print(j1y);
      Serial.print(" / ");
      Serial.print(j2x);
      Serial.print(" / ");
      Serial.print(pot1);
      Serial.print(" / ");
      Serial.print(b1);
      Serial.print(b2);
      Serial.print(b3);
      Serial.print(b4);
      Serial.print(b5);
      Serial.print(b6);
      Serial.println(tgs1);
      Serial.println("---");
      

      
      
  
      
      
      



      }
      
      




    
  
}
