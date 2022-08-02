#define MOTOR1_A 5
#define MOTOR1_B 6
#define MOTOR2_A 9
#define MOTOR2_B 10

#define TURN_DELAY 1000

#define SPEED 255


void forward ( int vel )
{
  analogWrite ( MOTOR1_A, vel );
  analogWrite ( MOTOR2_A, vel );

  digitalWrite ( MOTOR1_B, LOW );
  digitalWrite ( MOTOR2_B, LOW );
}

void backward ( int vel )
{
  analogWrite ( MOTOR1_B, vel );
  analogWrite ( MOTOR2_B, vel );

  digitalWrite ( MOTOR1_A, LOW );
  digitalWrite ( MOTOR2_A, LOW );
}

void right ( int vel )
{
  digitalWrite ( MOTOR1_B, LOW );
  digitalWrite ( MOTOR2_A, LOW );
  
  analogWrite ( MOTOR1_A, vel );
  analogWrite ( MOTOR2_B, vel );
  
  delay ( TURN_DELAY );
  
  analogWrite ( MOTOR1_A, 0 );
  analogWrite ( MOTOR2_B, 0 );
}

void left ( int vel )
{
  digitalWrite ( MOTOR1_A, LOW );
  digitalWrite ( MOTOR2_B, LOW );
  
  analogWrite ( MOTOR1_B, vel );
  analogWrite ( MOTOR2_A, vel );

  delay ( TURN_DELAY );

  analogWrite ( MOTOR1_B, 0 );
  analogWrite ( MOTOR2_A, 0 );
  
}

void idle()
{
  digitalWrite ( MOTOR1_A, LOW );
  digitalWrite ( MOTOR1_B, LOW );
  digitalWrite ( MOTOR2_A, LOW );
  digitalWrite ( MOTOR2_B, LOW );
}


void setup()
{
  pinMode(MOTOR1_A, OUTPUT);  
  pinMode(MOTOR1_B, OUTPUT); 
  pinMode(MOTOR2_A, OUTPUT); 
  pinMode(MOTOR2_B, OUTPUT); 
}

void loop()
{
   bool fw = digitalRead(A0);
   bool bw = digitalRead(A1);
   bool r = digitalRead(A2);
   bool l = digitalRead(A3);

   if ( fw ) { forward(SPEED); }
   else if ( bw ) { backward(SPEED); }
   else if ( r ) { right(SPEED); }
   else if ( l ) { left(SPEED); }
   else { idle(); }

  


















 

}
