//these pins can not be changed 2/3 are special pins
int encoderPin1 = 2;
int encoderPin2 = 3;

volatile int lastEncoded = 0;
volatile long encoderValue = 0;

long lastencoderValue = 0;

int lastMSB = 0;
int lastLSB = 0;

bool cw = false;  // Yön

int duration;  //İki step arası periyot

unsigned long time;





void setup() 
{
    Serial.begin (9600);
    
    pinMode(encoderPin1, INPUT);
    pinMode(encoderPin2, INPUT);
    
    digitalWrite(encoderPin1, HIGH); 
    digitalWrite(encoderPin2, HIGH); 
    
    attachInterrupt(0, updateEncoder, CHANGE);
    attachInterrupt(1, updateEncoder, CHANGE);

}



void loop()
{  
    int steps = encoderValue/4;
    int tour = steps/24;
    static int prevStep = 0;

    //Eğer step sayısı değiştiyse:
    
    if ( prevStep != steps )
    {
      prevStep = steps;

      duration = millis()-time;
      time = millis();
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
