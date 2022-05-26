

#define MOTOR1_A 5
#define MOTOR1_B 6
#define MOTOR2_A 10
#define MOTOR2_B 11

#define TRIG_PIN_F 2
#define ECHO_PIN_F 3

#define TRIG_PIN_R 4
#define ECHO_PIN_R 7

#define TRIG_PIN_L 8
#define ECHO_PIN_L 9

#define CONSTANT 25




#define TURN_DELAY 750

#define SPEED 175




int forwardDistance() 
{
    long duration;
    int dis;
    
    digitalWrite(TRIG_PIN_F, LOW);
    delayMicroseconds(2);
    
    digitalWrite(TRIG_PIN_F, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN_F, LOW);
    
    duration = pulseIn(ECHO_PIN_F, HIGH);
    dis = duration*0.034/2;
  
    return dis;
}

int rightDistance() 
{
  
    long duration;
    int dis;
    
    digitalWrite(TRIG_PIN_R, LOW);
    delayMicroseconds(2);
    
    digitalWrite(TRIG_PIN_R, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN_R, LOW);
    
    duration = pulseIn(ECHO_PIN_R, HIGH);
    dis = duration*0.034/2;
  
    return dis;
}

int leftDistance() 
{
    long duration;
    int dis;
    
    digitalWrite(TRIG_PIN_L, LOW);
    delayMicroseconds(2);
    
    digitalWrite(TRIG_PIN_L, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN_L, LOW);
    
    duration = pulseIn(ECHO_PIN_L, HIGH);
    dis = duration*0.034/2;
  
    return dis;
}

// Aşağıdaki dört fonksiyon, gereken şekilde motorları sürerek aracın temel hareketlerini oluşturacaktır.

void forward ( int vel ) //İki motor da ileri.
{
    analogWrite ( MOTOR1_A, vel );
    analogWrite ( MOTOR2_A, vel );
  
    digitalWrite ( MOTOR1_B, LOW );
    digitalWrite ( MOTOR2_B, LOW );
}

void forward1 ( int vel ) //İki motor da ileri.
{
    int difference = rightDistance() - leftDistance();
    //Pozitif ise sola kayıyor

    int cVel;

    if ( difference <= 10 )
    {
        cVel = difference*CONSTANT;
    }
    else
    {
        cVel = 0;
    }

    if ( cVel > 0 )
    {
      analogWrite ( MOTOR1_A, vel );
      analogWrite ( MOTOR2_A, vel-cVel );
    
      digitalWrite ( MOTOR1_B, LOW );
      digitalWrite ( MOTOR2_B, LOW );
    }
    else if ( cVel < 0 )
    {
      analogWrite ( MOTOR1_A, vel + cVel );
      analogWrite ( MOTOR2_A, vel );
    
      digitalWrite ( MOTOR1_B, LOW );
      digitalWrite ( MOTOR2_B, LOW );
    }
    else 
    {
      analogWrite ( MOTOR1_A, vel );
      analogWrite ( MOTOR2_A, vel );
    
      digitalWrite ( MOTOR1_B, LOW );
      digitalWrite ( MOTOR2_B, LOW );    
    }
}

void backward ( int vel ) //İki motor da geri.
{
    analogWrite ( MOTOR1_B, vel );
    analogWrite ( MOTOR2_B, vel );
  
    digitalWrite ( MOTOR1_A, LOW );
    digitalWrite ( MOTOR2_A, LOW );
}

void right ( int vel )  //Sağ motor geri, sol motor iler.
{
    digitalWrite ( MOTOR1_B, LOW );
    digitalWrite ( MOTOR2_A, LOW );
    
    analogWrite ( MOTOR1_A, vel );
    analogWrite ( MOTOR2_B, vel );
    
    delay ( TURN_DELAY );
    
    analogWrite ( MOTOR1_A, 0 );
    analogWrite ( MOTOR2_B, 0 );
}

void left ( int vel )  //Sol motor geri, sağ motor ileri.
{
    digitalWrite ( MOTOR1_A, LOW );
    digitalWrite ( MOTOR2_B, LOW );
    
    analogWrite ( MOTOR1_B, vel );
    analogWrite ( MOTOR2_A, vel );
  
    delay ( TURN_DELAY );
  
    analogWrite ( MOTOR1_B, 0 );
    analogWrite ( MOTOR2_A, 0 );
}

void idle()  //Motorları durdur.
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
  
    pinMode(TRIG_PIN_F, OUTPUT); 
    pinMode(ECHO_PIN_F, INPUT); 

    pinMode(TRIG_PIN_R, OUTPUT); 
    pinMode(ECHO_PIN_R, INPUT); 

    pinMode(TRIG_PIN_L, OUTPUT); 
    pinMode(ECHO_PIN_L, INPUT); 
    
    Serial.begin(9600); 
}



void loop()
{

  while(forwardDistance()>10)
  {
    
    forward(255);
  }
  
 

  if(rightDistance()>leftDistance())
  {
    right(255);
  }
  else
  {
    left(255);
  }

  




  
  Serial.print("FORWARD: ");
  Serial.print(forwardDistance());

  Serial.print("     RIGHT: ");
  Serial.print(rightDistance());

  Serial.print("     LEFT: ");
  Serial.println(leftDistance());
  
  



























     
}
