#include "Texture.h"

#include "globals.h"


Texture::Texture()
{
	textureWidth = 0;
	textureHeight = 0;

	texture = nullptr;
}

Texture::~Texture()
{
	free();
}

bool Texture::load( std::string path )
{
	free();

	SDL_Surface* surface = IMG_Load( path.c_str() );
	if ( surface == NULL )
	{
		printf( "Failed to load image %s\n", SDL_GetError() );
		return false;
	}

	SDL_SetColorKey( surface, SDL_TRUE, SDL_MapRGB( surface->format, 0xFF, 0xFF, 0xFF ) );

	SDL_Texture* tempTexture = SDL_CreateTextureFromSurface( gRenderer, surface );
	if ( tempTexture == NULL )
	{
		return false;
	}

	textureWidth = surface->w;
	textureHeight = surface->h;

	SDL_FreeSurface( surface );

	texture = tempTexture;


	return texture != NULL;
}

void Texture::render( int x, int y )
{
	SDL_Rect rectToBeRendered = { x, y, textureWidth, textureHeight };

	SDL_RenderCopy( gRenderer, texture, NULL, &rectToBeRendered );
}

void Texture::free()
{
	if ( texture != NULL )
	{
		SDL_DestroyTexture( texture );
		textureWidth = 0;
		textureHeight = 0;
	}
}














