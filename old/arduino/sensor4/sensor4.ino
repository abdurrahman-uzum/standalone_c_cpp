#include <Wire.h>

void setup() {
Wire.begin();
Serial.begin(9600);
pinMode(A0,OUTPUT);
}

void getData(byte *a, byte *b)
{Wire.beginTransmission(0x48);
Wire.write(0);
Wire.endTransmission();
Wire.requestFrom(0x48,2);
*a=Wire.read();
*b=Wire.read();}

void loop() {

  byte aa,bb;
  getData(&aa,&bb);
 float distance1=aa;
  float distance2=bb;
  float dist=analogRead(A0);
  Serial.print("distance1 = ");
  Serial.println(dist,1);
 
  delay(100);


}
//The pins connections that i made was:
//Vout=A0
//VIN(IO)=GPIO1=VCC
//SCL=A5
//SDA=A4
