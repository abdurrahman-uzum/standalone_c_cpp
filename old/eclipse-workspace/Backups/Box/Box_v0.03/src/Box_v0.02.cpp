#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>

#include "Texture.h"
#include "Object.h"

const int TOTAL_WIDTH = 640*4;
const int TOTAL_HEIGHT = 480;

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;



SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;

Texture someTexture;

bool init();
bool loadMedia();
void close();


bool init()
{
	if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "Failed to initialize SDL: %s\n", SDL_GetError() );
		return false;
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
			return false;
		}
		else
		{
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if ( gRenderer == NULL )
			{
				printf( "Failed to create renderer: %s\n", SDL_GetError() );
				return false;
			}
			else
			{
				SDL_SetRenderDrawColor( gRenderer, 0xff, 0xff, 0xff, 0xff );

				if ( !(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG ) )
				{
					printf( "Failed to initalize SDL_image: %s\n", IMG_GetError() );
					return false;
				}
			}
		}
	}

	return true;
}

bool loadMedia()
{


	return true;
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


const int MAP_WIDTH = 64;
const int MAP_HEIGHT = 12;
int map[MAP_WIDTH*MAP_HEIGHT] =
{
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,2,2,2,0,0,0,0,0,0,0,0,1,1,1,1,2,2,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,2,2,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
};

int getNumberOfBlocks ( int* givenMap, int size )
{
	int numberOfBlocks = 1;

	for ( int i=0; i < size; i++ )
	{
		if ( givenMap[i] ) { numberOfBlocks++; }
	}

	return numberOfBlocks;
}


void staticObjectCreater( const int* map, const int WIDTH, const int HEIGHT, StaticObject* statics, SDL_Rect* collisionBoxes )
{
	int n = 0;
	for ( int j=0; j < HEIGHT; j++ )
	{
		for ( int i=0; i < WIDTH; i++ )
		{
			switch ( map[j*WIDTH + i] )
			{
				case 1:
					statics[n].initialize( i*40, j*40, 40, 40 );
					statics[n].setTexture( "C:/Users/Abdurrahman/eclipse-workspace/Box/media/grassDirt.png" );
					collisionBoxes[n] = statics[n].getCollisionBox();// { i*40, j*40, 40, 40 };
					n++;
				break;
				case 2:
					statics[n].initialize( i*40, j*40, 40, 40 );
					statics[n].setTexture( "C:/Users/Abdurrahman/eclipse-workspace/Box/media/brick.png" );
					collisionBoxes[n] = statics[n].getCollisionBox();// { i*40, j*40, 40, 40 };
					n++;
				break;
			}
//			if ( map[j*WIDTH + i] == 1 )
//			{
//				statics[n].initialize( i*40, j*40, 40, 40 );
//				statics[n].setTexture( "C:/Users/Abdurrahman/eclipse-workspace/Box/media/brick.png" );
//				collisionBoxes[n] = statics[n].getCollisionBox();// { i*40, j*40, 40, 40 };
//				n++;
//			}
		}
	}
}

void staticObjectRenderer( StaticObject* statics, const int size, SDL_Rect& camera )
{
	for ( int i=0; i < size; i++ )
	{
		statics[i].render(camera.x,0);
	}
}


void updateCamera( SDL_Rect* camera, DynamicObject& object )
{

	if ( object.getPos_x() - camera->x <= SCREEN_WIDTH/3 )
	{
		camera->x = object.getPos_x() - SCREEN_WIDTH/3;
	}
	else if ( camera->x + camera->w - object.getPos_x() <= SCREEN_WIDTH/3 + DynamicObject::D_OBJ_WIDTH )
	{
		camera->x = (SCREEN_WIDTH/3 + DynamicObject::D_OBJ_WIDTH) - camera->w + object.getPos_x();
	}


	if ( camera->x < 0 ) { camera->x = 0; }
	if ( camera->x > TOTAL_WIDTH - camera->w ) { camera->x = TOTAL_WIDTH - camera->w; }

	if ( camera->y < 0 ) { camera->y = 0; }
	if ( camera->y > TOTAL_HEIGHT - camera->h ) { camera->y = TOTAL_HEIGHT - camera->h; }

}


int main ( int argc, char* argv[] )
{
	if ( init() )
	{
		SDL_Rect camera = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
		Timer stepTimer;

		DynamicObject box;
		box.setTexture( "C:/Users/Abdurrahman/eclipse-workspace/Box/media/box.png" );

		int numberOfBlocks = getNumberOfBlocks( map, sizeof(map)/sizeof(int) );
		StaticObject statics[ numberOfBlocks ];
		SDL_Rect obstacles[ numberOfBlocks ];
		staticObjectCreater( map, MAP_WIDTH, MAP_HEIGHT, statics, obstacles );

		SDL_Event e;
		bool quit = false;

		while ( !quit )
		{
			while ( SDL_PollEvent(&e) != 0 )
			{
				if ( e.type == SDL_QUIT ) { quit = true; }

				box.applyEvent( e );
			}

			double timeStep = stepTimer.getTicks() / 1000.f;

			box.update( timeStep, obstacles, numberOfBlocks );//, blocks, numberOfBlocks );
			updateCamera( &camera, box );
			stepTimer.restart();

			clear();

			staticObjectRenderer( statics, numberOfBlocks, camera );
			box.render( camera.x, camera.y);

			SDL_RenderPresent( gRenderer );

		}
	}

	close();







	return 0;
}

