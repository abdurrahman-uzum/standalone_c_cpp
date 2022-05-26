#include <WiFi.h>
#include <WebServer.h>
#include <ArduinoOTA.h>

String command;

const int RB = 18;
const int RF = 19;
const int LB = 16;
const int LF = 17;
const int HORN = 13;

const int freq = 5000;

const int c_RB = 0;
const int c_RF = 1;
const int c_LB = 2;
const int c_LF = 3;

const int res = 10;

int level = 0;

WebServer server(80);
unsigned long previous_millis = 0;
String sta_ssid = "Xperia XZ";
String sta_password = "1234567890.";

void HTTP_handleRoot( void )
{
    server.send( 200, "text/html", "" );

    if ( server.hasArg("State") )
    {
        Serial.println(server.arg("State") );
    }
}

void setup()
{
    Serial.begin(115200);

//    pinMode( LF, OUTPUT );
//    pinMode( RF, OUTPUT );
//    pinMode( LB, OUTPUT );
//    pinMode( RB, OUTPUT );

    ledcSetup( c_LF, freq, res );
    ledcSetup( c_RF, freq, res );
    ledcSetup( c_LB, freq, res );
    ledcSetup( c_RB, freq, res );

    ledcAttachPin( LF, c_LF );
    ledcAttachPin( RF, c_RF );
    ledcAttachPin( LB, c_LB );
    ledcAttachPin( RB, c_RB );

    pinMode ( HORN ,OUTPUT );

    
    

    String chip_id = "12356789abcdef";
    int i = chip_id.length() - 4;
    chip_id = chip_id.substring(i);
    chip_id = "wificar-" + chip_id; 
    String hostname( chip_id );
    

    Serial.println();
    Serial.println( "Hostname: " + hostname );

    WiFi.mode( WIFI_STA );
    WiFi.begin( sta_ssid.c_str(), sta_password.c_str() );

    Serial.print( "Connecting to:" );
    Serial.print( sta_ssid );

    unsigned long current_millis = millis();
    previous_millis = current_millis;

    while ( WiFi.status() != WL_CONNECTED && current_millis - previous_millis <= 2000 ) 
    {
        delay( 500 );
        Serial.print(".");
        current_millis = millis();
    }

    if ( WiFi.status() == WL_CONNECTED ) 
    {
        Serial.println("");
        Serial.print( "Connected. IP: " );
        Serial.println( WiFi.localIP() );
        delay(3000);
    }
    else
    {
        WiFi.mode( WIFI_AP );
        WiFi.softAP( hostname.c_str() );
        IPAddress myIP = WiFi.softAPIP();
        Serial.println("");
        Serial.println( "Failed to connect to " + sta_ssid );
        Serial.println( "WiFi-AP-Mode" );
        Serial.println( "AP IP address: " );
        Serial.println( myIP );
        delay(3000);
    }

    server.on( "/", HTTP_handleRoot );
    server.onNotFound( HTTP_handleRoot );
    server.begin();

    ArduinoOTA.begin();   
}


void forward()
{
    ledcWrite( c_RB, 0 );
    ledcWrite( c_LB, 0 );
    
    ledcWrite( c_RF, level );
    ledcWrite( c_LF, level );
}

void backward()
{
    ledcWrite( c_RF, 0 );
    ledcWrite( c_LF, 0 );
    
    ledcWrite( c_RB, level );
    ledcWrite( c_LB, level );
}

void right()
{
    ledcWrite( c_LB, 0 );    
    ledcWrite( c_RF, 0 );
    
    ledcWrite( c_RB, level );
    ledcWrite( c_LF, level );   
}

void left()
{
    ledcWrite( c_RB, 0 );
    ledcWrite( c_LF, 0 ); 
    
    ledcWrite( c_LB, level );    
    ledcWrite( c_RF, level );
}

void forward_left()
{
    ledcWrite( c_RB, 0 );
    ledcWrite( c_LB, 0 );
         
    ledcWrite( c_LF, (int)(level/1.2) );     
    ledcWrite( c_RF, level );
}

void forward_right()
{
    ledcWrite( c_RB, 0 );    
    ledcWrite( c_LB, 0 ); 
       
    ledcWrite( c_RF, (int)(level/1.2) );
    ledcWrite( c_LF, level ); 
}

void backward_left()
{   
    ledcWrite( c_RF, 0 );
    ledcWrite( c_LF, 0 ); 
    
    ledcWrite( c_LB, (int)(level/1.2) ); 
    ledcWrite( c_RB, level );    
}

void backward_right()
{
    ledcWrite( c_RF, 0 );
    ledcWrite( c_LF, 0 ); 
       
    ledcWrite( c_RB, (int)(level/1.2) );    
    ledcWrite( c_LB, level );    
}
    

void idle()
{
    ledcWrite( c_RB, 0 );
    ledcWrite( c_LF, 0 ); 
    
    ledcWrite( c_LB, 0 );    
    ledcWrite( c_RF, 0 );

    digitalWrite( HORN, LOW );
}



void loop()
{

    
    ArduinoOTA.handle();
    server.handleClient();

    command = server.arg("State");

    Serial.println( "Incoming command: " + command );

    
    if ( command == "F" )
    {
        forward();
    }
    else if ( command == "B" )
    {
        backward();
    }
    else if ( command == "L" )
    {
        left();
    }
    else if ( command == "R" )
    {
        right();
    }
    else if ( command == "G" )
    {
        forward_left();
    }
    else if ( command == "I" )
    {
        forward_right();
    }
    else if ( command == "H" )
    {
        backward_left();
    }
    else if ( command == "J" )
    {
        backward_right();
    }
    else if ( command == "V" )
    {
        digitalWrite( HORN, HIGH );
    }
    else if ( command == "S" || command.toInt() == 0 || command == NULL )
    {
        idle();
    }

    else if ( command == "q"  )
    {
        level = 1023;
    }
    else if ( command.toInt() >= 1 && command.toInt() < 10  )
    {
        level = map( command.toInt(), 1, 9, 650, 982 );
    }
   

}










































    
