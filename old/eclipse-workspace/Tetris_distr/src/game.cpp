#include "game.h"

const SDL_Rect gameBoundary = { 20, 20, 440, 680 };
const SDL_Rect scoreBox = { 470, 20, 160, 90 };
const SDL_Rect nextTetrBox = { 490, 150, 120, 120 };
const SDL_Rect nullRect = { 0, 0, 0, 0 };

const int PLAYGROUND_WIDTH = 23;
const int PLAYGROUND_HEIGHT = 35;

SDL_Rect statics[PLAYGROUND_WIDTH][PLAYGROUND_HEIGHT];

void clear()
{
	SDL_SetRenderDrawColor( gRenderer, LIGHT_GREEN );
	SDL_RenderClear( gRenderer );
}


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


void renderBackground()
{
	SDL_SetRenderDrawColor( gRenderer, 188, 218, 98, 0xFF );

	for ( int i=1; i < 34; i++ )
	{
		SDL_RenderDrawLine( gRenderer, 21, (20 + i*Tetromino::C_LENGTH), 458, (20 + i*Tetromino::C_LENGTH)  );
	}

	for ( int i=1; i < 22; i++ )
	{
		SDL_RenderDrawLine( gRenderer, (20 + i*Tetromino::C_LENGTH), 21, (20 + i*Tetromino::C_LENGTH), 698  );
	}


	SDL_SetRenderDrawColor( gRenderer, DARK_GREEN );

	SDL_RenderDrawRect( gRenderer, &gameBoundary );
	SDL_RenderDrawRect( gRenderer, &scoreBox );
	SDL_RenderDrawRect( gRenderer, &nextTetrBox );

	SDL_RenderDrawLine( gRenderer, 21, 120, 458, 120 );
}


void renderScoreBox( Tetromino& tetromino )
{
	static const int digit1_x = scoreBox.x + 10;
	static const int digit1_y = scoreBox.y + 10;

	static const int digit2_x = scoreBox.x + 60;
	static const int digit2_y = scoreBox.y + 10;

	static const int digit3_x = scoreBox.x + 110;
	static const int digit3_y = scoreBox.y + 10;

	int digit1 = 0;
	int digit2 = 0;
	int digit3 = 0;

	digit3 = ( tetromino.score % 10 );
	digit2 = (int)( tetromino.score % 100 ) / 10;
	digit1 = (int)tetromino.score/100;


	number[digit1].render( digit1_x, digit1_y );

	number[digit2].render( digit2_x, digit2_y );

	number[digit3].render( digit3_x, digit3_y );
}


void renderNextTetromino()
{
	nextTetrTexture[ getNextTetromino() ].render( nextTetrBox.x, nextTetrBox.y );
}


void renderFixedBlocks()
{
	SDL_SetRenderDrawColor( gRenderer, DARK_GREEN );

	for ( int j=0; j < PLAYGROUND_HEIGHT; j++ )
	{
		for ( int i=0; i < PLAYGROUND_WIDTH; i++ )
		SDL_RenderFillRect( gRenderer, &statics[i][j] );
	}
}


void renderGameOver( Tetromino& tetromino )
{
	SDL_Delay(1000);

	clear();
	gameOverTexture.render(0, 0);

	int digit3 = ( tetromino.score % 10 );
	int digit2 = (int)( tetromino.score % 100 ) / 10;
	int digit1 = (int)tetromino.score/100;

	number[digit1].render( 231 + 10, 476 + 10 );

	number[digit2].render( 231 + 60, 476 + 10 );

	number[digit3].render( 231 + 110, 476 + 10  );

	SDL_RenderPresent( gRenderer );
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


void blinkLine( int* j )
{
	for ( int i=0; i <= 3; i++ )
	{
		SDL_SetRenderDrawColor( gRenderer, LIGHT_GREEN );

		for ( int i=0; i < PLAYGROUND_WIDTH; i++ )
		{
			SDL_RenderFillRect( gRenderer, &statics[i][j[0]] );
			SDL_RenderFillRect( gRenderer, &statics[i][j[1]] );
			SDL_RenderFillRect( gRenderer, &statics[i][j[2]] );
			SDL_RenderFillRect( gRenderer, &statics[i][j[3]] );
		}

		SDL_SetRenderDrawColor( gRenderer, DARK_GREEN );
		SDL_RenderDrawRect( gRenderer, &gameBoundary );

		SDL_RenderPresent( gRenderer );

		SDL_Delay(200);

		SDL_SetRenderDrawColor( gRenderer, DARK_GREEN );

		for ( int i=0; i < PLAYGROUND_WIDTH; i++ )
		{
			SDL_RenderFillRect( gRenderer, &statics[i][j[0]] );
			SDL_RenderFillRect( gRenderer, &statics[i][j[1]] );
			SDL_RenderFillRect( gRenderer, &statics[i][j[2]] );
			SDL_RenderFillRect( gRenderer, &statics[i][j[3]] );
		}

		SDL_RenderPresent( gRenderer );

		SDL_Delay(200);
	}
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


Type getNextTetromino()
{
	return nextTetrominoType;
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


























