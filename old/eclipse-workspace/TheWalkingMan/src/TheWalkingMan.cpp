#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <iostream>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class LTexture
{
	public:
		LTexture();
		~LTexture();

		bool loadFromFile( std::string path );

		void free();

		void render( int x, int y, SDL_Rect* clip = NULL );

		int getWidth();
		int getHeight();

	private:
		SDL_Texture* mTexture;

		int mWidth;
		int mHeight;

};

bool init();
bool loadMedia();
void close();

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
//LTexture gFooTexture;
//LTexture gBackgroundTexture;

const int WALKING_ANIMATION_FRAMES = 4;
SDL_Rect gSpriteClips[4];
LTexture gSpriteSheetTexture;


const int FRAMES = 5;


SDL_Rect gWalkingRightClips[5];
SDL_Rect gWalkingLeftClips[5];
SDL_Rect gStandingClips[5];
SDL_Rect gJumpingClips[20];

LTexture gWalkingRightTexture;
LTexture gWalkingLeftTexture;
LTexture gStandingTexture;
LTexture gJumpingTexture;

double gOffset_x = 0;
double gOffset_y = 0;


LTexture::LTexture()
{
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

LTexture::~LTexture()
{
	free();
}

bool LTexture::loadFromFile( std::string path )
{
	free();

	SDL_Texture* newTexture = NULL;

	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if ( loadedSurface == NULL )
	{
		printf( "Failed to load image: %s\n", IMG_GetError() );
	}
	else
	{
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

		newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if ( newTexture == NULL )
		{
			printf( "Failed to create texture: %s\n", SDL_GetError() );
		}
		else
		{
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		SDL_FreeSurface( loadedSurface );
	}

	mTexture = newTexture;
	return mTexture != NULL;
}

void LTexture::free()
{
	if ( mTexture != NULL )
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void LTexture::render( int x, int y, SDL_Rect* clip )
{
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	if ( clip != NULL )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	SDL_RenderCopy( gRenderer, mTexture, clip, &renderQuad );
}





int LTexture::getWidth()
{
	return mWidth;
}
int LTexture::getHeight()
{
	return mHeight;
}


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
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		gWindow = SDL_CreateWindow( "Window Name", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if ( gWindow == NULL )
		{
			printf( "Failed to create window: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			gRenderer = SDL_CreateRenderer ( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if ( gRenderer == NULL )
			{
				printf( "Failed to create renderer: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				SDL_SetRenderDrawColor( gRenderer, 0xff, 0xff, 0xff, 0xff );

				int imgFlags = IMG_INIT_PNG;
				if ( !(IMG_Init(imgFlags) & imgFlags) )
				{
					printf( "Failed to initialize SDL_image: %s\n", IMG_GetError() );
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

	if ( !gStandingTexture.loadFromFile( "C:/Users/Abdurrahman/eclipse-workspace/TheWalkingMan/media/standing.png" ) )
	{
		printf( "Failed to load texture 1!");
		success = false;
	}
	else if ( !gWalkingRightTexture.loadFromFile( "C:/Users/Abdurrahman/eclipse-workspace/TheWalkingMan/media/walkingRight.png" ) )
	{
		printf( "Failed to load texture 2!");
		success = false;
	}
	else if ( !gWalkingLeftTexture.loadFromFile( "C:/Users/Abdurrahman/eclipse-workspace/TheWalkingMan/media/walkingLeft.png" ) )
	{
		printf( "Failed to load texture 3!");
		success = false;
	}
	else if ( !gJumpingTexture.loadFromFile( "C:/Users/Abdurrahman/eclipse-workspace/TheWalkingMan/media/jumping.png" ) )
	{
		printf( "Failed to load texture 4!");
		success = false;
	}
	else
	{
		for ( int i=0; i < FRAMES; i++ )
		{
			gStandingClips[i] = { i*70, 0, 70, 200 };
		}
		for ( int i=0; i < FRAMES; i++ )
		{
			gWalkingRightClips[i] = { i*70, 0, 70, 200 };
		}
		for ( int i=0; i < FRAMES; i++ )
		{
			gWalkingLeftClips[i] = { i*70, 0, 70, 200 };
		}
		for ( int i=0; i < 15; i++ )
		{
			gJumpingClips[i] = { i*100, 0, 100, 200 };
		}

//		gSpriteClips[ 0 ].x = 0;
//		gSpriteClips[ 0 ].y = 0;
//		gSpriteClips[ 0 ].w = 64;
//		gSpriteClips[ 0 ].h = 205;
//
//		gSpriteClips[ 1 ].x = 64;
//		gSpriteClips[ 1 ].y = 0;
//		gSpriteClips[ 1 ].w = 64;
//		gSpriteClips[ 1 ].h = 205;
//
//		gSpriteClips[ 2 ].x = 128;
//		gSpriteClips[ 2 ].y = 0;
//		gSpriteClips[ 2 ].w = 64;
//		gSpriteClips[ 2 ].h = 205;
//
//		gSpriteClips[ 3 ].x = 196;
//		gSpriteClips[ 3 ].y = 0;
//		gSpriteClips[ 3 ].w = 64;
//		gSpriteClips[ 3 ].h = 205;
	}

	return success;
}

void close()
{
//	gFooTexture.free();
//	gBackgroundTexture.free();

	//gSpriteSheetTexture.free();

	gStandingTexture.free();
	gWalkingRightTexture.free();
	gWalkingLeftTexture.free();
	gJumpingTexture.free();

	SDL_DestroyRenderer( gRenderer );
	gRenderer = NULL;

	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	IMG_Quit();
	SDL_Quit();
}


//void walk ( SDL_Event* event )
//{
//	static int frame = 0;
//	static double offset = 0;
//
//	SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
//	SDL_RenderClear( gRenderer );
//
//	switch ( event->key.keysym.sym )
//	{
//		case SDLK_RIGHT:
//		{
//			SDL_Rect* currentClip = &gWalkingRightClips[frame/5];
//			gWalkingRightTexture.render( ( (SCREEN_WIDTH - currentClip->w) / 2 ) + ( offset+=1.5) , ( SCREEN_HEIGHT - currentClip->h ) / 2, currentClip );
//			break;
//		}
//
//		case SDLK_LEFT:
//		{
//			SDL_Rect* currentClip = &gWalkingLeftClips[frame/5];
//			gWalkingLeftTexture.render( ( (SCREEN_WIDTH - currentClip->w) / 2 ) + ( offset-=1.5), ( SCREEN_HEIGHT - currentClip->h ) / 2, currentClip );
//			break;
//		}
//
//		default:
//		{
//			SDL_Rect* currentClip = &gStandingClips[frame/5];
//			gStandingTexture.render( ( (SCREEN_WIDTH - currentClip->w) / 2 ) + offset, ( SCREEN_HEIGHT - currentClip->h ) / 2, currentClip );
//		}
//	}
//
//	SDL_RenderPresent( gRenderer );
//
//	++frame;
//	if ( frame / 5 >= FRAMES ) { frame = 0; }
//}

void walk ( std::string direction )
{
	static int frame = 0;

	SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
	SDL_RenderClear( gRenderer );

	if ( direction == "right" )
	{
		SDL_Rect* currentClip = &gWalkingRightClips[frame];
		gWalkingRightTexture.render( ( (SCREEN_WIDTH - currentClip->w) / 2 ) + ( gOffset_x+=1.5) , ( (SCREEN_HEIGHT - currentClip->h) / 2 ) + (gOffset_y) , currentClip );
	}

	else if ( direction == "left" )
	{
		SDL_Rect* currentClip = &gWalkingLeftClips[frame];
		gWalkingLeftTexture.render( ( (SCREEN_WIDTH - currentClip->w) / 2 ) + ( gOffset_x-=1.5), ( (SCREEN_HEIGHT - currentClip->h) / 2 ) + (gOffset_y) , currentClip );
	}

	else
	{
		SDL_Rect* currentClip = &gStandingClips[frame];
		gStandingTexture.render( ( (SCREEN_WIDTH - currentClip->w) / 2 ) + gOffset_x, ( (SCREEN_HEIGHT - currentClip->h) / 2 ) + (gOffset_y) , currentClip );
	}

	SDL_RenderPresent( gRenderer );

	frame = (int)(SDL_GetTicks()*0.01)%5;
	//if ( frame / 5 >= FRAMES ) { frame = 0; }
}


void jump()
{
	int frame = 0;
	int timer = SDL_GetTicks();

	std::cout << "Jump requested. frame="<< frame << " timer="<< timer << std::endl;

	while ( frame < 15-1 )
	{
		frame = (int)((SDL_GetTicks()-timer)*0.01)%15;

		SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
		SDL_RenderClear( gRenderer );

		SDL_Rect* currentClip = &gJumpingClips[frame];
		gJumpingTexture.render( ( (SCREEN_WIDTH - currentClip->w) / 2 ) + gOffset_x, ( (SCREEN_HEIGHT - currentClip->h) / 2 ), currentClip );

		SDL_RenderPresent( gRenderer );

		std::cout << "frame="<<frame<< std::endl;
	}
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
				while ( SDL_PollEvent(&event) != 0 )
				{
					if ( event.type == SDL_QUIT )
					{
						quit = true;
					}
					if ( event.key.keysym.sym == SDLK_UP ) { jump(); }

					while ( event.type == SDL_KEYDOWN )
					{
						SDL_PollEvent(&event);
						switch ( event.key.keysym.sym )
						{
//						case SDLK_UP:
//							std::cout << "Jumping..."<< std::endl;
//							jump();
//						break;

						case SDLK_RIGHT:
							walk("right");
						break;

						case SDLK_LEFT:
							walk("left");
						break;

						default :
							walk("don't");
						break;
						}
					}



//					const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
//					if( currentKeyStates[ SDL_SCANCODE_RIGHT ] )
//					{
//						walk("right");
//					}
//					else if( currentKeyStates[ SDL_SCANCODE_LEFT ] )
//					{
//						walk("left");
//					}
//					else
//					{
//						walk("don't");
//					}
				}
				walk("don't");
			}
		}
	}

	close();


	return 0;
}


























