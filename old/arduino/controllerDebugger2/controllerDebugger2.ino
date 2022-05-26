void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  char buttons[6];
  
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

  if (b1) { buttons[0] = 'A'; }
  if (!b1) { buttons[0] = 'B'; }

  if (b2) { buttons[1] = 'C'; }
  if (!b2) { buttons[1] = 'D'; }

  if (b3) { buttons[2] = 'E'; }
  if (!b3) { buttons[2] = 'F'; }

  if (b4) { buttons[3] = 'G'; }
  if (!b4) { buttons[3] = 'H'; }

  if (b5) { buttons[4] = 'I'; }
  if (!b5) { buttons[4] = 'J'; }

  if (b6) { buttons[5] = 'K'; }
  if (!b6) { buttons[6] = 'L'; }
  

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
  Serial.println(buttons);

  Serial.println("-----------------------------------------------------");
  Serial.println("-----------------------------------------------------");

  delay(750);












  
  
}
