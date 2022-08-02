#include "Objects.h"


Rectangles::Rectangles( int x, int y, int w, int h )
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}

Rectangles::~Rectangles()
{
}

SDL_Rect Rectangles::getRect()
{
	SDL_Rect temp = { x, y, w, h };
	return temp;
}

