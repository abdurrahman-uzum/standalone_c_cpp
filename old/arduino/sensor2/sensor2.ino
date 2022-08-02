#include <Wire.h>
#define SENSOR_ADRS 0x40 // I2C address of GP2Y0E03
#define DISTANCE_ADRS 0x5E



void setup()
{
  Wire.begin(); // Initialize I2C,
  delay(1000); // start after 1 second
  Serial.begin(9600);
}
void loop()
{
    int ans ;
    byte c[2];
    Wire.beginTransmission (SENSOR_ADRS); // start communication processing
    Wire.write (DISTANCE_ADRS); // specify the address of the table storing the distance value
    ans = Wire.endTransmission(); // send and close data
    delay(200);

    if (ans == 0) {
        ans = Wire.requestFrom(SENSOR_ADRS, 2) ;
        c[0] = Wire.read(); // Read the 11th to 4th bits of data c [1]
        c[1] = Wire.read(); // Read the 3rd and 0th bits of the data
        ans = ((c [0] * 16 + c [1]) / 16) / 4; // distance
        Serial.print(ans);
        Serial.println (“cm”); //to display on serial monitor;
    }
}
