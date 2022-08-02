#define FORWARD 0
#define LEFT 1
#define RIGHT -1
#define BACK 2

// --- --- //

#define LEFT_MOTOR_F 5
#define LEFT_MOTOR_B 6

#define RIGHT_MOTOR_F 9
#define RIGHT_MOTOR_B 10

#define TURN_DELAY 350

#define SLOW_DOWN 100

int speed = 0;

// --- --- //

#define LEFT_SENSOR A1
#define RIGHT_SENSOR A0
#define BOTTOM_SENSOR 12

// --- --- //

#define ENC1_IN1 2
//#define ENC1_IN2 0

#define ENC2_IN1 3
//#define ENC2_IN2 1


// --- For Frontal Senor --- //

#include <Wire.h>
 
 // 7 highest bits
#define ADDRESS         (0x80 >> 1)
 
#define SHIFT_ADDR      0x35
#define DISTANCE_ADDR   0x5E
#define RIGHT_EDGE_ADDR 0xF8 // C
#define LEFT_EDGE_ADDR  0xF9 // A
#define PEAK_EDGE_ADDR  0xFA // B
 
uint8_t distance_raw[2] = { 0 };
uint8_t shift = 0;
uint8_t distance_cm = 0;
char buf[100];

// --- --- //


// --- For Encoders --- //

#define PPR 110 //pulses per rotation

volatile long encoderValue1 = 0;
volatile long encoderValue2 = 0;

int interval = 1000;

long previousMillis_1 = 0;
long previousMillis_2 = 0;

long currentMillis_1 = 0;
long currentMillis_2 = 0;

int rpm1 = 0;
int rpm2 = 0;

// --- --- //
 
void setup()
{
   pinMode(ENC1_IN1, INPUT_PULLUP);
   pinMode(ENC2_IN1, INPUT_PULLUP);

   attachInterrupt(digitalPinToInterrupt(ENC1_IN1), updateEncoder1, RISING);
   attachInterrupt(digitalPinToInterrupt(ENC2_IN1), updateEncoder2, RISING);

   previousMillis_1 = millis();
   previousMillis_2 = millis();
   
   
   Wire.begin();
   Serial.begin(9600);
 
   delay(2000);

   //
   //Serial.println("Initializing");
 
   Wire.beginTransmission(ADDRESS);
   Wire.write(byte(SHIFT_ADDR));
   Wire.endTransmission();
 
   Wire.requestFrom(ADDRESS, 1);
   if (1 <= Wire.available())
   {
      shift = Wire.read();
   }
 
   //Serial.print("Read shift bit: ");
   //Serial.println(shift, HEX);
}


 
void loop()
{
    updateRPM();
    //proceed(155);
        
    Serial.print("Sensor_F: "); Serial.print( readFront() );
    Serial.print("   Sensor_L: "); Serial.print( readLeft() );
    Serial.print("   Sensor_R: "); Serial.print( readRight() );
    Serial.print("   Sensor_B: "); Serial.println( digitalRead( BOTTOM_SENSOR ) );

    Serial.print("RPM_L: "); Serial.print(rpm1);
    Serial.print("   RPM_R: "); Serial.println(rpm2);

    Serial.println("----------------------------------------------------------------");
   
    delay(100);
}

void updateRPM()
{
    currentMillis_1 = millis();
    if (currentMillis_1 - previousMillis_1 > interval) 
    {
        previousMillis_1 = currentMillis_1;
        rpm1 = (float)(encoderValue1 * 60 / PPR );
    }

    currentMillis_2 = millis();
    if (currentMillis_2 - previousMillis_2 > interval) 
    {
        previousMillis_2 = currentMillis_2;
        rpm1 = (float)(encoderValue1 * 60 / PPR );
    }
}



double readFront()
{
    // Read basic measurement
   Wire.beginTransmission(ADDRESS);
   Wire.write(byte(DISTANCE_ADDR));
   Wire.endTransmission();
 
   Wire.requestFrom(ADDRESS, 2);
 
   if (2 <= Wire.available())
   {
      distance_raw[0] = Wire.read();
      distance_raw[1] = Wire.read();
 
      // Print distance in cm
      distance_cm = (distance_raw[0] * 16 + distance_raw[1]) / 16 / (int)pow(2, shift);
      return distance_cm;
   }
   else
   {
      return -1;
   }
}

int readLeft() { return analogRead( LEFT_SENSOR ); }
int readRight() { return analogRead( RIGHT_SENSOR ); }



void proceed ( int s )
{
    analogWrite ( RIGHT_MOTOR_B, 0 );
    analogWrite ( LEFT_MOTOR_B, 0 );

    analogWrite ( RIGHT_MOTOR_F, s );
    analogWrite ( LEFT_MOTOR_F, s );
}

int turn ( int where )
{
    int prevFORWARD = FORWARD;
    int prevRIGHT = RIGHT;
    int prevLEFT = LEFT;
    int prevBACK = BACK;

    if ( where == RIGHT )
    {
        analogWrite ( RIGHT_MOTOR_F, speed - SLOW_DOWN );
        delay ( TURN_DELAY );
        analogWrite ( RIGHT_MOTOR_F, speed );
    }

    else if ( where == LEFT )
    {
        analogWrite ( LEFT_MOTOR_F, (speed-SLOW_DOWN) );
        delay ( TURN_DELAY );
        analogWrite ( LEFT_MOTOR_F, speed );

    }

    else if ( where == BACK )
    {
        analogWrite ( RIGHT_MOTOR_F, speed );
        analogWrite ( LEFT_MOTOR_B, speed );
        delay ( TURN_DELAY );
        analogWrite ( LEFT_MOTOR_F, speed );

    }
    else
    {
        return -1;
    }
}


void updateEncoder1()
{
  // Increment value for each pulse from encoder
  encoderValue1++;
}

void updateEncoder2()
{
  // Increment value for each pulse from encoder
  encoderValue2++;
}
