#include <string.h>
#define MOTOR_R_F 10
#define MOTOR_R_B 9

#define MOTOR_L_F 6
#define MOTOR_L_B 5

#define VEL 255

#define TURN_DELAY 300

#define LED 13

int difference;
int correcter;



int readForward()
{
  return map(analogRead(A2), 0, 1024, 0, VEL);
}

int readRight()
{
  return map(analogRead(A1), 0, 1024, 0, VEL);
}

int readLeft()
{
  return map(analogRead(A0), 0, 1024, 0, VEL);
}


void forward ( int vel )
{
    digitalWrite(MOTOR_R_B, LOW);
    digitalWrite(MOTOR_L_B, LOW);
    
    int difference =  readRight() - readLeft();
    difference = abs(difference)>15 ? difference : 0;
    correcter = difference>0 ? difference+(VEL/5) : difference-(VEL/5);
    //if ( abs(correcter) >= VEL ) { correcter = VEL; }

    if( correcter > 0 )
    {
      digitalWrite(LED, HIGH); 
              
      analogWrite(MOTOR_R_F, VEL);
      analogWrite(MOTOR_L_F, VEL - correcter);
    }

    else if ( correcter < 0 )
    {
      digitalWrite(LED, HIGH);
      
      analogWrite(MOTOR_R_F, VEL + correcter);
      analogWrite(MOTOR_L_F, VEL);      
    }
    
    else
    {
      digitalWrite(LED, LOW);
      
      analogWrite(MOTOR_R_F, VEL);
      analogWrite(MOTOR_L_F, VEL);
    }
}



void right ( int vel )
{
    digitalWrite(MOTOR_R_F, LOW);
    digitalWrite(MOTOR_L_B, LOW);

    analogWrite(MOTOR_R_B, vel);
    analogWrite(MOTOR_L_F, vel);

    delay ( TURN_DELAY );

    digitalWrite(MOTOR_R_B, LOW);
    digitalWrite(MOTOR_L_F, LOW); 
}



void left ( int vel )
{
    digitalWrite(MOTOR_R_B, LOW);
    digitalWrite(MOTOR_L_F, LOW);

    analogWrite(MOTOR_R_F, vel);
    analogWrite(MOTOR_L_B, vel);

    delay ( TURN_DELAY );

    digitalWrite(MOTOR_R_F, LOW);
    digitalWrite(MOTOR_L_B, LOW); 
}


void idle ()
{
  digitalWrite ( MOTOR_R_F, LOW );
  digitalWrite ( MOTOR_R_B, LOW );
  digitalWrite ( MOTOR_L_F, LOW );
  digitalWrite ( MOTOR_L_B, LOW );
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
  
  while(0)
  {
    Serial.print(readForward());
    Serial.print("   ");
    Serial.print(readRight());
    Serial.print("   ");
    Serial.println(readLeft());
  }

  while ( readForward() <= 50 )
  {
      forward(VEL);
  } 
    
  if ( readLeft() < readRight() && readLeft() <=30  )
  {
      left(VEL);
  }
  else if ( readRight() < readLeft() && readRight <= 30 )
  {
      right(VEL);
  }
  else
  {      
      idle();
  }


















  
  
}
