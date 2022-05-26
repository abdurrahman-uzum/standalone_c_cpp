#include <Enrf24.h>
#include <nRF24L01.h>
#include <string.h> // atoi() fonksiyonu için string kütüphanesi tanımlanıyor
#include <SPI.h>

Enrf24 nRF(4, 10, 2);  // CE , CSN/CS/SS , IRQ bacaklarının Arduino ile bağlantıları tanımlandı

// alıcı adresi tanımlandı aynı adres vericide de tanımlanmalıdır
const byte address1[] = { 0xDC, 0xAD, 0xBE, 0x0F, 0x01 };
const byte address2[] = { 0xDE, 0xAD, 0xBE, 0x0F, 0x01 };
const byte address3[] = { 0xDA, 0xAD, 0xBE, 0x0F, 0x01 };


void setup() 
{
  pinMode(3, OUTPUT); // aç kapat yapılacak LED için pin modu çıkış ayarlandı
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  

  SPI.begin(); // SPI başlat
  SPI.setDataMode(SPI_MODE0); // SPI MODE0 seçildi, nrf24l01 MODE0 ile iletişim kurmaktadır
  SPI.setBitOrder(MSBFIRST); // bit sıralaması MSB'den LSB'ye doğru ayarlandı

  // datarate 250000/1000000/2000000, channel 0/125
  // 1000000 datarate seçildi , 124 nolu kanal seçildi
  nRF.begin(1000000,124); 

  nRF.setRXaddress(address1); // alıcı adresi ayarlandı
  
  nRF.enableRX();  // Dinlemeye başla

  
}

void loop()
{

char data1[33]; // gelen string türünde bilgi için geçici dizi değişken
char data2[33];
char data3[33];

  int datawrite1;
  int datawrite2;
  int datawrite3;

  
/////////////////////////////////

  nRF.setRXaddress(address1);
  if (nRF.read(data1))  // bilgi geldiyse bunu gelen_bilgi değişkenine aktar
  {

    datawrite1 = atoi(data1);
    analogWrite(3,map(datawrite1,0,1023,0,255));

    
   }

   delay(10);  
   
/////////////////////////////////

   
/////////////////////////////////

   nRF.setRXaddress(address2);
  if (nRF.read(data2))  // bilgi geldiyse bunu gelen_bilgi değişkenine aktar
  {

    datawrite2 = atoi(data2);
    analogWrite(5,map(datawrite2,0,1023,0,255));
   }

   delay(10);
   
/////////////////////////////////


/////////////////////////////////

    nRF.setRXaddress(address3);
  if (nRF.read(data3))  // bilgi geldiyse bunu gelen_bilgi değişkenine aktar
  {

    datawrite3 = atoi(data3);
    analogWrite(6,map(datawrite3,0,1023,0,255));
   }

   delay(10);










    
  
}
