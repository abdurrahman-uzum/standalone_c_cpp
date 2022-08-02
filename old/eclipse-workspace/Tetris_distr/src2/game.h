#ifndef GAME_H_
#define GAME_H_

#include "globals.h"
#include "Tetromino.h"

extern const int PLAYGROUND_WIDTH;
extern const int PLAYGROUND_HEIGHT;

extern const SDL_Rect gameBoundary;
extern const SDL_Rect scoreBox;
extern const SDL_Rect nextTetrBox;





void clear();
void initializeFixedBlocks();

void renderBackground();
void renderScoreBox( Tetromino& );
void renderNextTetromino();
void renderFixedBlocks();
void renderGameOver( Tetromino& );



int detectFullLine();
void blinkLine( int* );
void destroyFullLine( int* );
Type getNextTetromino();

bool isGameOver();
void restart( Tetromino& );













#endif /* GAME_H_ */
