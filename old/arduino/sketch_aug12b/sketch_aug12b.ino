
#include <Stepper.h>

const int stepsPerRevolution = 2048;

Stepper stepper1 = Stepper(stepsPerRevolution, A0, A2, A1, A3);//8 10 9 11


void setup()
{
  stepper1.setSpeed(10);
  
  pinMode(6, INPUT); 
  pinMode(7, INPUT);

}
void loop() 
{

 while(digitalRead(6) == HIGH) {
  stepper1.step(25);
 }

 while(digitalRead(7) == HIGH) {
  stepper1.step(-25);
 }
}
