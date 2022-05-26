#include <math.h>



#define MOTOR_R_F 10
#define MOTOR_R_B 9

#define MOTOR_L_F 6
#define MOTOR_L_B 5

#define VEL 75

int readForward()
{
  return map(analogRead(A2), 0, 1024, 0, 255);
}
int readRight()
{
  return map(analogRead(A1), 0, 1024, 0, 255);
}
int readLeft()
{
  return map(analogRead(A0), 0, 1024, 0, 255);
}


void setup()
{
  Serial.begin(9600);

  pinMode(MOTOR_R_F, OUTPUT);
  pinMode(MOTOR_R_B, OUTPUT);

  pinMode(MOTOR_L_F, OUTPUT);
  pinMode(MOTOR_L_B, OUTPUT);
}


void loop()
{
  int difference =  readRight() - readLeft();
  
  difference = abs(difference)>15 ? difference : 0;
  
  Serial.print(readForward());
  Serial.print(" | ");
  Serial.print(readRight());
  Serial.print(" | ");
  Serial.print(readLeft());
  Serial.print("  :  ");
  Serial.println(difference);
  
  


    
  



  
  
  
}
