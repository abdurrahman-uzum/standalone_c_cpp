#include <WiFi.h>
#include <WebServer.h>
#include <ArduinoOTA.h>

String command;
int SPEED = 1023;
int speed_coef = 3;

const int RB = 16;
const int RF = 17;
const int LB = 18;
const int LF = 19;

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

    while ( WiFi.status() != WL_CONNECTED && current_millis - previous_millis <= 10000 ) 
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

void loop()
{
    ArduinoOTA.handle();
    server.handleClient();

    command = server.arg("State");

    Serial.println( "Incoming command: " + command );
}    








































    
