#include <Servo.h>
Servo myservo;


void setup() {
  pinMode (10, OUTPUT);
  pinMode (11, OUTPUT);
  myservo.attach(9);
}

void loop() {
  myservo.write(90);
  digitalWrite(10, HIGH);
  myservo.write(70);
  delay(250);
  myservo.write(90);
  delay(250);
  myservo.write(110);
  delay(250);
}
