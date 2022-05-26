#include <SoftwareSerial.h>

SoftwareSerial bt(8,7); //RX TX ( of Arduino )

void setup() {  
  bt.begin(9600);
  Serial.begin(9600); 
}


void loop() 
{
  while(bt.available()) 
  {
    char data = bt.read();   
    Serial.println(data);
      
  }
}
