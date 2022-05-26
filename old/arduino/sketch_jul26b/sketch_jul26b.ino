void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

}

void loop() {
  int pot = map(analogRead(A0), 0,1024, -20, 20);

  Serial.println(abs(pot));
}
