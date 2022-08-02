#include <SoftwareSerial.h>

SoftwareSerial bt_iletisim(8, 7); // RX,TX

void setup()
{
  Serial.begin(9600);
  bt_iletisim.begin(9600);
}

void loop()
{
  if (bt_iletisim.available())
  {
    char data = bt_iletisim.read();
    Serial.println(data);
  }
}
