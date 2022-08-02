#include "Screen.h"

Screen::Screen() : window(NULL)
{

}

Screen::~Screen()
{

}

bool Screen::init()
{
	if ( SDL_Init(SDL_INIT_VIDEO) < 0 )
	{
		printf( "Failed to initialize SDL: %s\n", SDL_GetError() );
		return false;
	}
	else
	{
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		window = SDL_CreateWindow ( "Window Name", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if ( window == NULL )
		{
			printf( "Failed to create window: %s\n", SDL_GetError() );
			return false;
		}
		else
		{
			renderer = SDL_CreateRenderer ( window, -1, SDL_RENDERER_ACCELERATED );
			if ( renderer == NULL )
			{
				printf( "Failed to create renderer: %s\n", SDL_GetError() );
				return false;
			}
			else
			{
				SDL_SetRenderDrawColor ( renderer, 0xff, 0xff, 0xff, 0xff );
			}
		}
	}

	return true;
}

void Screen::print()
{

}

void Screen::renderObject( SDL_Rect rect )
{
	SDL_SetRenderDrawColor( Screen::renderer, 0xFF, 0x00, 0x00, 0xFF );
	SDL_RenderFillRect( Screen::renderer, &rect );
}


void Screen::close()
{
	SDL_DestroyRenderer ( renderer );
	SDL_DestroyWindow ( window );
	window = NULL;
	renderer = NULL;

	SDL_Quit();
}

void Screen::update()
{
	//SDL_UpdateWindowSurface ( window );

	//Update screen
	SDL_RenderPresent( Screen::renderer );
}

void Screen::clear()
{
	SDL_SetRenderDrawColor( Screen::renderer, 0xFF, 0xFF, 0xFF, 0xFF );
	SDL_RenderClear( Screen::renderer );

}




