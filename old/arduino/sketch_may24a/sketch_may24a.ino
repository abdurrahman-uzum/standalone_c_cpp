#include <Servo.h>

const int servopin = 4;


Servo servo1;

void setup() 
{
    Serial.begin(115200);
    servo1.attach(servopin);

}

void loop() 
{

    for(;;)
    {
        Serial.println( "0" );
        servo1.write( 0 );
        delay(1000);

        Serial.println( "45" );
        servo1.write( 45 );
        delay(1000);

        Serial.println( "90" );
        servo1.write( 90 );
        delay(1000);
        
        Serial.println( "135" );
        servo1.write( 135 );
        delay(1000);

        Serial.println( "180" );
        servo1.write( 180 );
        delay(1000);

        Serial.println( "90" );
        servo1.write( 90 );
        delay(1000);
        
    }






}
