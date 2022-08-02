#include <SPI.h>
#include <RFID.h>
#include <Servo.h>

Servo servo;

int pos;

RFID rfid(10, 5);

int key[5] = { 25, 175, 196, 86, 36 };
int key1[5] = { 89, 148, 101, 72, 224 };
int attemp[5];

int lock;
int a;

void unlock() {
  for (pos; pos <= 170; pos += 2) { 
    servo.write(pos);              
    delay(15);   
    //if (pos <= 170) { break; }                    
  }  
}

void Lock() {
  for (pos; pos >= 10; pos -= 2) { 
    servo.write(pos);              
    delay(15);         
    //if (pos >= 10) { break; }              
   
  }  
}

void setup() {
  SPI.begin();
  rfid.init();
  pinMode(8, INPUT);
  pinMode(5, OUTPUT);
  servo.attach(3);

  digitalWrite(5, HIGH);
  delay(70);
  unlock();
  digitalWrite(5, LOW);
  
  

  
  
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
       
        digitalWrite(5, HIGH);
        delay(200);
        unlock();
        delay(100);
        digitalWrite(5, LOW);
        

        attemp[0] = 0;
        attemp[1] = 0;
        attemp[2] = 0;
        attemp[3] = 0;
        attemp[4] = 0;
        

        delay(3000);
        
        lock = 10;
        a = 1;
      }
      else if ( key1[0] == attemp[0] && key1[1] == attemp[1] && key1[2] == attemp[2] && key1[3] == attemp[3] && key1[4] == attemp[4] ) {

        digitalWrite(5, HIGH);
        delay(200);
        unlock();
        delay(100);
        digitalWrite(5, LOW);
        

        attemp[0] = 0;
        attemp[1] = 0;
        attemp[2] = 0;
        attemp[3] = 0;
        attemp[4] = 0;
        

        delay(3000);
        
        lock = 10;
        a = 1;
        
      }
      
      if ( lock == 10 && digitalRead(8) == HIGH && a != 0) {
        delay(2000);
        
        digitalWrite(5, HIGH);
        delay(200);
        Lock();
        delay(100);
        digitalWrite(5,LOW);
        a=0;
        
      }
}
