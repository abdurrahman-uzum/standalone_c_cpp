#include <stdio.h>
#include <SDL.h>
#include <string>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

bool init();
bool loadMedia();
void close();
SDL_Surface* loadSurface ( std::string path );

SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gStretchedSurface = NULL;

bool init()
{
	bool success = true;

	if ( SDL_Init(SDL_INIT_VIDEO) < 0 )
	{
		printf( "Failed to initalize SDL: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		gWindow = SDL_CreateWindow ( "Window Name", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if ( gWindow == NULL )
		{
			printf( "Failed to create window: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			gScreenSurface = SDL_GetWindowSurface ( gWindow );
		}
	}


	return success;
}


SDL_Surface* loadSurface ( std::string path )
{
	SDL_Surface* optimizedSurface = NULL;

	SDL_Surface* loadedSurface = SDL_LoadBMP(  path.c_str() );
	if ( loadedSurface == NULL )
	{
		printf( "Failed to load image: %s\n", SDL_GetError() );
	}
	else
	{
		optimizedSurface = SDL_ConvertSurface ( loadedSurface, gScreenSurface->format, 0 );
		if ( optimizedSurface == NULL )
		{
			printf ( "Failed optimizing image: %s\n", SDL_GetError() );
		}
		SDL_FreeSurface( loadedSurface );
	}

	return optimizedSurface;
}



bool loadMedia()
{
	bool success = true;

	gStretchedSurface = loadSurface ( "C:/Users/Abdurrahman/eclipse-workspace/SDL Tutorials/images/stretch.bmp" );
	if ( gStretchedSurface == NULL )
	{
		printf( "Failed to load media: %s\n", SDL_GetError() );
		success = false;
	}

	return success;
}


void close()
{
	SDL_FreeSurface ( gStretchedSurface );
	gStretchedSurface = NULL;

	SDL_DestroyWindow ( gWindow );
	gWindow = NULL;

	SDL_Quit();
}



int main ( int argc, char* argv[] )
{
	if ( init() )
	{
		if ( loadMedia() )
		{
			SDL_Event event;
			bool quit = false;

			while ( !quit )
			{
				while ( SDL_PollEvent ( &event ) != 0 )
				{
					if ( event.type == SDL_QUIT )
					{
						quit = true;
					}
				}

				SDL_Rect stretchedRect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };

				SDL_BlitScaled ( gStretchedSurface, NULL, gScreenSurface, &stretchedRect );

				SDL_UpdateWindowSurface ( gWindow );


			}
		}
	}

	close();


	return 0;
}






























