#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <string>


const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

bool init();
bool loadMedia();
void close();
SDL_Texture* loadTexture ( std::string );

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
SDL_Texture* gTexture = NULL;


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
		if ( !SDL_SetHint ( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Lineer texture filtering not enabled!\n" );
		}

		gWindow = SDL_CreateWindow ( "Window Name", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if ( gWindow == NULL )
		{
			printf( "Failed to create window: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			gRenderer = SDL_CreateRenderer ( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if ( gRenderer == NULL )
			{
				printf( "Failed to create renderer: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				SDL_SetRenderDrawColor ( gRenderer, 0xff, 0xff, 0xff, 0xff );

				int imgFlags = IMG_INIT_PNG;
				if ( !(IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "Failed to initialize SDL_image: %s\n", IMG_GetError() );
					success = false;
				}

			}
		}
	}

	return success;
}

SDL_Texture* loadTexture ( std::string path )
{
	SDL_Texture* newTexture = NULL;

	SDL_Surface* loadedSurface = IMG_Load ( path.c_str() );
	if ( loadedSurface == NULL )
	{
		printf( "Failed to load image: %s\n", IMG_GetError() );
	}
	else
	{
		newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if ( newTexture == NULL )
		{
			printf( "Failed to create texture: %s\n", SDL_GetError() );
		}

		SDL_FreeSurface ( loadedSurface );
	}

	return newTexture;
}

bool loadMedia()
{
	bool success = true;

	gTexture = loadTexture( "C:/Users/Abdurrahman/eclipse-workspace/SDL Tutorials/images/texture.png");
	if ( gTexture == NULL )
	{
		printf( "Failed to load media: %s\n", SDL_GetError() );
		success = false;
	}

	return success;
}

void close()
{
	SDL_DestroyTexture ( gTexture );
	gTexture = NULL;

	SDL_DestroyRenderer ( gRenderer );
	gRenderer = NULL;

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
			// x, y, w, h
			SDL_Rect topleft = { 0, 0, SCREEN_WIDTH/2, SCREEN_HEIGHT/2 };
			SDL_Rect topright = { SCREEN_WIDTH/2, 0, SCREEN_WIDTH/2, SCREEN_HEIGHT/2 };
			SDL_Rect bottom = { 0, SCREEN_HEIGHT/2, SCREEN_WIDTH, SCREEN_HEIGHT/2 };

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
				SDL_SetRenderDrawColor ( gRenderer, 0xff, 0xff, 0xff, 0xff );
				SDL_RenderClear( gRenderer );

				SDL_RenderSetViewport( gRenderer, &topleft );
				SDL_RenderCopy( gRenderer, gTexture, NULL, NULL );

				SDL_RenderSetViewport( gRenderer, &topright );
				SDL_RenderCopy( gRenderer, gTexture, NULL, NULL );

				SDL_RenderSetViewport( gRenderer, &bottom );
				SDL_RenderCopy( gRenderer, gTexture, NULL, NULL );

				SDL_RenderPresent ( gRenderer );



			}
		}
	}

	close();













	return 0;
}






























