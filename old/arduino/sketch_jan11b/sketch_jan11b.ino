#include <Enrf24.h>
#include <nRF24L01.h>
#include <string.h> // atoi() 
#include <SPI.h>

Enrf24 nRF(3, 10, 2);  // CE , CSN/CS/SS , IRQ 

const byte address1[] = { 0xDE, 0xAD, 0xBE, 0x0F, 0x01 };  //0xDE, 0xAD, 0xBE, 0x0F, 0x01

char data1[33];
int j2x;
int j1y;

char jx[4];
char jy[4];

void setup()
{
  SPI.begin(); // SPI başlat
  SPI.setDataMode(SPI_MODE0); 
  SPI.setBitOrder(MSBFIRST); 

  Serial.begin(9600);

  // datarate 250000/1000000/2000000, channel 0/125
  nRF.begin(1000000,125); 
  nRF.setRXaddress(address1);

  nRF.enableRX();

  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

  //servo.attach(9);
}


void loop()
{
  while ( nRF.read(data1)) 
  {
    jy[0] = data1[0];
    jy[1] = data1[1];
    jy[2] = data1[2];

    jx[0] = data1[3];
    jx[1] = data1[4];
    jx[2] = data1[5];

    j2x = map(atoi(jx), 100, 999, -60, 60);        
    j1y = map(atoi(jy), 100, 999, -255, 255);

    if ( j1y > 10 ) { analogWrite(5, j1y); }
    else if ( j1y < -10 ) { analogWrite(6, abs(j1y)); }
    else { analogWrite(5, 0); analogWrite(6, 0); }

    Serial.print(j1y);
    Serial.print(" / ");
    Serial.println(j2x);
  }

}
