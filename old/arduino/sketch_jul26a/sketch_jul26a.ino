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
Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);
Servo servo;

void setup()
{
  // Set the speed to 5 rpm:
  myStepper.setSpeed(10);
  servo.attach(5);
  // Initialize the serial port:
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
}
void loop() 
{
 int pot = map(analogRead(A0),0,1024,0,180);
 servo.write(pot);
 
 while(digitalRead(2) == HIGH) {
  Serial.println("clockwise");
  myStepper.step(25);
  //delay(500);
  }

 while(digitalRead(3) == HIGH) {
  Serial.println("counterclockwise");
  myStepper.step(-25);
  //delay(500);
 }
}
