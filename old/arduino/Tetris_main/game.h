#ifndef _GAME_H
#define _GAME_H

#include "globals.h"
#include "tetromino.h"

extern int const PLAYGROUND_WIDTH;
extern int const PLAYGROUND_HEIGHT;

extern const Square gameBoundary;
extern const Square scoreBox;
extern const Square nextTetrBox;

void clear();
void initializeFixedBlocks();

void renderFixedBlocks();

int detectFullLine();
void blinkLine( int* );
void destroyFullLine( int* );

bool isGameOver();
void restart( Tetromino& );




#endif