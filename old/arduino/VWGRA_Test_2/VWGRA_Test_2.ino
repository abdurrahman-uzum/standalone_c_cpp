#include <Enrf24.h>
#include <nRF24L01.h>
#include <string.h> // atoi() 
#include <SPI.h>

#include <Stepper.h>
#include <Servo.h>

const int stepsPerRevolution = 2048;  //Dependent on stepper you are using, check datasheet.

Stepper stepper(stepsPerRevolution, A0, A2, A1, A3); // This should have been as in1, in2, in3, in4 but for some reason it does not work like that but works on this arrange. IDK...

Servo servo;

Enrf24 nRF(4, 10, 2);  // CE , CSN/CS/SS , IRQ 

const byte address1[] = { 0xDE, 0xAD, 0xBE, 0x0F, 0x01 };  //0xDE, 0xAD, 0xBE, 0x0F, 0x01

 char data1[33]; //temporary storage for receiving data as char type.

 
  int j2x;    // steering.
  int j1y;    // direction and speed.
  int pot1;   // robotic arm to grab

  char jx[4];   //temporary storage
  char jy[4];
  char pot[4];

  bool b1;
  bool b2;
  bool b3;
  bool b4;
  bool b5;
  bool b6;
  bool tgs1;

  int DS;  //Differencial speed; for steer vehicle

  

  
void setup() 
{
  SPI.begin(); 
  SPI.setDataMode(SPI_MODE0); 
  SPI.setBitOrder(MSBFIRST); 

  nRF.begin(1000000,125); // datarate 250000/1000000/2000000, channel 0/125 (Note that lower channels may interfere with WiFi signals)

  stepper.setSpeed(10); //RPM

  servo.attach(8);
  
  nRF.enableRX();  // Start listening.

  pinMode(3, OUTPUT); //PWM output pins for motor control.
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);

  pinMode(A4, OUTPUT);  // Switching amongst steppers which share same pins.
  pinMode(A5, OUTPUT);
  pinMode(7, OUTPUT);

  nRF.setRXaddress(address1);
}

// Motors: (3, 5)left - (6, 9)right / forward first 
// left will receive negative x axis value

void forward() {
  analogWrite(3, j1y);
  analogWrite(6, j1y);
}

void backward() {
  analogWrite(5, abs(j1y));
  analogWrite(9, abs(j1y));
}

void rightforward() {
  DS = map(j2x, 0, 255, 0, j1y);
  
  analogWrite(3, j1y);
  analogWrite(6, j1y-DS);
}

void leftforward() {
  DS = map(abs(j2x), 0,255, 0, j1y);

  analogWrite(3, j1y-DS);
  analogWrite(6, j1y);
}

void rightbackward() {
  DS = map(j2x, 0, 255, 0, j1y);

  analogWrite(5, abs(j1y));
  analogWrite(9, abs(j1y)-DS);
}

void leftbackward() {
  DS = map(abs(j2x), 0, 255, 0, j1y);
  
  analogWrite(5, abs(j1y)-DS);
  analogWrite(9, abs(j1y));
}

void idle() { 
  digitalWrite(3, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(9, 0);
}
// I really hope these commands above will work :( 



void loop()
{    
      nRF.read(data1);     //while we are receiving anything...
 

      if(data1[9] == '1') { b1=true; }
      if(data1[9] == '0') { b1=false; }

      if(data1[10] == '1') { b2=true; }
      if(data1[10] == '0') { b2=false; }

      if(data1[11] == '1') { b3=true; }
      if(data1[11] == '0') { b3=false; }

      if(data1[12] == '1') { b4=true; }
      if(data1[12] == '0') { b4=false; }

      if(data1[13] == '1') { b5=true; }
      if(data1[13] == '0') { b5=false; }

      if(data1[14] == '1') { b6=true; }
      if(data1[14] == '0') { b6=false; }

      if(data1[15] == '1') { tgs1=true; }
      if(data1[15] == '0') { tgs1=false; }

      pot[0] = data1[6];
      pot[1] = data1[7];
      pot[2] = data1[8];

      

     
      pot1 = map(atoi(pot), 0, 999, 30, 150);        


          
          if(b1 || b2) { digitalWrite(A4, HIGH);  digitalWrite(A5, LOW);  digitalWrite(7, LOW); }
          if(b3 || b4) { digitalWrite(A5, HIGH);  digitalWrite(A4, LOW);  digitalWrite(7, LOW); }
          if(b5 || b6) { digitalWrite(7, HIGH);  digitalWrite(A4, LOW);  digitalWrite(A5, LOW); }

          if(b1 || b3 || b5) { stepper.step(25); }
          if(b2 || b4 || b6) { stepper.step(-25); }

           

          servo.write(pot1);
          
        }

      

      
