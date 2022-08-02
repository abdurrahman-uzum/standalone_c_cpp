#include <IRremote.h>

IRrecv irrecv(2);
decode_results results;

void setup() {
  pinMode(2, INPUT); //IR
  pinMode(3, OUTPUT); //Relay
  pinMode(4, INPUT); //B

  irrecv.enableIRIn();
}

void loop() {
  int a;
  int b;

  if (irrecv.decode(&results)) {

    if( digitalRead(4) == HIGH) {
      a = results.value;
    }
    else {
      b = results.value;
    }

    if (results.value == a) {
      digitalWrite(3, HIGH);
    }
    if (results.value == b) {
      digitalWrite(3, LOW);
    }
    irrecv.resume();
  }
  
}
