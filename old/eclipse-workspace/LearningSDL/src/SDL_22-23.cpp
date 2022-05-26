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

		bool loadFromFile( std::string );

		void free();

		void setColor( Uint8, Uint8, Uint8 );
		void setBlendMode( SDL_BlendMode blending );
		void setAlpha( Uint8 );

		void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );

		int getWidth();
		int getHeight();

	private:
		SDL_Texture* mTexture;
		int mWidth;
		int mHeight;

};




class LTimer
{
	public:
		LTimer();

		void start();
		void stop();
		void pause();
		void unpause();

		Uint32 getTicks();

		bool isStarted();
		bool isPaused();

	private:
		Uint32 mStartTicks;
		Uint32 mPausedTicks;

		bool mPaused;
		bool mStarted;
};




bool init();

bool loadMedia();

void close();

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;

LTexture gTimeTextTexture;
LTexture gPausePromptTexture;
LTexture gStartPromptTexture;



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
		SDL_SetColorKey ( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

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
		SDL_DestroyTexture( mTexture );
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}


void LTexture::setColor( Uint8 red, Uint8 green, Uint8 blue )
{
	SDL_SetTextureColorMod( mTexture, red, green, blue );
}


void LTexture::setBlendMode( SDL_BlendMode blending )
{
	SDL_SetTextureBlendMode( mTexture, blending );
}


void LTexture::setAlpha( Uint8 alpha )
{
	SDL_SetTextureAlphaMod( mTexture, alpha );
}


void LTexture::render( int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip )
{
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	if( clip != NULL )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	SDL_RenderCopyEx( gRenderer, mTexture, clip, &renderQuad, angle, center, flip );
}



int LTexture::getWidth()
{
	return mWidth;
}



int LTexture::getHeight()
{
	return mHeight;
}



LTimer::LTimer()
{
	mStartTicks = 0;
	mPausedTicks = 0;

	mPaused = false;
	mStarted = false;
}

void LTimer::start()
{
	mStarted = true;
	mPaused = false;

	mStartTicks = SDL_GetTicks();
	mPausedTicks = 0;
}

void LTimer::stop()
{
	mStarted = false;
	mPaused = false;

	mStartTicks = 0;
	mPausedTicks = 0;
}

void LTimer::pause()
{
	if ( mStarted && !mPaused )
	{
		mPaused = true;

		mPausedTicks = SDL_GetTicks() - mStartTicks;
		mStartTicks = 0;
	}
}

void LTimer::unpause()
{
	if ( mStarted && mPaused )
	{
		mPaused = false;

		mStartTicks = SDL_GetTicks() - mPausedTicks;

		mPausedTicks = 0;
	}
}

Uint32 LTimer::getTicks()
{
	Uint32 time = 0;

	if( mStarted )
	{
		if( mPaused )
		{
			time = mPausedTicks;
		}
		else
		{
			time = SDL_GetTicks() - mStartTicks;
		}
	}

	return time;
}

bool LTimer::isStarted() { return mStarted; }

bool LTimer::isPaused() { return mPaused; }





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

//	if( !gButtonSpriteSheetTexture.loadFromFile( "C:/Users/Abdurrahman/eclipse-workspace/SDL Tutorials/images/button.png" ) )
//	{
//		printf( "Failed to load button sprite texture!\n" );
//		success = false;
//	}
//	else
//	{
//		//load media here
//	}

	return success;
}



void close()
{
	//gButtonSpriteSheetTexture.free(); WARNING: Do not forget to free your pointer!

	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	IMG_Quit();
	SDL_Quit();
}


int main ( int argc, char* argv[] )
{
	if ( init() )
	{
		if ( loadMedia() )
		{
			SDL_Event e;

			LTimer timer;

			bool quit = false;
			while ( !quit )
			{
				while ( SDL_PollEvent(&e) != 0 )
				{
					if ( e.type == SDL_QUIT )
					{
						quit = true;
					}
					else if ( e.type == SDL_KEYDOWN )
					{
						if ( e.key.keysym.sym == SDLK_s )
						{
							if ( timer.isStarted() ) { timer.stop(); }
							else { timer.start(); }
						}
						else if ( e.key.keysym.sym == SDLK_p )
						{
							if ( timer.isPaused() ) { timer.unpause(); }
							else { timer.pause(); }
						}
					}

				}//pollEvent end


				std::cout << "Seconds since start time " << ( timer.getTicks() / 1000.f ) << std::endl;

				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( gRenderer );

				// render here

				SDL_RenderPresent( gRenderer );











			}//main loop end
		}
	}

	close();


	return 0;
}












































































