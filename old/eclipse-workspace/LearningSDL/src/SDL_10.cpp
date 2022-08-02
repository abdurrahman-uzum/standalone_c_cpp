#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

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

//	if ( !gFooTexture.loadFromFile("C:/Users/Abdurrahman/eclipse-workspace/SDL Tutorials/images/foo.png") )
//	{
//		success = false;
//	}
//
//	if ( !gBackgroundTexture.loadFromFile("C:/Users/Abdurrahman/eclipse-workspace/SDL Tutorials/images/background.png") )
//	{
//		success = false;
//	}

	if ( !gSpriteSheetTexture.loadFromFile( "C:/Users/Abdurrahman/eclipse-workspace/SDL Tutorials/images/foo2.png" ) )
	{
		printf( "Failed to load sprite sheet texture!\n");
		success = false;
	}
	else
	{
		gSpriteClips[ 0 ].x = 0;
		gSpriteClips[ 0 ].y = 0;
		gSpriteClips[ 0 ].w = 64;
		gSpriteClips[ 0 ].h = 205;

		gSpriteClips[ 1 ].x = 64;
		gSpriteClips[ 1 ].y = 0;
		gSpriteClips[ 1 ].w = 64;
		gSpriteClips[ 1 ].h = 205;

		gSpriteClips[ 2 ].x = 128;
		gSpriteClips[ 2 ].y = 0;
		gSpriteClips[ 2 ].w = 64;
		gSpriteClips[ 2 ].h = 205;

		gSpriteClips[ 3 ].x = 196;
		gSpriteClips[ 3 ].y = 0;
		gSpriteClips[ 3 ].w = 64;
		gSpriteClips[ 3 ].h = 205;
	}

	return success;
}

void close()
{
//	gFooTexture.free();
//	gBackgroundTexture.free();

	gSpriteSheetTexture.free();

	SDL_DestroyRenderer( gRenderer );
	gRenderer = NULL;

	SDL_DestroyWindow( gWindow );
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
			int frame = 0;

			bool quit = false;
			while ( !quit )
			{
				while ( SDL_PollEvent(&event) != 0 )
				{
					if ( event.type == SDL_QUIT )
					{
						quit = true;
					}
				}

				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( gRenderer );

				SDL_Rect* currentClip = &gSpriteClips[frame/4];
				gSpriteSheetTexture.render( (SCREEN_WIDTH - currentClip->w) / 2, ( SCREEN_HEIGHT - currentClip->h ) / 2, currentClip );

				SDL_RenderPresent( gRenderer );

				++frame;

				if ( frame / 4 >= WALKING_ANIMATION_FRAMES ) { frame = 0; }
			}
		}
	}

	close();


	return 0;
}











