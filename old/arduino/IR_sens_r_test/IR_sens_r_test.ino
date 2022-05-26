void setup() {
    Serial.begin(9600);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);

}

void loop() {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);

    if ( digitalRead(A2) )
    {
        digitalWrite(2, LOW);
    }

    if ( analogRead(A0) > 750 )
    {
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW );
    }

    if ( analogRead(A1) > 780 )
    {
        digitalWrite( 3, HIGH );
    }

}
