#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <string>

#include "Texture.h"
#include "Object.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;

Texture someTexture;

bool init();
bool loadMedia();
void close();


bool init()
{
	bool success = true;

	if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "Failed to initialize SDL: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		if ( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!\n" );
		}
		gWindow = SDL_CreateWindow( "Box", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if ( gWindow == NULL )
		{
			printf( "Failed to create window: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if ( gRenderer == NULL )
			{
				printf( "Failed to create renderer: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				SDL_SetRenderDrawColor( gRenderer, 0xff, 0xff, 0xff, 0xff );

				if ( !(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG ) )
				{
					printf( "Failed to initalize SDL_image: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMedia()
{
	bool success = true;

	if ( !someTexture.load("C:/Users/Abdurrahman/eclipse-workspace/Box/media/box.png") )
	{
		printf( "Unsuccessful call to function Texture::load()\n" );
		success = false;
	}

	return success;
}

void close()
{
	SDL_DestroyRenderer( gRenderer );
	gRenderer = NULL;

	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	IMG_Quit();
	SDL_Quit();
}


void clear()
{
	SDL_SetRenderDrawColor( gRenderer, 0xff, 0xff, 0xff, 0xff );
	SDL_RenderClear( gRenderer );
}




int main ( int args, char* argv[] )
{
	if ( init() && loadMedia() )
	{
		Timer stepTimer;

		SDL_Event e;
		Object box;

		SDL_Rect wall1 = { 300, 440, 80, 40 };
		SDL_Rect wall2 = { 300, 100, 40, 40 };

		SDL_Rect obstacles[] = { wall1, wall2 };


		box.setTexture( "C:/Users/Abdurrahman/eclipse-workspace/Box/media/box.png" );


		bool quit = false;

		while ( !quit )
		{
			while ( SDL_PollEvent(&e) != 0 )
			{
				if ( e.type == SDL_QUIT ) { quit = true; }

				box.applyEvent( e );
			}

			double timeStep = stepTimer.getTicks() / 1000.f;

			clear();

			SDL_SetRenderDrawColor( gRenderer, 0, 0, 0, 0xff );
			SDL_RenderDrawRect( gRenderer, &wall1 );
			SDL_RenderDrawRect( gRenderer, &wall2 );

			box.update( timeStep, obstacles, sizeof(obstacles)/sizeof(SDL_Rect) );

			stepTimer.restart();


			SDL_RenderPresent( gRenderer );


		}
	}








	return 0;
}

