void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  bool j1b = digitalRead(A0);
  int j1x = analogRead(A1);
  int j1y = analogRead(A2);
  int pot1 = analogRead(A3);
  int pot2 = analogRead(A4);
  bool j2b = digitalRead(A5);
  int j2y = analogRead(A6);
  int j2x = analogRead(A7);

  bool b1 = digitalRead(3);
  bool b2 = digitalRead(5);
  bool b3 = digitalRead(6);
  bool b4 = digitalRead(7);
  bool b5 = digitalRead(8);
  bool b6 = digitalRead(9);

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

  delay(750);












  
  
}
