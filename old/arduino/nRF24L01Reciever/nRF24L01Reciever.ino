/*
* Lezzetli Robot Tarifleri
* https://lezzetlirobottarifleri.com/nrf24l01-kablosuz-alici-verici-haberlesme-modulu/
*/

// Kütüphane dosyaları tanımlanıyor
#include <Enrf24.h>
#include <nRF24L01.h>
#include <string.h> // atoi() fonksiyonu için string kütüphanesi tanımlanıyor
#include <SPI.h>

Enrf24 nRF(9, 10, 2);  // CE , CSN/CS/SS , IRQ bacaklarının Arduino ile bağlantıları tanımlandı

// alıcı adresi tanımlandı aynı adres vericide de tanımlanmalıdır
const byte alici_adresi[] = { 0xDE, 0xAD, 0xBE, 0x0F, 0x01 };

int LED2=4;
int LED1=3;

void setup() 
{
  pinMode(LED2, OUTPUT); // aç kapat yapılacak LED için pin modu çıkış ayarlandı

  SPI.begin(); // SPI başlat
  SPI.setDataMode(SPI_MODE0); // SPI MODE0 seçildi, nrf24l01 MODE0 ile iletişim kurmaktadır
  SPI.setBitOrder(MSBFIRST); // bit sıralaması MSB'den LSB'ye doğru ayarlandı

  // datarate 250000/1000000/2000000, channel 0/125
  // 1000000 datarate seçildi , 124 nolu kanal seçildi
  nRF.begin(1000000,124); 

  nRF.setRXaddress(alici_adresi); // alıcı adresi ayarlandı
  
  nRF.enableRX();  // Dinlemeye başla
}

void loop()
{
  char gelen_bilgi[33]; // gelen string türünde bilgi için geçici dizi değişken
  int bilgi=0; // string değeri sayısal değere dönüştürdükten sonra aktarılacak değişken tanımlanıyor

  if (nRF.read(gelen_bilgi))  // bilgi geldiyse bunu gelen_bilgi değişkenine aktar
  {
    // atoi() ile gelen_bilgi string ifadesini interger
    // yani tam sayıya dönüştür ve bilgi değişkenine aktar
    bilgi = atoi(gelen_bilgi);

    // gelen veri analog bilgi olduğundan 0-1023 arasında
    // değerler gelecektir. analogWrite ile bunu dijital pine aktarmak için 
    // map fonskiyonu ile 0-255 arasında oranlamalıyız. daha sonra LED1
    // parlaklığını analogWrite ile ayarlamış oluyoruz.
    if(gelen_bilgi[0]=='A') // eğer gelen_bilgi dizinin ilk karakteri A ise
    {
      digitalWrite(LED2, HIGH); // LED2'yi yak
    }
    else if(gelen_bilgi[0]=='K') // eğer gelen_bilgi dizinin ilk karakteri K ise
    {
      digitalWrite(LED2, LOW); // LED2'yi söndür
    }
    else
    {
      analogWrite(LED1,map(bilgi,0,1023,0,255));
    }
  }
}
