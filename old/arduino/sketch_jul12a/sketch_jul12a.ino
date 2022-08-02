void setup() {

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(0, INPUT);
  pinMode(1, INPUT);

}

void loop() {

  if(digitalRead(0) == HIGH) {
    digitalWrite(2, HIGH);
  }
  else {
    digitalWrite(2, LOW);
  }

  if(digitalRead(1) == HIGH) {
    digitalWrite(3, HIGH);
  }
  else {
    digitalWrite(3, LOW);
  }
  }
