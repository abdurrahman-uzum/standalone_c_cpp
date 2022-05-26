

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  int j1x = map(analogRead(A0), 0, 1024, -512, 512);
  int j1y = map(analogRead(A1), 0, 1024, -512, 512);
  bool j1b = digitalRead(A2);

  int j2x = map(analogRead(A3), 0, 1024, -512, 512);
  int j2y = map(analogRead(A4), 0, 1024, -512, 512);
  bool j2b = digitalRead(A5);

  Serial.print("J1X: ");
  Serial.println(j1x);
  Serial.print("J1Y: ");
  Serial.println(j1y);
  Serial.print("Button1: ");
  Serial.println(j1b);

  Serial.print("J2X: ");
  Serial.println(j2x);
  Serial.print("J2Y: ");
  Serial.println(j2y);
  Serial.print("Button2: ");
  Serial.println(j2b);

  
  delay(500);


}
