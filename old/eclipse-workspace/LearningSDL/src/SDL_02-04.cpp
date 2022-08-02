#include <stdio.h>
#include <SDL.h>
#include <string>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

enum KeyPressSurfaces
{
	DEFAULT,
	UP,
	DOWN,
	LEFT,
	RIGHT,
	TOTAL
};

bool init();
bool loadMedia();
void close();
SDL_Surface* loadSurface ( std::string path );

SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gKeySurfaces [ TOTAL ];
SDL_Surface* gCurrentSurface = NULL;



bool init()
{
	bool success = true;

	if ( SDL_Init(SDL_INIT_VIDEO) < 0 )
	{
		printf ( "Failed to initalize SDL: %s\n", SDL_GetError() );
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
	SDL_Surface* loadedSurface = SDL_LoadBMP ( path.c_str() );
	if ( loadedSurface == NULL )
	{
		printf( "Failed to load image %s !\n%s\n", path.c_str(), SDL_GetError() );
	}

	return loadedSurface;
}



bool loadMedia()
{
	bool success = true;

	gKeySurfaces[DEFAULT] = loadSurface( "C:/Users/Abdurrahman/eclipse-workspace/SDL Tutorials/images/press.bmp" );
	if ( gKeySurfaces[DEFAULT] == NULL )
	{
		printf("Failed to load image!\n");
		success = false;
	}

	gKeySurfaces[UP] = loadSurface( "C:/Users/Abdurrahman/eclipse-workspace/SDL Tutorials/images/up.bmp" );
	if ( gKeySurfaces[UP] == NULL )
	{
		printf("Failed to load image!\n");
		success = false;
	}

	gKeySurfaces[DOWN] = loadSurface ( "C:/Users/Abdurrahman/eclipse-workspace/SDL Tutorials/images/down.bmp" );
	if ( gKeySurfaces[DOWN] == NULL )
	{
		printf("Failed to load image!\n");
		success = false;
	}

	gKeySurfaces[LEFT] = loadSurface ( "C:/Users/Abdurrahman/eclipse-workspace/SDL Tutorials/images/left.bmp" );
	if ( gKeySurfaces[LEFT] == NULL )
	{
		printf("Failed to load image!\n");
		success = false;
	}

	gKeySurfaces[RIGHT] = loadSurface ( "C:/Users/Abdurrahman/eclipse-workspace/SDL Tutorials/images/right.bmp" );
	if ( gKeySurfaces[RIGHT] == NULL )
	{
		printf("Failed to load image!\n");
		success = false;
	}

	return success;
}


void close()
{
	for ( int i=0; i<TOTAL; ++i )
	{
		SDL_FreeSurface ( gKeySurfaces[i] );
		gKeySurfaces[i] = NULL;
	}
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
					else if ( event.key.keysym.sym )
					{
						switch ( event.key.keysym.sym )
						{
							case SDLK_UP:
								gCurrentSurface = gKeySurfaces[UP];
								break;
							case SDLK_DOWN:
								gCurrentSurface = gKeySurfaces[DOWN];
								break;
							case SDLK_LEFT:
								gCurrentSurface = gKeySurfaces[LEFT];
								break;
							case SDLK_RIGHT:
								gCurrentSurface = gKeySurfaces[RIGHT];
								break;
							default:
								gCurrentSurface = gKeySurfaces[DEFAULT];
								break;
						}
					}
				}

				SDL_BlitSurface ( gCurrentSurface, NULL, gScreenSurface, NULL );

				SDL_UpdateWindowSurface ( gWindow );

			}
		}
	}

	close();




	return 0;
}
