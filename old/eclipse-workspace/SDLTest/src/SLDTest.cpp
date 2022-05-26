#include <iostream>
#include <SDL.h>
#include <stdio.h>

using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

const int RED = 0xFF000000;
const int GREEN = 0x00FF0000;
const int BLUE = 0x0000FF00;
const int YELLOW = 0xFFFF0000;
const int CYAN = 0x00FFFF00;
const int MAGENTA = 0xFF00FF00;

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Texture* texture = NULL;

void close()
{
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

int main ( int argc, char* argv[] )
{
	if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf("Failed to initialize SDL: %s\n", SDL_GetError() );
		return 1;
	}

	printf("SDL successfully initialized.\n");

	window = SDL_CreateWindow("New Window", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
	if ( window == NULL )
	{
		printf("Failed to create window: %s\n", SDL_GetError() );
		SDL_Quit();
		return 2;
	}


	renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_PRESENTVSYNC );
	if ( renderer == NULL )
	{
		printf("Failed to create renderer: %s\n", SDL_GetError() );
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 3;
	}


	texture = SDL_CreateTexture( renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT );
	if ( texture == NULL )
	{
		printf("Failed to create texture: %s\n", SDL_GetError() );
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 4;
	}

	Uint32* buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

	memset(buffer, 0, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32) );

	buffer[30000] = 0xFFFFFFFF;



	for ( int i = 0; i<SCREEN_WIDTH*SCREEN_HEIGHT; i++ )
	{
		buffer[i] = MAGENTA;
	}

	SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH*sizeof(Uint32) );
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);


	SDL_Event event;

	bool quit = false;

	while ( !quit )
	{
		while ( SDL_PollEvent(&event) )
		{
			if ( event.type == SDL_QUIT )
			{
				quit = true;
			}
		}
	}


	delete[] buffer;
	close();

	return 0;
}
