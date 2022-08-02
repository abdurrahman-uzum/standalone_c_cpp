// Include the standard Wire library for I2C 
#include <Wire.h>

void setup() { 
// Start the I2C Bus as Master 
Wire.begin(); 
} 
void loop() { 
Wire.beginTransmission(9); // transmit to device #9 
Wire.write('x'); // sends x 

delay(500); 
}
