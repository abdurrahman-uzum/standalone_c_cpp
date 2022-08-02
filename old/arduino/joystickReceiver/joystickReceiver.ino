#include <Enrf24.h>
#include <nRF24L01.h>
#include <string.h> // atoi() 
#include <SPI.h>

Enrf24 nRF(4, 10, 2);  // CE , CSN/CS/SS , IRQ 

const byte address1[] = { 0xDE, 0xAD, 0xBE, 0x0F, 0x01 };  //0xDE, 0xAD, 0xBE, 0x0F, 0x01
const byte address2[] = { 0xDE, 0xAD, 0xBE, 0x0F, 0x02 };
const byte address3[] = { 0xDE, 0xAD, 0xBE, 0x0F, 0x03 };
const byte address4[] = { 0xDE, 0xAD, 0xBE, 0x0F, 0x04 };
const byte address5[] = { 0xDE, 0xAD, 0xBE, 0x0F, 0x05 };
const byte address6[] = { 0xDE, 0xAD, 0xBE, 0x0F, 0x06 };
const byte address7[] = { 0xDE, 0xAD, 0xBE, 0x0F, 0x07 };
const byte address8[] = { 0xDE, 0xAD, 0xBE, 0x0F, 0x08 };
const byte address9[] = { 0xDE, 0xAD, 0xBE, 0x0F, 0x09 };
const byte address10[] = { 0xDE, 0xAD, 0xBE, 0x0F, 0x10 };
const byte address11[] = { 0xDE, 0xAD, 0xBE, 0x0F, 0x11 };
const byte address12[] = { 0xDE, 0xAD, 0xBE, 0x0F, 0x12 };
const byte address13[] = { 0xDE, 0xAD, 0xBE, 0x0F, 0x13 };
const byte address14[] = { 0xDE, 0xAD, 0xBE, 0x0F, 0x14 };
const byte address15[] = { 0xDE, 0xAD, 0xBE, 0x0F, 0x15 };
const byte address16[] = { 0xDE, 0xAD, 0xBE, 0x0F, 0x16 };


 char data1[33]; 
  char data2[33];
  char data3[33];
  char data4[33]; 
  char data5[33];
  char data6[33];
  char data7[33]; 
  char data8[33]; 
  char data9[33]; 
  char data10[33]; 
  char data11[33]; 
  char data12[33]; 
  char data13[33]; 
  char data14[33]; 
  char data15[33]; 
  char data16[33]; 

  int intData1;
  int intData2;
  int intData4;
  int intData5;
  int intData7;
  int intData8;
  

  
  int j1x;
  int j1y;
  bool j1b;

  int j2y;
  int j2x;
  bool j2b;
  
  int pot1;
  int pot2;
  
  bool b1;
  bool b2;
  bool b3;
  bool b4;
  bool b5;
  bool b6;

  bool tgs1;
  bool tgs2;

  
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

  char data1[33]; 
  char data2[33];
  char data3[33];
  char data4[33]; 
  char data5[33];
  char data6[33];
  char data7[33]; 
  char data8[33]; 
  char data9[33]; 
  char data10[33]; 
  char data11[33]; 
  char data12[33]; 
  char data13[33]; 
  char data14[33]; 
  char data15[33]; 
  char data16[33]; 

  int intData1;
  int intData2;
  int intData4;
  int intData5;
  int intData7;
  int intData8;
  

  
  int j1x;
  int j1y;
  bool j1b;

  int j2y;
  int j2x;
  bool j2b;
  
  int pot1;
  int pot2;
  
  bool b1;
  bool b2;
  bool b3;
  bool b4;
  bool b5;
  bool b6;

  bool tgs1;
  bool tgs2;

  

    nRF.setRXaddress(address1);
      if(nRF.read(data1))
      {
        intData1 = atoi(data1);
        j1x = map(intData1, 0, 1024, -128, 128);

        Serial.println(j1x);

        delay(10);
        
      }

    nRF.setRXaddress(address2);
      if(nRF.read(data2))
      {
        intData2 = atoi(data2);
        j1y = map(intData2, 0, 1024, -128, 128);

        Serial.println(j1y);

        delay(10);
        
      }

      nRF.setRXaddress(address3);
      if(nRF.read(data3))
      {
        if (data3 == '1') { j1b = true; }
        else if (data3 == '0') { j1b = false; }

        delay(10);
      }

    nRF.setRXaddress(address4);
      if(nRF.read(data4))
      {
        intData4 = atoi(data4);
        j2x = map(intData4, 0, 1023, -128, 128);

        delay(10);
        
      }

    nRF.setRXaddress(address5);
      if(nRF.read(data5))
      {
        intData5 = atoi(data5);
        j2y = map(intData5, 0, 1023, -128, 128);

        delay(10);
        
      }

      nRF.setRXaddress(address6);
      if(nRF.read(data6))
      {
        if (data6 == 1) { j2b = true; }
        else if (data6 == 0) { j2b = false; }

        delay(10);
        
      }

      nRF.setRXaddress(address7);
      if(nRF.read(data7))
      {
        intData7 = atoi(data7);
        pot1 = map(intData7, 0, 1023, 0, 256);

        delay(10);
        
      }

      nRF.setRXaddress(address8);
      if(nRF.read(data8))
      {
        intData8 = atoi(data8);
        pot2 = map(intData8, 0, 1023, 0, 256);

        delay(10);
        
      }

      nRF.setRXaddress(address9);
      if(nRF.read(data9))
      {
        if (data9 == 1) { b1 = true; }
        else if (data9 == 0) { b2 = false; }

        delay(10);
      }

      nRF.setRXaddress(address10);
      if(nRF.read(data10))
      {
        if (data10 == 1) { b2 = true; }
        else if (data10 == 0) { b2 = false; }

        delay(10);
        
      }

      nRF.setRXaddress(address11);
      if(nRF.read(data11))
      {
        if (data11 == 1) { b3 = true; }
        else if (data11 == 0) { b3 = false; }

        delay(10);
        
      }

      nRF.setRXaddress(address12);
      if(nRF.read(data12))
      {
        if (data12 == 1) { b4 = true; }
        else if (data12 == 0) { b4 = false; }

        delay(10);
      }

      nRF.setRXaddress(address13);
      if(nRF.read(data13))
      {
        if (data13 == 1) { b5 = true; }
        else if (data13 == 0) { b5 = false; }

        delay(10);
      }

      nRF.setRXaddress(address14);
      if(nRF.read(data14))
      {
        if (data14 == 1) { b6 = true; }
        else if (data14 == 0) { b6 = false; }

        delay(10);
        
      }

      nRF.setRXaddress(address15);
      if(nRF.read(data15))
      {
        if (data15 == 1) { tgs1 = true; }
        else if (data15 == 0) { tgs1 = false; }

        delay(10);
      }

      nRF.setRXaddress(address16);
      if(nRF.read(data16))
      {
        if (data16 == 1) { tgs2 = true; }
        else if (data16 == 0) { tgs2 = false; }

        delay(10);
        
      }

      


  Serial.print("Joystick 1: ");
  Serial.print(j1x);
  Serial.print(" / ");
  Serial.print(j1y);
  Serial.print(" / ");
  Serial.println(j1b);

  Serial.println("-----------------------------------------------------");

  Serial.print("Joystick 2: ");
  Serial.print(j2x);
  Serial.print(" / ");
  Serial.print(j2y);
  Serial.print(" / ");
  Serial.println(j2b);

  Serial.println("-----------------------------------------------------");

  delay(750);

  Serial.print("Pot1: ");
  Serial.println(pot1);

  Serial.println("-----------------------------------------------------");

  Serial.print("Pot2: ");
  Serial.println(pot2);

  Serial.println("-----------------------------------------------------");

  Serial.print("Buttons: ");
  Serial.print(b1);
  Serial.print(" / ");
  Serial.print(b2);
  Serial.print(" / ");
  Serial.print(b3);
  Serial.print(" / ");
  Serial.print(b4);
  Serial.print(" / ");
  Serial.print(b5);
  Serial.print(" / ");
  Serial.println(b6);

  Serial.print("Toggle switches: ");
  Serial.print(tgs1);
  Serial.print(" / ");
  Serial.println(tgs2);

  Serial.println("-----------------------------------------------------");
  Serial.println("-----------------------------------------------------");

  delay(750);

      
        
      
    







    
  
}
