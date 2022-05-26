#include <Arduino.h>

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

#include "globals.h"
#include "game.h"

const int SCREEN_WIDTH = 48;
const int SCREEN_HEIGHT = 84;

Adafruit_PCD8544 display = Adafruit_PCD8544(5, 18, 19, 22, 23);

void setup()
{
    pinMode( UP, OUTPUT );
    pinMode( LEFT, OUTPUT );
    pinMode( DOWN, OUTPUT );
    pinMode( RIGHT, OUTPUT );
    pinMode( TOP_LEFT, OUTPUT );
    pinMode( TOP_RIGHT, OUTPUT );
    

    display.begin();
    display.setContrast(57);
    display.clearDisplay();

    // Draw Rectangle
    //display.drawRect(0, 0, 1, 1, BLACK);
    //display.display();

    randomSeed( analogRead(A0) );
    initializeFixedBlocks();

    Tetromino tetromino( Type( random(6) ) );
;

    while ( true )
    {
        //handle events
        tetromino.applyEvent();

        tetromino.update();
        if ( isGameOver() )
        {
            restart( tetromino );
        }
        else
        {
            display.clearDisplay();

            renderFixedBlocks();

            tetromino.render();
        }

        display.display();
        
    }


    
}

void loop()
{
}
