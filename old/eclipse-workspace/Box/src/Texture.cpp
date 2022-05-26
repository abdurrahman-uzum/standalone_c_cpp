#include "Texture.h"


Texture::Texture()
{
	mWidth = 0;
	mHeight = 0;
	mTexture = nullptr;
}

Texture::~Texture()
{
	free();
}

bool Texture::load( std::string path )
{
	free();
	bool success = true;

	SDL_Surface* surface = IMG_Load( path.c_str() );
	SDL_Texture* texture = nullptr;

	if ( surface == nullptr )
	{
		printf( "Failed to load image: %s\n", IMG_GetError() );
		success = false;
	}
	else
	{
		texture = SDL_CreateTextureFromSurface( gRenderer, surface );
		if ( texture == nullptr ) { success = false; }
		else
		{
			mWidth = surface->w;
			mHeight = surface ->h;
		}

		SDL_FreeSurface( surface );
	}


	mTexture = texture;

	return success;
}


void Texture::free()
{
	if ( mTexture != nullptr )
	{
		SDL_DestroyTexture( mTexture );
		mWidth = 0;
		mHeight = 0;
	}
}

void Texture::render( int x, int y, SDL_Rect* clip )
{
	SDL_Rect rectToBeRendered = { x, y, mWidth, mHeight };
	if ( clip != nullptr )
	{
		rectToBeRendered.w = clip->w;
		rectToBeRendered.h = clip->h;
	}

	SDL_RenderCopy( gRenderer, mTexture, clip, &rectToBeRendered );
}

int Texture::getWidth() { return mWidth; }
int Texture::getHeight() { return mHeight; }











