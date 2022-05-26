#include <SPI.h>
#include <RFID.h>
#include <Servo.h>

Servo servo;

int pos;

RFID rfid(10, 5);

int key[5] = { 25, 175, 196, 86, 36 };
int attemp[5];

int lock;

void Lock() {
  for (pos = 0; pos <= 180; pos += 1) { 
    servo.write(pos);              
    delay(15);   
    if (pos <= 170) { break; }                    
  }  
}

void unlock() {
  for (pos = 180; pos >= 0; pos -= 1) { 
    servo.write(pos);              
    delay(15);         
    if (pos >= 10) { break; }              
   
  }  
}

void setup() {
  //Serial.begin(9600);
  SPI.begin();
  rfid.init();
  //pinMode(3, OUTPUT);
  pinMode(4, INPUT);
  servo.attach(3);
  

  
  
}


void loop() {  
  
  if( rfid.isCard() ) {

    if(  rfid.readCardSerial() ) {

        attemp[0] = rfid.serNum[0];
        attemp[1] = rfid.serNum[1];
        attemp[2] = rfid.serNum[2];
        attemp[3] = rfid.serNum[3];
        attemp[4] = rfid.serNum[4];
    
    }
  }   rfid.halt();

      if ( key[0] == attemp[0] && key[1] == attemp[1] && key[2] == attemp[2] && key[3] == attemp[3] && key[4] == attemp[4] ) {
        unlock();

        attemp[0] = 0;
        attemp[1] = 0;
        attemp[2] = 0;
        attemp[3] = 0;
        attemp[4] = 0;
        

        delay(3000);

        lock = 10;
      }
      
      if ( lock == 10 && digitalRead(3) == HIGH ) {
        delay(2000);
        Lock();
      }
}
