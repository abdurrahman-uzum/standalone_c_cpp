#define pot A0
#define led 11

void setup() 
{
  pinMode ( 11, OUTPUT);

}

void loop() 
{
  int deger = analogRead(pot);
  int potDeger = map(deger,0, 1023, 0, 255);
  analogWrite(11, potDeger );

}
