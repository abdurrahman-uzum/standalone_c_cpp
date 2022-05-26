#include "game.h"
#include "tetromino.h"

const Square gameBoundary = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };

const int PLAYGROUND_WIDTH = SCREEN_WIDTH/Tetromino::C_LENGTH;
const int PLAYGROUND_HEIGHT = SCREEN_HEIGHT/Tetromino::C_LENGTH;

Square statics[48/Tetromino::C_LENGTH][84/Tetromino::C_LENGTH];

const Square nullRect = { 0, 0, 0, 0 };


void initializeFixedBlocks()
{
    for ( int j=0; j < PLAYGROUND_HEIGHT; j++ )
    {
        for ( int i=0; i < PLAYGROUND_WIDTH; i++ )
        {
            statics[i][j] = nullRect;
        }
    }
}

void renderFixedBlokcs()
{
    for ( int j=0; j < PLAYGROUND_HEIGHT; j++ )
    {
        for ( int i=0; i < PLAYGROUND_WIDTH; i++ )

        display.fillRect( statics[i][j].x, statics[i][j].y, Tetromino::C_LENGTH, Tetromino::C_LENGTH, BLACK );
    }
}

int detectFullLine()
{
    int filled = 0;
    int detected = 0;
    int linesToBeDestroyed[4] = { 0 };

    for ( int j=0; j < PLAYGROUND_HEIGHT; j++ )
    {
        for ( int i=0; i < PLAYGROUND_WIDTH; i++ )
        {
            if ( statics[i][j].w != 0 )
            {
                filled++;
            }
        }
        if ( filled >= 22 )
        {
            linesToBeDestroyed[detected] = j;

            detected++;
        }
        filled = 0;
    }

    if ( detected )
    {
        blinkLine( linesToBeDestroyed );
        destroyFullLine( linesToBeDestroyed );
    }

    return detected;
}


void destroyFullLine( int* row )
{
    for ( int k=0; k < 4; k++ )
    {
        for ( int j = row[k]; j > 1; j-- )
        {
            for ( int i=0; i < PLAYGROUND_WIDTH; i++ )
            {
                statics[i][j] = statics[i][j-1];
                statics[i][j].y += Tetromino::C_LENGTH;
            }
        }
    }
}


bool isGameOver()
{
    for ( int i=0; i < PLAYGROUND_WIDTH; i++ )
    {
        if ( statics[i][5].w != 0 )
        {
            return true;
        }
    }

    return false;
}


void restart( Tetromino& tetromino )
{
    initializeFixedBlocks();

    tetromino.score = 0;
}
