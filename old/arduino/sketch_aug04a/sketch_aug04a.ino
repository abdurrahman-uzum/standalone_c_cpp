void setup() {
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  for (int i = 0; i <= 255; i = i+5) {
    analogWrite(3, i);
    delay(200);
  }
}
