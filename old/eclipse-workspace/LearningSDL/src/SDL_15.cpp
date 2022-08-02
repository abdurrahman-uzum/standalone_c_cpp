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

		void setColor( Uint8, Uint8, Uint8 );

		void setBlendMode ( SDL_BlendMode );
		void setAlpha ( Uint8 );

		void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );

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

LTexture gArrowTexture;

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

void LTexture::setColor( Uint8 red, Uint8 green, Uint8 blue )
{
	SDL_SetTextureColorMod ( mTexture, red, green, blue );
}

void LTexture::render( int x, int y, SDL_Rect* clip, double angle, SDL_Point* point, SDL_RendererFlip flip )
{
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	if ( clip != NULL )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//SDL_RenderCopy( gRenderer, mTexture, clip, &renderQuad ); // without rotation or flipping
	SDL_RenderCopyEx( gRenderer, mTexture, clip, &renderQuad, angle, point, flip );
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

	if ( !gArrowTexture.loadFromFile( "C:/Users/Abdurrahman/eclipse-workspace/SDL Tutorials/images/arrow.png") )
	{
		printf("Failed to load texture!\n");
		success = false;
	}

	return success;
}

void close()
{
//	gFooTexture.free();
//	gBackgroundTexture.free();

	gArrowTexture.free();

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

			double degrees = 0;

			SDL_RendererFlip flipType = SDL_FLIP_NONE;

			bool quit = false;
			while ( !quit )
			{
				while ( SDL_PollEvent(&event) != 0 )
				{
					if ( event.type == SDL_QUIT )
					{
						quit = true;
					}
					else if ( event.type == SDL_KEYDOWN )
					{
						switch ( event.key.keysym.sym )
						{
							case SDLK_a:
								degrees -= 60;
								break;

							case SDLK_d:
								degrees +=60;
								break;

							case SDLK_q:
								flipType = SDL_FLIP_HORIZONTAL;
								break;

							case SDLK_w:
								flipType = SDL_FLIP_NONE;
								break;

							case SDLK_e:
								flipType = SDL_FLIP_VERTICAL;
								break;
						}
					}
				}

				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( gRenderer );

				gArrowTexture.render( (SCREEN_WIDTH - gArrowTexture.getWidth()) / 2, (SCREEN_HEIGHT - gArrowTexture.getHeight()) /2, NULL, degrees, NULL, flipType );

				SDL_RenderPresent( gRenderer );

			}
		}
	}

	close();


	return 0;
}











