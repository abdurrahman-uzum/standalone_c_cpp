#include <Enrf24.h>
#include <nRF24L01.h>
#include <string.h> // atoi() fonksiyonu için string kütüphanesi tanımlanıyor
#include <SPI.h>

Enrf24 nRF(4, 10, 2);  // CE , CSN/CS/SS , IRQ bacaklarının Arduino ile bağlantıları tanımlandı

// alıcı adresi tanımlandı aynı adres vericide de tanımlanmalıdır
const byte address1[] = { 0xDC, 0xAD, 0xBE, 0x0F, 0x01 };
const byte address2[] = { 0xDE, 0xAD, 0xBE, 0x0F, 0x01 };
const byte address3[] = { 0xDA, 0xAD, 0xBE, 0x0F, 0x01 };
const byte address4[] = { 0xDF, 0xAD, 0xBE, 0x0F, 0x01 };


void setup() 
{
  SPI.begin(); // SPI başlat
  SPI.setDataMode(SPI_MODE0); // SPI MODE0 seçildi, nrf24l01 MODE0 ile iletişim kurmaktadır
  SPI.setBitOrder(MSBFIRST); // bit sıralaması MSB'den LSB'ye doğru ayarlandı

  // datarate 250000/1000000/2000000, channel 0/125
  // 1000000 datarate seçildi , 124 nolu kanal seçildi
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

  int intData1;
  int intData2;
  int intData3;
  int intData4;
  int intData5;
  int intData6;

  int j1x;
  int j1y;
  int j2x;
  int j2y;
  

    nRF.setRXaddress(address1);
      if(nRF.read(data1))
      {
        Serial.println(data1);

        delay(10);
        
      }

   }
