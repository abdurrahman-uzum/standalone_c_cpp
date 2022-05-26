
#include <Stepper.h>

const int stepsPerRevolution = 2048;

Stepper stepper1 = Stepper(stepsPerRevolution, 2, 4, 3, 5);//8 10 9 11


void setup()
{
  stepper1.setSpeed(10);

  pinMode(9, OUTPUT); //stepper2

}
void loop() 
{

 if (digitalRead(A0) == HIGH || digitalRead(A1) == HIGH) {digitalWrite(9, HIGH); }
 else if (digitalRead(A2) == HIGH || digitalRead(A3) == HIGH) { digitalWrite(9, LOW); } 


 while(digitalRead(A0)==HIGH || digitalRead(A2) == HIGH) {
  stepper1.step(25);
 }

 while(digitalRead(A1)==HIGH || digitalRead(A3) == HIGH) {
  stepper1.step(-25);
 }
 
 
}
