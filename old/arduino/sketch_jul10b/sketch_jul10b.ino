unsigned long time;

void setup() {
  Serial.begin(9600);
  pinMode(6, INPUT);
}
void loop() {
  Serial.print("Time: ");
  while ( digitalRead(6 == HIGH) ) {
  
  time = millis();
  }
  Serial.println(time); //prints time since program started
  delay(1000);          // wait a second so as not to send massive amounts of data
}
