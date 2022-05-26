/*Example sketch to control a 28BYJ-48 stepper motor with ULN2003 driver board, and Arduino UNO. More info: https://www.makerguides.com */
// Include the Arduino Stepper Library:
#include <Stepper.h>
#include <Servo.h>
// Number of steps per rotation:
const int stepsPerRevolution = 2048;
//Wiring:
// Pin 8 to IN1 on the ULN2003 driver
// Pin 9 to IN2 on the ULN2003 driver
// Pin 10 to IN3 on the ULN2003 driver
// Pin 11 to IN4 on the ULN2003 driver
// Create stepper object called 'myStepper', note the pin order:
Stepper stepper1 = Stepper(stepsPerRevolution, 6, 8, 7, 9);//8 10 9 11
Stepper stepper2 = Stepper(stepsPerRevolution, 0, 2, 1, 3);

Servo servo;

void setup()
{
  stepper1.setSpeed(10);
  stepper2.setSpeed(10);
  
 // servo.attach(5);

 // Serial.begin(9600);
  
//  pinMode(2, INPUT); //stepper1
 // pinMode(3, INPUT);

  pinMode(6, INPUT); //stepper2
  pinMode(7, INPUT);
}
void loop() 
{
 int pot = map(analogRead(A0),0,1024,0,180);
 servo.write(pot);
 
 /*while(digitalRead(2) == HIGH) {
  stepper1.step(25);
 }

 while(digitalRead(3) == HIGH) {
  stepper1.step(-25);
 }*/

 while(digitalRead(6) == HIGH) {
  stepper2.step(-25);
 }

 while(digitalRead(7) == HIGH) {
  stepper2.step(25);
 }
 
}
