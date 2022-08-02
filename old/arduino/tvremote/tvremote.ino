#include <IRremote.h>

IRrecv irrecv(5);

decode_results results;

void setup() {
  pinMode(5, INPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results)) {
    
    if (results.value == 2160030094) {
      Serial.println("1");
    }

    if (results.value == 2160026014) {
      Serial.println("2");
    }
    Serial.println(results.value);

    irrecv.resume();
    
  }
  
}
