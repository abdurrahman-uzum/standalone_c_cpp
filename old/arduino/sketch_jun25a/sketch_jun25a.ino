#include <SoftwareSerial.h>

SoftwareSerial bt_iletisim(8,7);

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  bt_iletisim.begin(9600);

}

void loop() {
  if (bt_iletisim.available())
  {
    char data=bt_iletisim.read();
    Serial.println(data);

    
  }

}
