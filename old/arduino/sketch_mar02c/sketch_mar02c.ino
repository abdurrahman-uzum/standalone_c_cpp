bool door = digitalRead(3);
//boolean lock = true;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

 // if ( digitalRead(3) == HIGH ) { door = true; }
  //else if ( digitalRead(3) == LOW ) { door = false; }
  if( door == true )  {
    digitalWrite(2, HIGH);
  }
  else { digitalWrite(2, LOW); }}
