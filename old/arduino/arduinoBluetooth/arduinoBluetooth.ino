char inSerial[15];

void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);

  pinMode(1,OUTPUT);
  pinMode(0,INPUT);

  allpinslow();

}

void loop() {
  int i = 0;
  int m = 0;
  delay(500);
  if(Serial.available() > 0) {
    while(Serial.available() > 0) {
      inSerial[i] = Serial.read();
      i++;
    }
    inSerial[i] = '\0';
    Check_Protocol(inSerial);
  }
}

void allpinslow() {
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
}

void Check_Protocol(char inStr[]) {
  int i=0;
  int m=0;
  Serial.println(inStr);

  if(!strcmp(inStr, "2off")) {
    allpinslow();
    digitalWrite(13,LOW);
    Serial.println("elma");
    for(m=0; m<11; m++) {
      inStr[m]=0;
    }

  if(!strcmp(inStr, "2on")) {
    allpinslow();
    digitalWrite(13,HIGH);
    Serial.println("portakal");
    for(m=0; m<11; m++) {
      inStr[m]=0;
    }
  }

    else{
      for(m=0; m<11; m++) {
      inStr[m]=0;
    }
    i=0;
    }}}
