#include "tetromino.h"
#include "texture.h"
#include "game.h"
#include "globals.h"


const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 720;


SDL_Window* window = nullptr;
SDL_Renderer* gRenderer = nullptr;

Texture number[10];
Texture nextTetrTexture[7];

Texture gameOverTexture;



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

	if ( !(IMG_Init( IMG_INIT_PNG ) & IMG_INIT_PNG ) )
	{
		printf( "Failed to initialize SDL_image. Error: %s\n", IMG_GetError() );
		return false;
	}

	return true;
}


bool loadMedia()
{
	std::string path = "media/";
	std::string n[10] = { "0.png", "1.png", "2.png", "3.png", "4.png", "5.png", "6.png", "7.png", "8.png", "9.png" };
	std::string types[7] = { "I.png", "O.png", "J.png", "L.png", "S.png", "Z.png", "T.png" };

	for ( int i=0; i < 10; i++ )
	{
		if ( !number[i].load( (path+n[i]).c_str() ) )
		{
			printf( "Failed to load media numbers.\n" );
			return false;
		}
	}

	for ( int i=0; i < 7; i++ )
	{
		if ( !nextTetrTexture[i].load( (path+types[i]).c_str() ) )
		{
			printf( "Failed to load nextTetrTexture.\n" );
			return false;
		}
	}

	if ( !gameOverTexture.load( "media/gameOver.png" ) )
	{
		printf( "Failed to load gameOver.png.\n" );
		return false;
	}




	return true;
}


void close()
{
	SDL_DestroyWindow( window );
	window = nullptr;

	SDL_DestroyRenderer( gRenderer );
	gRenderer = nullptr;

//	IMG_Quit();
	SDL_Quit();
}



int main ( int argc, char* argv[] )
{
	if ( !init() || !loadMedia() )
	{
		exit(-1);
	}

	srand(time(NULL));
	initializeFixedBlocks();

	Tetromino tetromino( Type( rand()%7 ) );

	bool quit = false;
	bool pause = false;

	SDL_Event e;


	while ( !quit )
	{
		while ( SDL_PollEvent( &e ) )
		{
			if ( e.type == SDL_QUIT )
			{
				quit = true;
			}
			else if ( e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_p )
			{
				pause = !pause;
			}

			if ( !pause )
			{
				tetromino.applyEvent(e);
			}
		}

		if ( !pause )
		{
			tetromino.update();

			if ( isGameOver() )
			{
				renderGameOver( tetromino );

				// Game over wait screen handling:
				while ( true )
				{
					SDL_PollEvent( &e );

					if ( e.type == SDL_KEYDOWN && ( e.key.keysym.sym == SDLK_RETURN || e.key.keysym.sym == SDLK_SPACE ) )
					{
						restart( tetromino );
						break;
					}
					else if ( e.type == SDL_QUIT )
					{
						quit = true;
						break;
					}
				}
			}
			else // Regular rendering
			{
				clear();

				renderBackground();

				renderFixedBlocks();

				renderScoreBox( tetromino );

				renderNextTetromino();

				tetromino.render();
			}


		SDL_RenderPresent( gRenderer );
		}


	}// main loop end


	close();

	return 0;
}


