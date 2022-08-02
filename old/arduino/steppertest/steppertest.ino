/*Example sketch to control a 28BYJ-48 stepper motor with ULN2003 driver board, and Arduino UNO. More info: https://www.makerguides.com */
// Include the Arduino Stepper Library:
#include <Stepper.h>

// Number of steps per rotation:
const int stepsPerRevolution = 2048;
//Wiring:
// Pin 8 to IN1 on the ULN2003 driver
// Pin 9 to IN2 on the ULN2003 driver
// Pin 10 to IN3 on the ULN2003 driver
// Pin 11 to IN4 on the ULN2003 driver
// Create stepper object called 'myStepper', note the pin order:
Stepper stepper1 = Stepper(stepsPerRevolution, 8, 10, 9, 11);//8 10 9 11


void setup()
{
  stepper1.setSpeed(27);

  


  pinMode(5, INPUT);
  pinMode(6, INPUT);

  
}
void loop() {

  
  if(digitalRead(A0)) {
  stepper1.step(-1);
  }
  else if(digitalRead(A1)) {
  stepper1.step(1);
  }















}
