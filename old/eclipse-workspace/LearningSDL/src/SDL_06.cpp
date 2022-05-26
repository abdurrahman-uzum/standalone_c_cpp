#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <string>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

bool init();
bool loadMedia();
void close();
SDL_Surface* loadSurface ( std::string path );

SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gPNGSurface = NULL;


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
			int imgFlags = IMG_INIT_PNG;
			if ( !( IMG_Init ( imgFlags ) & imgFlags ) )
			{
				printf( "Failed to initialize SDL_image: %s\n", IMG_GetError() );
				success = false;
			}
			else
			{
				gScreenSurface = SDL_GetWindowSurface ( gWindow );

			}
		}
	}


	return success;
}



SDL_Surface* loadSurface ( std::string path )
{
	SDL_Surface* optimizedSurface = NULL;

	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if ( loadedSurface == NULL )
	{
		printf("Failed to load PNG: %s\n", IMG_GetError() );
	}
	else
	{
		optimizedSurface = SDL_ConvertSurface ( loadedSurface, gScreenSurface->format, 0 );
		if ( optimizedSurface == NULL )
		{
			printf( "Failed to optimize image: %s\n", SDL_GetError() );
		}

		SDL_FreeSurface ( loadedSurface );
	}

	return optimizedSurface;
}



bool loadMedia()
{
	bool success = true;

	gPNGSurface = loadSurface( "C:/Users/Abdurrahman/eclipse-workspace/SDL Tutorials/images/loaded.png" );
	if ( gPNGSurface == NULL )
	{
		printf( "Failed to load PNG!\n" );
		success = false;
	}

	return success;
}

void close()
{
	SDL_FreeSurface ( gPNGSurface );
	gPNGSurface = NULL;

	SDL_DestroyWindow ( gWindow );
	gWindow = NULL;

	IMG_Quit();
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
				while ( SDL_PollEvent( &event ) != 0 )
				{
					if ( event.type == SDL_QUIT )
					{
						quit = true;
					}
				}

				SDL_BlitSurface ( gPNGSurface, NULL, gScreenSurface, NULL );

				SDL_UpdateWindowSurface ( gWindow );
			}

		}
	}

	close();










	return 0;
}















