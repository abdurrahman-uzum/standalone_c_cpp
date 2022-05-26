#include "Object.h"
#include <math.h>
#include "Texture.h"

Timer fallTimer;
const double gravity = 1.5;
bool resultBottomCollision = false;
bool bCollisions = false;


Object::Object( int x, int y, int w, int h )
{
	objPos_x = x;
	objPos_y = y;
	objWidth = w;
	objHeight = h;
}

Object::~Object()
{
	objTexture.free();
}


void Object::render( int x, int y, int cam_x, int cam_y )
{
	objTexture.render(x - cam_x, y );
}


void Object::setTexture( std::string path )
{
	objTexture.load( path.c_str() );
}







DynamicObject::DynamicObject(int x, int y, int w, int h) : Object::Object( x ,  y,  w,  h )
{
	d_objPos_x = getPos_x();
	d_objPos_y = getPos_y();
	d_objWidth = getWidth();
	d_objHeight = getHeight();
	vel_x = 0;
	vel_y = 0;
}





void DynamicObject::applyEvent( SDL_Event& e )
{
	if ( e.type == SDL_KEYDOWN && !e.key.repeat )
	{
		switch ( e.key.keysym.sym )
		{
			case SDLK_LEFT:
				vel_x -= OBJ_VEL;
			break;

			case SDLK_RIGHT:
				vel_x += OBJ_VEL;
			break;

			case SDLK_UP:
				vel_y -= OBJ_VEL;
				fallTimer.start();
			break;
		}
	}
	else if ( e.type == SDL_KEYUP && !e.key.repeat )
	{
		switch ( e.key.keysym.sym )
		{
			case SDLK_LEFT:
				vel_x += OBJ_VEL;
			break;

			case SDLK_RIGHT:
				vel_x -= OBJ_VEL;
			break;

			case SDLK_UP:
			break;
		}
	}

}




void DynamicObject::handleRightCollision(SDL_Rect* obs)
{
	d_objPos_x = obs->x - getWidth();
}
void DynamicObject::handleLeftCollision(SDL_Rect* obs)
{
	d_objPos_x = obs->x + obs->w;
}
void DynamicObject::handleTopCollision(SDL_Rect* obs)
{
	d_objPos_y = obs->y + obs->h;
}
void DynamicObject::handleBottomCollision(SDL_Rect* obs)
{
	d_objPos_y = obs->y - getWidth();
}




bool DynamicObject::rightCollision(SDL_Rect* obs)
{
	return (d_objPos_x + getWidth() >= obs->x && d_objPos_x + getWidth() <= obs->x+obs->w) && !( (d_objPos_y + getHeight() <= obs->y) || (d_objPos_y >= obs->y + obs->h) );
}
bool DynamicObject::leftCollision(SDL_Rect* obs)
{
	return (d_objPos_x <= obs->x+obs->w && d_objPos_x >= obs->x) && !( (d_objPos_y + getHeight() <= obs->y) || (d_objPos_y >= obs->y + obs->h) );
}
bool DynamicObject::topCollision(SDL_Rect* obs)
{
	return (d_objPos_y <= obs->y+obs->h && d_objPos_y >= obs->y) && !( (d_objPos_x >= obs->x + obs->w) || (d_objPos_x + getWidth() <= obs->x) );
}
bool DynamicObject::bottomCollision(SDL_Rect* obs)
{
	return (d_objPos_y + getHeight() >= obs->y && d_objPos_y + getHeight() <= obs->y+obs->h) && !( (d_objPos_x  >= obs->x + obs->w) || (d_objPos_x + getWidth() <= obs->x) );
}




void DynamicObject::update ( double timeStep, SDL_Rect* obs, const int TOTAL_OBSTACLES )
{
	d_objPos_x += vel_x * timeStep;

	if ( d_objPos_x < 0 ) { d_objPos_x = 0; }
	else if ( d_objPos_x > TOTAL_WIDTH - getWidth() ) { d_objPos_x = TOTAL_WIDTH - getWidth(); }

	if ( obs != NULL )
	{
		for ( int i=0; i < TOTAL_OBSTACLES; i++ )
		{
			if ( rightCollision( &obs[i] ) )
			{
				printf("Right collision.\n");
				handleRightCollision( &obs[i] );
			}


			else if ( leftCollision( &obs[i] ) )
			{
				printf("Left collision.\n");
				handleLeftCollision( &obs[i] );
			}
		}
	}

	vel_y += gravity*fallTimer.getTicks()*0.04;
	printf("vel_y = %f   bCollisions = %d\n", vel_y, bCollisions );
	d_objPos_y += vel_y*timeStep;


	if ( d_objPos_y < 0 ) { d_objPos_y = 0; }
	if ( d_objPos_y + getHeight() >= TOTAL_HEIGHT ) { d_objPos_y = TOTAL_HEIGHT - getHeight();  bCollisions = true; }
	else { bCollisions = false; }

	if ( obs != NULL )
	{
		for ( int i=0; i < TOTAL_OBSTACLES; i++ )
		{

			if ( bottomCollision( &obs[i] ) )
			{
				printf("Bottom collision.\n");
				handleBottomCollision( &obs[i] );
				bCollisions = true;
			}
			else { bCollisions = bCollisions || false; }

			if ( topCollision( &obs[i] ) )
			{
				printf("Top collision.\n");
				handleTopCollision( &obs[i] );
				vel_y = 50;
			}
		}
	}

	if ( !bCollisions ) { fallTimer.start(); }
	else { vel_y = 0; fallTimer.stop(); }

}























