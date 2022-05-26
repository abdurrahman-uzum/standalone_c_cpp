bool limButtonF;
bool limButtonB;


void setup() {
Serial.begin(9600);
}

void loop() {

  if(100 <= analogRead(A6)&& analogRead(A6) <= 600) { limButtonB = true; }
  else if(600 < analogRead(A6)) { limButtonF = true; }
  else { limButtonF = false;   limButtonB = false;  }

  Serial.print("F: ");
  Serial.print(limButtonF);
  Serial.print(" / B: ");
  Serial.print(limButtonB);
  Serial.print(" / ");
  Serial.println(analogRead(A6));

  
  
}
