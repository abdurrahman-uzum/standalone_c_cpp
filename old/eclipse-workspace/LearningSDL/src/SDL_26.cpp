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

		void setColor( Uint8 red, Uint8 green, Uint8 blue );
		void setBlendMode( SDL_BlendMode blending );
		void setAlpha( Uint8 alpha );

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

		bool isStarted;
		bool isPaused;
};




class Dot
{
	public:
		static const int DOT_WIDTH = 20;
		static const int DOT_HEIGHT = 20;

		static const int DOT_VEL = 10;

	public:
		Dot();

		void handleEvent( SDL_Event& e );

		void move( SDL_Rect& wall );

		void render();

	private:
		int mPosX, mPosY;
		int mVelX, mVelY;
		SDL_Rect mCollider;
};

bool init();

bool loadMedia();

void close();

bool checkCollision( SDL_Rect A, SDL_Rect B );

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;

LTexture gDotTexture;

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
		printf( "Failed to load surface! %s\n", IMG_GetError() );
	}
	else
	{
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

		newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if ( newTexture == NULL )
		{
			printf( "Failed to create texture from surface! %s\n", SDL_GetError() );
		}
		else
		{
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}
		SDL_FreeSurface( loadedSurface );
	}

	mTexture = newTexture;

	return newTexture != NULL;
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
	//Modulate texture rgb
	SDL_SetTextureColorMod( mTexture, red, green, blue );
}

void LTexture::setBlendMode( SDL_BlendMode blending )
{
	//Set blending function
	SDL_SetTextureBlendMode( mTexture, blending );
}

void LTexture::setAlpha( Uint8 alpha )
{
	//Modulate texture alpha
	SDL_SetTextureAlphaMod( mTexture, alpha );
}

void LTexture::render( int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip )
{
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	if ( clip != NULL )
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




Dot::Dot()
{
	mPosX = 0;
	mPosY = 0;

	mVelX = 0;
	mVelY = 0;

	mCollider.w = DOT_WIDTH;
	mCollider.h = DOT_HEIGHT;
}


void Dot::handleEvent( SDL_Event& e )
{
	if ( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
	{
		switch ( e.key.keysym.sym )
		{
			case SDLK_UP: mVelY -= DOT_VEL; break;
			case SDLK_DOWN: mVelY += DOT_VEL; break;
			case SDLK_LEFT: mVelX -= DOT_VEL; break;
			case SDLK_RIGHT: mVelX += DOT_VEL; break;
		}
	}
	else if ( e.type == SDL_KEYUP && e.key.repeat == 0 )
	{
		switch ( e.key.keysym.sym )
		{
			case SDLK_UP: mVelY += DOT_VEL; break;
			case SDLK_DOWN: mVelY -= DOT_VEL; break;
			case SDLK_LEFT: mVelX += DOT_VEL; break;
			case SDLK_RIGHT: mVelX -= DOT_VEL; break;
		}
	}
}

void Dot::move( SDL_Rect& wall )
{
	mPosX += mVelX;
	mCollider.x = mPosX;

	if ( (mPosX < 0) || (mPosX + DOT_WIDTH > SCREEN_WIDTH) || checkCollision(mCollider, wall) )
	{
		mPosX -= mVelX;
		mCollider.x = mPosX;
	}

	mPosY += mVelY;
	mCollider.y = mPosY;

	if ( (mPosY < 0) || (mPosY + DOT_HEIGHT > SCREEN_HEIGHT) || checkCollision(mCollider, wall) )
	{
		mPosY -= mVelY;
		mCollider.y = mPosY;
	}
}

void Dot::render()
{
	gDotTexture.render( mPosX, mPosY );
}




bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}



bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load dot texture
	if( !gDotTexture.loadFromFile( "C:/Users/Abdurrahman/eclipse-workspace/SDL Tutorials/images/dot.bmp" ) )
	{
		printf( "Failed to load dot texture!\n" );
		success = false;
	}

	return success;
}


void close()
{
	//Free loaded images
	gDotTexture.free();

	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}



bool checkCollision( SDL_Rect A, SDL_Rect B )
{
	int leftA = A.x;
	int rightA = A.x + A.w;
	int topA = A.y;
	int bottomA = A.y + A.h;

	int leftB = B.x;
	int rightB = B.x + B.w;
	int topB = B.y;
	int bottomB = B.y + B.h;

	if ( leftA >= rightB ) { return false; }

	if ( rightA <= leftB ) { return false; }

	if ( topA >= bottomB ) { return false; }

	if ( bottomA <= topB ) { return false; }

	return true;
}





int main ( int argc, char* argv[] )
{
	if ( init() && loadMedia() )
	{
		SDL_Event e;

		Dot dot;

		SDL_Rect wall = { SCREEN_WIDTH/2, 40, 20, SCREEN_HEIGHT - 80 };

		bool quit = false;
		while ( !quit )
		{
			while ( SDL_PollEvent( &e ) != 0 )
			{
				if ( e.type == SDL_QUIT )
				{
					quit = true;
				}

				dot.handleEvent( e );
			}

			dot.move( wall );

			SDL_SetRenderDrawColor( gRenderer, 0xff, 0xff, 0xff, 0xff );
			SDL_RenderClear( gRenderer );

			SDL_SetRenderDrawColor( gRenderer, 0, 0, 0, 0 );
			SDL_RenderDrawRect( gRenderer, &wall );

			dot.render();

			SDL_RenderPresent( gRenderer );


		}//end of main loop
	}

	close();
	return 0;
}



































































