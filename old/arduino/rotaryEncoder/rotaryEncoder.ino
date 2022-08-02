//these pins can not be changed 2/3 are special pins
int encoderPin1 = 2;
int encoderPin2 = 3;

volatile int lastEncoded = 0;
volatile long encoderValue = 0;

long lastencoderValue = 0;

int lastMSB = 0;
int lastLSB = 0;

bool cw = false;

int duration;

void updateEncoder(void);

void setup() 
{
    Serial.begin (9600);
    
    pinMode(encoderPin1, INPUT);
    pinMode(encoderPin2, INPUT);
    
    digitalWrite(encoderPin1, HIGH); //turn pullup resistor on
    digitalWrite(encoderPin2, HIGH); //turn pullup resistor on
    
    //call updateEncoder() when any high/low changed seen
    //on interrupt 0 (pin 2), or interrupt 1 (pin 3)
    attachInterrupt(0, updateEncoder, CHANGE);
    attachInterrupt(1, updateEncoder, CHANGE);

}

unsigned long chr;

void loop()
{  
    int tour = (encoderValue/4)/24;
    
    int steps = encoderValue/4;
    
    bool looped = steps%24==0 ? 1 : 0;
    
    if ( looped )
    {
      duration = millis() - chr;
      chr = millis();
    }
    
    Serial.print("Steps:");
    Serial.print(steps);
    
    Serial.print("   Tour:");
    Serial.print(tour);
    
    Serial.print("   Direction:");
    if ( cw ) { Serial.print("cw"); }
    else { Serial.print("ccw"); }
    
    Serial.print("   Period:");
    Serial.println(duration);

    

    
    
}































void updateEncoder()
{   
    int MSB = digitalRead(encoderPin1); //MSB = most significant bit
    int LSB = digitalRead(encoderPin2); //LSB = least significant bit 
    
    int encoded = (MSB << 1) | LSB; 
    //converting the 2 pin value to single number 
    
    int sum = (lastEncoded << 2) | encoded; 
    //adding it to the previous encoded value 
    
    if(sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) 
    {
        encoderValue++; 
        cw = false;       
    }
     
    if(sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) 
    { 
      encoderValue--; 
      cw = true; 
    }
     
    lastEncoded = encoded; 
    //store this value for next time 
}
