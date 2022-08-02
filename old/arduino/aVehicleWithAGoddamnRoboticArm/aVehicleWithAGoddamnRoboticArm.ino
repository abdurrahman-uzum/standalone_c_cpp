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
#include <Servo.h>

const int stepsPerRevolution = 2048;  //Dependent on stepper you are using, check datasheet.

Stepper stepper(stepsPerRevolution, A0, A2, A1, A3); // This should have been as in1, in2, in3, in4 but for some reason it does not work like that but works on this arrange. IDK...

Servo servo;      //Servo for robotic arm
Servo steering;   //Servo for steering the vehicle

Enrf24 nRF(4, 10, 2);  // CE , CSN/CS/SS , IRQ 

const byte address1[] = { 0xDE, 0xAD, 0xBE, 0x0F, 0x01 };  //0xDE, 0xAD, 0xBE, 0x0F, 0x01    Setting the address which NRF modules will communicate on.

 char data1[33]; //temporary storage for receiving data as char type. I programmed the controller to send all the data on one long string of characters.

 
  int j2x;    // steering.
  int j1y;    // direction and speed.
  int pot1;   // robotic arm to grab

  char jx[4];   //temporary storage
  char jy[4];
  char pot[4];

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

  stepper.setSpeed(10);  // Setting the rpm of the stepper motor, check datasheet to find on what range of rmp your stepper can work.

  steering.attach(9);
  servo.attach(8);

  pinMode(3, OUTPUT);   //PWM output pins for motor control.
  pinMode(5, OUTPUT);   //

  pinMode(A4, OUTPUT);    //Control pins for swithcing amongst steppers
  pinMode(A5, OUTPUT);    //
  pinMode(7, OUTPUT);     //
 
  nRF.setRXaddress(address1);
}

void forward() {                   // Reason why does functions exists even though
  analogWrite(3, j1y);             // commands are simple is because control mechanics 
}                                  // were lot more complicated on the first phase of the project.

void backward() {
  analogWrite(5, abs(j1y));
 }


void idle() { 
  digitalWrite(3, 0);
  digitalWrite(5, 0);
  
}


void loop()
{    
      nRF.read(data1);       //Store the incoming data at the array 'data1'.
 
      jy[0] = data1[0];      // Transmitter sends data as a big continuous chunk of characters
      jy[1] = data1[1];      // we are taking digits as refernace points and storing each separate
      jy[2] = data1[2];      // data on different arrays.

      jx[0] = data1[3];
      jx[1] = data1[4];
      jx[2] = data1[5];

      pot[0] = data1[6];
      pot[1] = data1[7];
      pot[2] = data1[8];

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

      

     
      pot1 = map(atoi(pot), 0, 999, 10, 150);        // Converting the char form data to integer form and setting the proper range.
      j2x = map(atoi(jx), 100, 999, -40, 40);        //
      j1y = map(atoi(jy), 100, 999, -255, 255);      //

      const int midPoint = 87;          // Creating a constant for servo to be at to vehicle to go straight. It wasn't exactly 90 degrees in this case.
      int diviation = midPoint + j2x;   // Creating a variable on which we will add or substract the mapped value of x joystick, thus angle the front wheels.

          
          
          steering.write(diviation);  //Steering the vehicle
          if(-10 <= j1y <= 10)            { idle(); }         //
          if(j1y > 10  && -10 <= j2x <= 10) { forward(); }    // Vehicle controlls.
          if(j1y < -10 && -10 <= j2x <= 10) { backward(); }   //

          
         
         if(b1 || b2) { digitalWrite(A4, HIGH);  digitalWrite(A5, LOW);  digitalWrite(7, LOW); }   //
          if(b3 || b4) { digitalWrite(A5, HIGH);  digitalWrite(A4, LOW);  digitalWrite(7, LOW); }   // Stepper swithcing controlls.
          if(b5 || b6) { digitalWrite(7, HIGH);  digitalWrite(A4, LOW);  digitalWrite(A5, LOW); }   //

          if(!b1 && !b2 && !b3 && !b4 && !b5 && !b6) { digitalWrite(A4, LOW);  digitalWrite(A5, LOW);  digitalWrite(7, LOW); }  //Shutting stepper drive cards down when they are not being used to prevent heating on steppers.

          limPot = analogRead(A7);
          if(100 <= analogRead(A6)&& analogRead(A6) <= 600) { limButtonB = true; }
          else if(600 < analogRead(A6)) { limButtonF = true; }
          else { limButtonF = false;   limButtonB = false;  }
          
          
          
            if(analogRead(A7) > 40 &&!limButtonB && (b1 || b4 || b5)) { stepper.step(25); }    
            
            if(analogRead(A7) < 810 &&!limButtonF && (b2 || b3 || b6)) { stepper.step(-25); } 
          
            
          
          
          servo.write(pot1);      //Servo which is responsible for grasping of robotic arm.
       


          
         

}
