#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial bt(8,7);
Servo servo;

void setup() {
  pinMode (10, OUTPUT);
  pinMode (11, OUTPUT);
  
  servo.attach(9);
  servo.write(90);
  
  bt.begin(9600); 
}

void forward() 
{
  analogWrite (11, 255);
}


void backward() 
{
  analogWrite (10, 255);
}


void right() {
  servo.write(60);
}


void left() {
  servo.write(120);
}


void straight() 
{
  servo.write(90);
}

void standby() 
{
  servo.write(90);
  digitalWrite(10, 0);
  digitalWrite(11, 0);
}


void loop() 
{
  while(bt.available()) 
  {
    char data = bt.read();

    switch(data) 
    {      
      case 'f':
      straight();
      forward();
      break;

      case 'b':
      straight();
      backward();
      break;

      case 'r':
      right();
      break;

      case 'l':
      left();
      break;

      case 'c':
      right();
      forward();
      break;

      case 'a':
      left();
      forward();
      break;

      case 'e':
      right();
      backward();
      break;

      case 'd':
      left();
      backward();
      break;

      case '0':
      standby();
      break;
    }

    
      
   }
  }
