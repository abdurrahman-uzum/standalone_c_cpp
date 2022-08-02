#include <Enrf24.h>
#include <nRF24L01.h>
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



void setup() 
{
  

  SPI.begin(); // SPI başlat
  SPI.setDataMode(SPI_MODE0); // SPI MODE0 seçildi, nrf24l01 MODE0 ile iletişim kurmaktadır
  SPI.setBitOrder(MSBFIRST); // bit sıralaması MSB'den LSB'ye doğru ayarlandı
  
  // datarate 250000/1000000/2000000, channel 0/125
  // 1000000 datarate seçildi , 124 nolu kanal seçildi
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
  int j1x = analogRead(A1);
  int j1y = analogRead(A2);
  bool j1b = digitalRead(A0);

  int j2y = analogRead(A6);
  int j2x = analogRead(A7);
  bool j2b = digitalRead(A5);
  
  int pot1 = analogRead(A3);
  int pot2 = analogRead(A4);
  
  bool b1 = digitalRead(3);
  bool b2 = digitalRead(5);
  bool b3 = digitalRead(6);
  bool b4 = digitalRead(7);
  bool b5 = digitalRead(8);
  bool b6 = digitalRead(9);

  bool tgs1 = digitalRead(0);
  bool tgs2 = digitalRead(1);

  nRF.setTXaddress(address1);
  nRF.print(j1x);
  nRF.flush();
  delay(10);
  
  nRF.setTXaddress(address2);
  nRF.print(j1y);
  nRF.flush();
  delay(10);

  nRF.setTXaddress(address3);
  nRF.print(j1b);
  nRF.flush();
  delay(10);
  

  nRF.setTXaddress(address4);
  nRF.print(j2x);
  nRF.flush();

  nRF.setTXaddress(address5);
  nRF.print(j2y);
  nRF.flush();

  nRF.setTXaddress(address6);
  nRF.print(j2b);
  nRF.flush();

  nRF.setTXaddress(address7);
  nRF.print(pot1);
  nRF.flush();

  nRF.setTXaddress(address8);
  nRF.print(pot2);
  nRF.flush();

  nRF.setTXaddress(address9);
  nRF.print(b1);
  nRF.flush();

  nRF.setTXaddress(address10);
  nRF.print(b2);
  nRF.flush();

  nRF.setTXaddress(address11);
  nRF.print(b3);
  nRF.flush();

  nRF.setTXaddress(address12);
  nRF.print(b4);
  nRF.flush();

  nRF.setTXaddress(address13);
  nRF.print(b5);
  nRF.flush();

  nRF.setTXaddress(address14);
  nRF.print(b6);
  nRF.flush();

  nRF.setTXaddress(address15);
  nRF.print(tgs1);
  nRF.flush();

  nRF.setTXaddress(address16);
  nRF.print(tgs2);
  nRF.flush();
  
  



















  
}
