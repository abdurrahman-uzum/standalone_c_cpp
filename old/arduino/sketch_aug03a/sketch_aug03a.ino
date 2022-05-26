void setup() {
  Serial.begin(9600);
}

void loop() {
  int pot0 = analogRead(A0);
  int pot1 = analogRead(A1);
  int pot2 = analogRead(A2);

  Serial.print("Pot0 = ");
  Serial.println(pot0);
  Serial.print("Pot1 = ");
  Serial.println(pot1);
  Serial.print("Pot2 = ");
  Serial.println(pot2);
  Serial.println("");
  delay(1000);
}
