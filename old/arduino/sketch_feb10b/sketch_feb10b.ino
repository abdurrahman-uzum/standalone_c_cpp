/*
 1: 4294967295
 1: 2160030094

 2: 4294967295
 2: 2160026014
 */

#include <IRremote.h>
IRrecv irrecv(4);
decode_results results;

void setup() {
  pinMode(4, INPUT);
  pinMode(3, OUTPUT);
  
  irrecv.enableIRIn();
}

void loop() {
  
  if (irrecv.decode(&results)) {
    
    if (results.value == 2160030094) {
      digitalWrite(3, HIGH);
    }

    if (results.value == 2160026014) {
      digitalWrite(3, LOW);
    }

    irrecv.resume();
    
  }
}
