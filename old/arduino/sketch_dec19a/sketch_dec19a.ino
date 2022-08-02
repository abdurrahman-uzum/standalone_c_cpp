void setup()
{
  pinMode (5, OUTPUT);
  pinMode (6, OUTPUT);
  pinMode (9, OUTPUT);
  pinMode (10, OUTPUT);
}




void loop()
{
  analogWrite(6, 200);
  analogWrite(10, 200);
}
