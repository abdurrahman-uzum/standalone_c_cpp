int inputPins[] = {10, 11, 2, 3, 4, 5, 6, 7, 8, 9};


void setup() {
  pinMode(inputPins[10,11, 2, 3, 4, 5, 6, 7, 8, 9], INPUT);  
  Serial.begin(9600);
}

void loop() {
  for(int i=0; i<9; i++) {
    if(digitalRead(inputPins[i]) == HIGH) {
      Serial.print(inputPins[i]);
      Serial.println(" .pin is HIGH");
    }
    else if(digitalRead(inputPins[i]) == LOW) {
      Serial.print(inputPins[i]);
      Serial.println(" .pin is LOW");
    }
    delay(1000);
  }

}
