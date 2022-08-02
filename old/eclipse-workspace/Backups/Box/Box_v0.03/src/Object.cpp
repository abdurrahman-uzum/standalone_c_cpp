#include "Object.h"
#include <math.h>
#include "Texture.h"




DynamicObject::DynamicObject()
{
	dPos_x = 0;
	dPos_y = 0;
	dVel_x = 0;
	dVel_y = 0;

	resultBottomCollision = false;
	bCollisions = false;
}

DynamicObject::~DynamicObject()
{
	dTexture.free();
}


void DynamicObject::applyEvent( SDL_Event& e )
{
	if ( e.type == SDL_KEYDOWN && !e.key.repeat )
	{
		switch ( e.key.keysym.sym )
		{
			case SDLK_LEFT:
				dVel_x -= D_OBJ_VEL;
			break;

			case SDLK_RIGHT:
				dVel_x += D_OBJ_VEL;
			break;

			case SDLK_UP:
				dVel_y -= D_OBJ_VEL;
				fallTimer.start();
			break;
		}
	}
	else if ( e.type == SDL_KEYUP && !e.key.repeat )
	{
		switch ( e.key.keysym.sym )
		{
			case SDLK_LEFT:
				dVel_x += D_OBJ_VEL;
			break;

			case SDLK_RIGHT:
				dVel_x -= D_OBJ_VEL;
			break;

			case SDLK_UP:
			break;
		}
	}

}




void DynamicObject::handleRightCollision(SDL_Rect* obs)
{
	dPos_x = obs->x - D_OBJ_WIDTH;
}
void DynamicObject::handleLeftCollision(SDL_Rect* obs)
{
	dPos_x = obs->x + obs->w;
}
void DynamicObject::handleTopCollision(SDL_Rect* obs)
{
	dPos_y = obs->y + obs->h;
}
void DynamicObject::handleBottomCollision(SDL_Rect* obs)
{
	dPos_y = obs->y - D_OBJ_WIDTH;
}



bool DynamicObject::rightCollision(SDL_Rect* obs)
{
	return (dPos_x + D_OBJ_WIDTH >= obs->x && dPos_x + D_OBJ_WIDTH <= obs->x+obs->w) && !( (dPos_y + D_OBJ_HEIGHT <= obs->y) || (dPos_y >= obs->y + obs->h) );
}
bool DynamicObject::leftCollision(SDL_Rect* obs)
{
	return (dPos_x <= obs->x+obs->w && dPos_x >= obs->x) && !( (dPos_y + D_OBJ_HEIGHT <= obs->y) || (dPos_y >= obs->y + obs->h) );
}
bool DynamicObject::topCollision(SDL_Rect* obs)
{
	return (dPos_y <= obs->y+obs->h && dPos_y >= obs->y) && !( (dPos_x >= obs->x + obs->w) || (dPos_x + D_OBJ_WIDTH <= obs->x) );
}
bool DynamicObject::bottomCollision(SDL_Rect* obs)
{
	return (dPos_y + D_OBJ_HEIGHT >= obs->y && dPos_y + D_OBJ_HEIGHT <= obs->y+obs->h) && !( (dPos_x  >= obs->x + obs->w) || (dPos_x + D_OBJ_WIDTH <= obs->x) );
}




void DynamicObject::update ( double timeStep, SDL_Rect* obs, const int TOTAL_OBSTACLES )
{
	printf("UPDATE> position: ( %d, %d ) \n", dPos_x, dPos_y);

	dPos_x += dVel_x * timeStep;

	if ( dPos_x < 0 ) { dPos_x = 0; }
	else if ( dPos_x > TOTAL_WIDTH - D_OBJ_WIDTH ) { dPos_x = TOTAL_WIDTH - D_OBJ_WIDTH; }
	printf("UPDATE#2> position: ( %d, %d ) \n", dPos_x, dPos_y);

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

	dVel_y += GRAVITY*fallTimer.getTicks()*0.04;
	printf("dVel_y = %f   bCollisions = %d\n", dVel_y, bCollisions );
	dPos_y += dVel_y*timeStep;


	if ( dPos_y < 0 ) { dPos_y = 0; }
	if ( dPos_y + D_OBJ_HEIGHT >= TOTAL_HEIGHT ) { dPos_y = TOTAL_HEIGHT - D_OBJ_HEIGHT;  bCollisions = true; }
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
				dVel_y = 50;
			}
		}
	}

	if ( !bCollisions ) { fallTimer.start(); }
	else { dVel_y = 0; fallTimer.stop(); }



}


void DynamicObject::render( int cam_x, int cam_y )
{
	dTexture.render(dPos_x - cam_x, dPos_y );
}

void DynamicObject::setTexture( std::string path )
{
	dTexture.load( path.c_str() );
}


//////////////////////////////////////////////////////////////////////////////


void StaticObject::setTexture( std::string path )
{
	sTexture.load( path.c_str() );
}

void StaticObject::render( int cam_x, int cam_y )
{
	sTexture.render(collisionBox.x - cam_x, collisionBox.y);
}
















