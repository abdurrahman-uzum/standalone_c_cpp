#include <Wire.h>
#include <String.h>

atoi

char x;


void setup() { 

// Start the I2C Bus as Slave on address 9 
Wire.begin(9); 
// Attach a function to trigger when something is received.
Wire.onReceive(receiveEvent); 

Serial.begin(9600);

} 
void receiveEvent(int bytes) { 
 x = Wire.read(); // read one character from the I2C 
 
} 
void loop() { 

  Serial.println(x);








  
/*//If value received is 0 blink LED for 200 ms 
if (x == '0') { 
digitalWrite(LED, HIGH); 
delay(200); 
digitalWrite(LED, LOW); 
delay(200); 
} 
//If value received is 3 blink LED for 400 ms 
if (x == '3') { 
digitalWrite(LED, HIGH); 
delay(400); 
digitalWrite(LED, LOW); 
delay(400); 
} */


}
