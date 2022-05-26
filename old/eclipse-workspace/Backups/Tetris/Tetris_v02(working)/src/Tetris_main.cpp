#include <iostream>

#include "Globals.h"

#include "Tetromino.h"



const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 720;

const int PLAYGROUND_WIDTH = 23;
const int PLAYGROUND_HEIGHT = 35;

const SDL_Rect nullRect = { 0, 0, 0, 0 };

SDL_Window* window = nullptr;
SDL_Renderer* gRenderer = nullptr;

const SDL_Rect gameBoundary = { 20, 20, 440, 680 };
const SDL_Rect scoreBox = { 500, 10, 110, 70 };
const SDL_Rect nextTetrBox = { 500, 110, 110, 110 };
const SDL_Rect pauseBox = { 500, 540, 110, 70 };
const SDL_Rect exitBox = { 500, 640, 110, 70 };

SDL_Rect statics[PLAYGROUND_WIDTH][PLAYGROUND_HEIGHT];


bool init()
{
	if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "Failed to initialize SDL. Error: %s\n", SDL_GetError() );
		return false;
	}


	if ( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
	{
		printf( "Warning! Linear texture filtering not enabled. ( Idk what it means though... )\n" );
	}


	window = SDL_CreateWindow( "Tetris", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
	if ( window == nullptr )
	{
		printf( "Failed to create window. Error: %s\n", SDL_GetError() );
		return false;
	}


	gRenderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
	if ( gRenderer == nullptr )
	{
		printf( "Failed to create renderer. Error: %s\n", SDL_GetError() );
		return false;
	}

	SDL_SetRenderDrawColor( gRenderer, 0xff, 0xff, 0xff, 0xff );


	return true;
}



void close()
{
	SDL_DestroyWindow( window );
	window = nullptr;

	SDL_DestroyRenderer( gRenderer );
	gRenderer = nullptr;

	SDL_Quit();
}


void clear()
{
	SDL_SetRenderDrawColor( gRenderer, LIGHT_GREEN );
	SDL_RenderClear( gRenderer );
}


void renderBackground()
{
	SDL_SetRenderDrawColor( gRenderer, DARK_GREEN );

	SDL_RenderDrawRect( gRenderer, &gameBoundary );
	SDL_RenderDrawRect( gRenderer, &scoreBox );
	SDL_RenderDrawRect( gRenderer, &nextTetrBox );
	SDL_RenderDrawRect( gRenderer, &pauseBox );
	SDL_RenderDrawRect( gRenderer, &exitBox );

	SDL_SetRenderDrawColor( gRenderer, 188, 218, 98, 0xFF );

	for ( int i=1; i < 34; i++ )
	{
		SDL_RenderDrawLine( gRenderer, 21, (20 + i*Tetromino::C_LENGTH), 458, (20 + i*Tetromino::C_LENGTH)  );
	}

	for ( int i=1; i < 22; i++ )
	{
		SDL_RenderDrawLine( gRenderer, (20 + i*Tetromino::C_LENGTH), 21, (20 + i*Tetromino::C_LENGTH), 698  );
	}
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



void renderFixedBlocks()
{
	SDL_SetRenderDrawColor( gRenderer, DARK_GREEN );

	for ( int j=0; j < PLAYGROUND_HEIGHT; j++ )
	{
		for ( int i=0; i < PLAYGROUND_WIDTH; i++ )
		SDL_RenderFillRect( gRenderer, &statics[i][j] );
	}
}




int main ( int argc, char* argv[] )
{
	if ( !init() )
	{
		exit(-1);
	}

	SDL_Delay(3000);

	bool quit = false;

	SDL_Event e;

	Timer timer;

	initializeFixedBlocks();

	Tetromino tetromino(L);



	while ( !quit )
	{
		while ( SDL_PollEvent( &e ) )
		{
			if ( e.type == SDL_QUIT )
			{
				quit = true;
			}
			tetromino.applyEvent(e);
		}

		double timeStep = timer.getTicks() / 1000.f;

		tetromino.update(timeStep);

		//detectFullLine();

		timer.start();

		clear();

		renderBackground();
		renderFixedBlocks();

		tetromino.render();



		SDL_RenderPresent( gRenderer );










	}// main loop end







	return 0;
}






























