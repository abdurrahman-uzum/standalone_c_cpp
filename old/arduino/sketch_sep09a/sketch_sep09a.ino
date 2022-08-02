// Written by Abdurrahman ÜZÜM

/*
 This is a project which I started on 20th of July, 2019, and succesfly completed on 4th of September, 2019. 
 This was probably the biggest project of mine which was possible mainly because I finally was able to work with 
 NRF modules. I was struggling with those since not long after I first met with Arduino.
 
 This is the source which helped me for NRFs : https://lezzetlirobottarifleri.com/nrf24l01-kablosuz-alici-verici-haberlesme-modulu/

 Being able to make projects with RF communication opened a huge number of other possible projects, this one happened to be the first,
 and a gateway for much larger lands of projects. I wanted to put this little not here, maybe after years, I will come here again
 and have an emotional moment or whatever.
*/

// LATEST CHANGE: (04.09.2019)  Added for shutting stepper drive cards down unless they are being used, thus preventing heating of stepper motors unnecessarly.

// ---{ 04.09.2019  }---



#include <Enrf24.h>
#include <nRF24L01.h>
#include <string.h> 
#include <SPI.h>

#include <Stepper.h>

const int stepsPerRevolution = 2048;  //Dependent on stepper you are using, check datasheet.

Stepper stepper(stepsPerRevolution, A0, A2, A1, A3); // This should have been as in1, in2, in3, in4 but for some reason it does not work like that but works on this arrange. IDK...



Enrf24 nRF(4, 10, 2);  // CE , CSN/CS/SS , IRQ 

const byte address1[] = { 0xDE, 0xAD, 0xBE, 0x0F, 0x01 };  //0xDE, 0xAD, 0xBE, 0x0F, 0x01    Setting the address which NRF modules will communicate on.

 char data1[33]; //temporary storage for receiving data as char type. I programmed the controller to send all the data on one long string of characters.

 

  bool b1;    //
  bool b2;    //
  bool b3;    //for stepper motors
  bool b4;    //
  bool b5;    //
  bool b6;    //
  bool tgs1;

  bool limButtonB;
  bool limButtonF;
  int limPot;


  

  
void setup() 
{
  SPI.begin(); 
  SPI.setDataMode(SPI_MODE0); 
  SPI.setBitOrder(MSBFIRST); 

  nRF.begin(1000000,125); // datarate 250000/1000000/2000000, channel 0/125 (Note that lower channels may interfere with WiFi signals)
  nRF.enableRX();  // Start listening.

  stepper.setSpeed(15);  // Setting the rpm of the stepper motor, check datasheet to find on what range of rmp your stepper can work.

  Serial.begin(9600);
 

  pinMode(A4, OUTPUT);    //Control pins for swithcing amongst steppers
  pinMode(A5, OUTPUT);    //
  pinMode(7, OUTPUT);     //
 
  nRF.setRXaddress(address1);
}




void loop()
{    
      nRF.read(data1);       //Store the incoming data at the array 'data1'.
 
      

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

      



          
         
          if(b1 || b2) { digitalWrite(A4, HIGH);  digitalWrite(A5, LOW);  digitalWrite(7, LOW); }   //
          if(b3 || b4) { digitalWrite(A5, HIGH);  digitalWrite(A4, LOW);  digitalWrite(7, LOW); }   // Stepper swithcing controlls.
          if(b5 || b6) { digitalWrite(7, HIGH);  digitalWrite(A4, LOW);  digitalWrite(A5, LOW); }   //

          if(!b1 && !b2 && !b3 && !b4 && !b5 && !b6) { digitalWrite(A4, LOW);  digitalWrite(A5, LOW);  digitalWrite(7, LOW); }  //Shutting stepper drive cards down when they are not being used to prevent heating on steppers.

          limPot = analogRead(A7);
          if(100 <= analogRead(A6)&& analogRead(A6) <= 600) { limButtonB = true; }
          else if(600 < analogRead(A6)) { limButtonF = true; }
          else { limButtonF = false;   limButtonB = false;  }
          
          
          
            if(analogRead(A7) > 50 &&!limButtonB && (b1 || b4 || b5)) { stepper.step(25); }    
            
            if(analogRead(A7) < 810 &&!limButtonF && (b2 || b3 || b6)) { stepper.step(-25); } 

            Serial.print("B1:");
            Serial.print(b1);
            Serial.print(" B2:");
            Serial.print(b2);
            Serial.print(" B3:");
            Serial.print(b3);
            Serial.print(" B4:");
            Serial.print(b4);
            Serial.print(" B5:");
            Serial.print(b5);
            Serial.print(" B6:");
            Serial.print(b6);
            Serial.print(" Pot:");

            Serial.println(analogRead(A7)); // 400-1023 (-200)
                         
            
          
            
          
          
       

         

}
