#include "Object.h"
#include <math.h>
#include "Texture.h"

Timer fallTimer;
const double gravity = 1.5;
bool resultBottomCollision = false;
bool bCollisions = false;


Object::Object()
{
	objPos_x = 0;
	objPos_y = 0;
	objVel_x = 0;
	objVel_y = 0;
}

Object::~Object()
{
	objTexture.free();
}


void Object::applyEvent( SDL_Event& e )
{
	if ( e.type == SDL_KEYDOWN && !e.key.repeat )
	{
		switch ( e.key.keysym.sym )
		{
			case SDLK_LEFT:
				objVel_x -= OBJ_VEL;
			break;

			case SDLK_RIGHT:
				objVel_x += OBJ_VEL;
			break;

			case SDLK_UP:
				objVel_y -= OBJ_VEL;
				fallTimer.start();
			break;
		}
	}
	else if ( e.type == SDL_KEYUP && !e.key.repeat )
	{
		switch ( e.key.keysym.sym )
		{
			case SDLK_LEFT:
				objVel_x += OBJ_VEL;
			break;

			case SDLK_RIGHT:
				objVel_x -= OBJ_VEL;
			break;

			case SDLK_UP:
			break;
		}
	}

}


//int Object::handleCollision( SDL_Rect* obs )
//{
//	unsigned char collisionSides = 0;
//
//	// right collision:
//	if ( ( objPos_x + OBJ_WIDTH >= obs->x && objPos_x + OBJ_WIDTH <= obs->x+obs->w) && !( (objPos_y + OBJ_HEIGHT <= obs->y) || (objPos_y >= obs->y + obs->h) ) )
//	{
//		objPos_x = obs->x - OBJ_WIDTH;
//		collisionSides += 0xFF;
//		collisionSides <<= 8;
//	}
//	else
//	{
//		collisionSides += 0x00;
//		collisionSides <<= 8;
//	}
//
//
//	// left collision:
//	if ( (objPos_x <= obs->x+obs->w && objPos_x >= obs->x) && !( (objPos_y + OBJ_HEIGHT <= obs->y) || (objPos_y >= obs->y + obs->h) ) )
//	{
//		objPos_x = obs->x + obs->w;
//
//		collisionSides += 0xFF;
//		collisionSides <<= 8;
//	}
//	else
//	{
//		collisionSides += 0x00;
//		collisionSides <<= 8;
//	}
//
//
//	// top collision:
//	if ( (objPos_y <= obs->y+obs->h && objPos_y >= obs->y) && !( (objPos_x >= obs->x + obs->w) || (objPos_x + OBJ_WIDTH <= obs->x) ) )
//	{
//		objPos_y = obs->y + obs->h;
//
//		collisionSides += 0xFF;
//		collisionSides <<= 8;
//	}
//	else
//	{
//		collisionSides += 0x00;
//		collisionSides <<= 8;
//	}
//
//
//	// bottom collision:
//	if ( (objPos_y + OBJ_HEIGHT >= obs->y && objPos_y + OBJ_HEIGHT <= obs->y+obs->h) && !( (objPos_x  >= obs->x + obs->w) || (objPos_x + OBJ_WIDTH <= obs->x) ) )
//	{
//		objPos_y = obs->y - OBJ_WIDTH;
//		collisionSides += 0xFF;
//		bCollisions = true;
//	}
//	else
//	{
//		collisionSides += 0x00;
//		bCollisions = bCollisions || false;
//	}
//
//	return collisionSides;
//}


void Object::handleRightCollision(SDL_Rect* obs)
{
	objPos_x = obs->x - OBJ_WIDTH;
}
void Object::handleLeftCollision(SDL_Rect* obs)
{
	objPos_x = obs->x + obs->w;
}
void Object::handleTopCollision(SDL_Rect* obs)
{
	objPos_y = obs->y + obs->h;
}
void Object::handleBottomCollision(SDL_Rect* obs)
{
	objPos_y = obs->y - OBJ_WIDTH;
}




bool Object::rightCollision(SDL_Rect* obs)
{
	return (objPos_x + OBJ_WIDTH >= obs->x && objPos_x + OBJ_WIDTH <= obs->x+obs->w) && !( (objPos_y + OBJ_HEIGHT <= obs->y) || (objPos_y >= obs->y + obs->h) );
}
bool Object::leftCollision(SDL_Rect* obs)
{
	return (objPos_x <= obs->x+obs->w && objPos_x >= obs->x) && !( (objPos_y + OBJ_HEIGHT <= obs->y) || (objPos_y >= obs->y + obs->h) );
}
bool Object::topCollision(SDL_Rect* obs)
{
	return (objPos_y <= obs->y+obs->h && objPos_y >= obs->y) && !( (objPos_x >= obs->x + obs->w) || (objPos_x + OBJ_WIDTH <= obs->x) );
}
bool Object::bottomCollision(SDL_Rect* obs)
{
	return (objPos_y + OBJ_HEIGHT >= obs->y && objPos_y + OBJ_HEIGHT <= obs->y+obs->h) && !( (objPos_x  >= obs->x + obs->w) || (objPos_x + OBJ_WIDTH <= obs->x) );
}




void Object::update ( double timeStep, SDL_Rect* obs, const int TOTAL_OBSTACLES )
{
	objPos_x += objVel_x * timeStep;

	if ( objPos_x < 0 ) { objPos_x = 0; }
	else if ( objPos_x > TOTAL_WIDTH - OBJ_WIDTH ) { objPos_x = TOTAL_WIDTH - OBJ_WIDTH; }

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

	objVel_y += gravity*fallTimer.getTicks()*0.04;
	printf("objVel_y = %f   bCollisions = %d\n", objVel_y, bCollisions );
	objPos_y += objVel_y*timeStep;


	if ( objPos_y < 0 ) { objPos_y = 0; }
	if ( objPos_y + OBJ_HEIGHT >= TOTAL_HEIGHT ) { objPos_y = TOTAL_HEIGHT - OBJ_HEIGHT;  bCollisions = true; }
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
				objVel_y = 50;
			}
		}
	}

	if ( !bCollisions ) { fallTimer.start(); }
	else { objVel_y = 0; fallTimer.stop(); }



}



//void Object::update ( double timeStep, SDL_Rect* obs, const int TOTAL_OBSTACLES )
//{
//	unsigned char collisionSides;
//
//	objPos_x += objVel_x * timeStep;
//
//	if ( objPos_x < 0 ) { objPos_x = 0; }
//	else if ( objPos_x > TOTAL_WIDTH - OBJ_WIDTH ) { objPos_x = TOTAL_WIDTH - OBJ_WIDTH; }
//
////	if ( obs != NULL )
////	{
////		for ( int i=0; i < TOTAL_OBSTACLES; i++ )
////		{
////
////		}
////	}
//
//	objVel_y += gravity*fallTimer.getTicks()*0.04;
//	printf("objVel_y = %f   bCollisions = %d\n", objVel_y, bCollisions );
//	objPos_y += objVel_y*timeStep;
//
//
//	if ( objPos_y < 0 ) { objPos_y = 0; }
//	if ( objPos_y + OBJ_HEIGHT >= TOTAL_HEIGHT ) { objPos_y = TOTAL_HEIGHT - OBJ_HEIGHT;  bCollisions = true; }
//	else { bCollisions = false; }
//
//	if ( obs != NULL )
//	{
//		for ( int i=0; i < TOTAL_OBSTACLES; i++ )
//		{
//			handleCollision( &obs[i] );
//		}
//	}
//
//	if ( collisionSides & 0x11000000 ) { printf("Right collision!\n"); }
//	if ( collisionSides & 0x00110000 ) { printf("Left collision!\n"); }
//	if ( collisionSides & 0x00001100 ) { printf("Top collision!\n"); }
//	if ( collisionSides & 0x00000011 ) { printf("Bottom collision!\n"); }
//
//
//	if ( !bCollisions ) { fallTimer.start(); }
//	else { objVel_y = 0; fallTimer.stop(); }
//
//
//
//}





void Object::render( int cam_x, int cam_y )
{
	objTexture.render(objPos_x - cam_x, objPos_y );
}





























void Object::setTexture( std::string path )
{
	objTexture.load( path.c_str() );
}


















