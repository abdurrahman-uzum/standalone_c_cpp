#include "Object.h"
#include <math.h>

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


//void Object::applyEvent( SDL_Event& e )
//{
//
//	if ( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
//	{
//		if ( e.key.keysym.sym == SDLK_LEFT && e.key.repeat == 0 ) { objVel_x -= OBJ_VEL; }
//		else if ( e.key.keysym.sym == SDLK_RIGHT && !e.key.repeat ) { objVel_x += OBJ_VEL; }
//		else if ( e.key.keysym.sym == SDLK_UP )
//		{
//			if ( !e.key.repeat )
//			{
//				fallTimer.start();
//				objVel_y -= 5*OBJ_VEL;
//			}
//			else
//			{
//				objVel_y += 5*OBJ_VEL;
//			}
//		}
//
////		switch ( e.key.keysym.sym )
////		{
////			case SDLK_LEFT:
////				objVel_x -= OBJ_VEL;
////			break;
////
////			case SDLK_RIGHT:
////				objVel_x += OBJ_VEL;
////			break;
////
////			case SDLK_UP:
////				if ( upReleased )
////				{
////					upReleased = false;
////					fallTimer.start();
////					objVel_y -= 5*OBJ_VEL;
////				}
////
////			break;
////
////			case SDLK_DOWN:
////				objVel_y += OBJ_VEL;
////			break;
////		}
//	}
//
//	else if ( e.type == SDL_KEYUP && e.key.repeat == 0 )
//	{
//		switch ( e.key.keysym.sym )
//		{
//			case SDLK_LEFT:
//				objVel_x += OBJ_VEL;
//			break;
//
//			case SDLK_RIGHT:
//				objVel_x -= OBJ_VEL;
//			break;
//		}
//	}
//
//
//}


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

			case SDLK_DOWN:
				objVel_y += OBJ_VEL;
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
				//objVel_y += OBJ_VEL; //TODO WARNING REMOVE THIS LINE IF TIMESTEP THING DOES NOT WORK !
			break;

			case SDLK_DOWN:
				objVel_y -= OBJ_VEL;
			break;
		}
	}

}


//void Object::handleCollision( SDL_Rect* obs )
//{
//	//Screen-border collisions:
//	if ( objPos_x < 0 )
//	{
//		objPos_x = 0;
//	}
//	else if ( objPos_x + OBJ_WIDTH > SCREEN_WIDTH )
//	{
//		objPos_x = SCREEN_WIDTH - OBJ_WIDTH;
//	}
//
//	if ( objPos_y < 0 )
//	{
//		objPos_y = 0;
//	}
//	else if ( objPos_y + OBJ_HEIGHT > SCREEN_HEIGHT )
//	{
//		objPos_y = SCREEN_HEIGHT - OBJ_HEIGHT;
//	}
//
//	//object collisions:
//	if ( obs != NULL )
//	{
//		bool collided_x = !( ( objPos_x > obs->x + obs->w ) || ( objPos_x + OBJ_WIDTH < obs->x ) || ( objPos_y > obs->y + obs->h ) || ( objPos_y + OBJ_HEIGHT < obs->y ) );
//		bool collided_y = !( ( objPos_x > obs->x + obs->w ) || ( objPos_x + OBJ_WIDTH < obs->x ) || ( objPos_y > obs->y + obs->h ) || ( objPos_y + OBJ_HEIGHT < obs->y ) );
//
//		int objR = objPos_x + OBJ_WIDTH;
//		int objL = objPos_x;
//		int objT = objPos_y;
//		int objB = objPos_y + OBJ_HEIGHT;
//
//		int obsR = obs->x + obs->w;
//		int obsL = obs->x;
//		int obsT = obs->y;
//		int obsB = obs->y + obs->h;
//
//		if ( objR > obsL && objR < obsR && collided ) // collision at right of the object.
//		{
//			objPos_x = obsL - OBJ_WIDTH;
//		}
//
//		if ( objL < obsR && objL > obsL && collided ) // collision at left of the object.
//		{
//			objPos_x = obsR;
//		}
//
//		if ( objT < obsB && objT > obsT && collided ) // collision at top of the object.
//		{
//			objPos_y = obsB;
//		}
//
//		if ( objB > obsT && objB < obsB && collided ) // collision at bottom of the object.
//		{
//			objPos_y = obsT - OBJ_WIDTH;
//		}
//	}
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




//void Object::update ( SDL_Rect* obs, const int TOTAL_OBSTACLES )
//{
//
//
//
//
//	objPos_x += objVel_x;
//	if ( obs != NULL )
//	{
//		for ( int i=0; i < TOTAL_OBSTACLES; i++ )
//		{
//			if ( objVel_x > 0 )
//			{
//				if ( rightCollision( &obs[i] ) && (topCollision( &obs[i] ) || bottomCollision( &obs[i] )) ) // collision at right of the object.
//				{
//					handleRightCollision( &obs[i] );
//				}
//			}
//			else
//			{
//				if ( leftCollision( &obs[i] ) && (topCollision( &obs[i] ) || bottomCollision( &obs[i] )) ) // collision at left of the object.
//				{
//					handleLeftCollision( &obs[i] );
//				}
//			}
//		}
//	}
//
//	objPos_y += objVel_y;
//	if ( obs != NULL )
//	{
//		for ( int i=0; i < TOTAL_OBSTACLES; i++ )
//		{
//			if ( objVel_y > 0 )
//			{
//				if ( bottomCollision( &obs[i] ) && (leftCollision( &obs[i] ) || rightCollision( &obs[i] )) ) // collision at bottom of the object.
//				{
//					handleBottomCollision( &obs[i] );
//				}
//			}
//			else
//			{
//				if ( topCollision( &obs[i] ) && (leftCollision( &obs[i] ) || rightCollision( &obs[i] )) ) // collision at top of the object.
//				{
//					handleTopCollision( &obs[i] );
//				}
//			}
//		}
//	}
//
//
//
//	objTexture.render(objPos_x, objPos_y);
//}

//Deðiþik harekerler yapan versiyon üstteki.



// TODO TODO TODO TODO Timer does not work properly. TODO TODO TODO TODO // or does it?

//void Object::update ( SDL_Rect* obs, const int TOTAL_OBSTACLES )
//{
//	bCollision = false;
//	printf("fallTimer:%d | objPos: %d,%d | objVel_y: %d, | bCollision: %d\n", fallTimer.getTicks(), objPos_x, objPos_y, objVel_y, bCollision );
//
//	objPos_x += objVel_x;
//
//	// x axis screen border collision:
//	if ( objPos_x < 0 ) { objPos_x = 0; }
//	else if ( objPos_x + OBJ_WIDTH > SCREEN_WIDTH ) { objPos_x = SCREEN_WIDTH - OBJ_WIDTH; }
//
//	if ( obs != NULL )
//	{
//		for ( int i=0; i < TOTAL_OBSTACLES; i++ )
//		{
//			if ( rightCollision( &obs[i] ) && (topCollision( &obs[i] ) || bottomCollision( &obs[i] )) ) // collision at right of the object.
//			{
//				printf("Right collision.\n");
//				handleRightCollision( &obs[i] );
//			}
//
//
//			else if ( leftCollision( &obs[i] ) && (topCollision( &obs[i] ) || bottomCollision( &obs[i] )) ) // collision at left of the object.
//			{
//				printf("Left collision.\n");
//				handleLeftCollision( &obs[i] );
//			}
//		}
//	}
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	double t = fallTimer.getTicks()/10;
//
//	double temp_y = objVel_y*t + 0.5*gravity * pow(t,2);
//	objVel_y += gravity*t;
//	objPos_y += temp_y;
//
//	// y axis screen border collision:
//	if ( objPos_y < 0 )
//	{
//		objPos_y = 0;
//	}
//	else if ( objPos_y + OBJ_HEIGHT > SCREEN_HEIGHT )
//	{
//		objPos_y = SCREEN_HEIGHT - OBJ_HEIGHT;
//		bCollision = true;
//	}
//
//	if ( obs != NULL )
//	{
//		for ( int i=0; i < TOTAL_OBSTACLES; i++ )
//		{
//
//			if ( bottomCollision( &obs[i] ) && (leftCollision( &obs[i] ) || rightCollision( &obs[i] )) ) // collision at bottom of the object.
//			{
//				printf("Bottom collision.\n");
//				handleBottomCollision( &obs[i] );
//				bCollision = true;
//			}
//
//			if ( topCollision( &obs[i] ) && (leftCollision( &obs[i] ) || rightCollision( &obs[i] )) ) // collision at top of the object.
//			{
//				printf("Top collision.\n");
//				handleTopCollision( &obs[i] );
//			}
//		}
//	}
//
//	if ( !bCollision ) { fallTimer.start(); }
//	else { fallTimer.stop(); }
//
//
//
//	objTexture.render(objPos_x, objPos_y);
//}



//HALF WORKING VERSION: ( depending frame rate )

//void Object::update ( SDL_Rect* obs, const int TOTAL_OBSTACLES )
//{
//	objPos_x += objVel_x;
//
//	if ( objPos_x < 0 ) { objPos_x = 0; }
//	else if ( objPos_x > SCREEN_WIDTH - OBJ_WIDTH ) { objPos_x = SCREEN_WIDTH - OBJ_WIDTH; }
//
//	if ( obs != NULL )
//	{
//		for ( int i=0; i < TOTAL_OBSTACLES; i++ )
//		{
//			if ( rightCollision( &obs[i] ) && (topCollision( &obs[i] ) || bottomCollision( &obs[i] )) ) // collision at right of the object.
//			{
//				printf("Right collision.\n");
//				handleRightCollision( &obs[i] );
//			}
//
//
//			else if ( leftCollision( &obs[i] ) && (topCollision( &obs[i] ) || bottomCollision( &obs[i] )) ) // collision at left of the object.
//			{
//				printf("Left collision.\n");
//				handleLeftCollision( &obs[i] );
//			}
//		}
//	}
//
//	objVel_y += gravity*fallTimer.getTicks()*0.01;
//	printf("objVel_y = %f   bCollisions = %d\n", objVel_y, bCollisions );
//	objPos_y += objVel_y;
//
//
//	if ( objPos_y < 0 ) { objPos_y = 0; }
//	if ( objPos_y + OBJ_HEIGHT > SCREEN_HEIGHT ) { objPos_y = SCREEN_HEIGHT - OBJ_HEIGHT;  bCollisions = true; }
//	else { bCollisions = false; }
//
//	if ( obs != NULL )
//	{
//		for ( int i=0; i < TOTAL_OBSTACLES; i++ )
//		{
//
//			if ( bottomCollision( &obs[i] ) && (leftCollision( &obs[i] ) || rightCollision( &obs[i] )) ) // collision at bottom of the object.
//			{
//				printf("Bottom collision.\n");
//				handleBottomCollision( &obs[i] );
//				bCollisions = bCollisions || true;
//			}
//			else { bCollisions = bCollisions || false; }
//
//			if ( topCollision( &obs[i] ) && (leftCollision( &obs[i] ) || rightCollision( &obs[i] )) ) // collision at top of the object.
//			{
//				printf("Top collision.\n");
//				handleTopCollision( &obs[i] );
//			}
//		}
//	}
//
//	if ( !bCollisions ) { fallTimer.start(); }
//	else { objVel_y = 0; fallTimer.stop(); }
//
//
//	objTexture.render(objPos_x, objPos_y);
//}


void Object::update ( double timeStep, SDL_Rect* obs, const int TOTAL_OBSTACLES )
{
	objPos_x += objVel_x * timeStep;

	if ( objPos_x < 0 ) { objPos_x = 0; }
	else if ( objPos_x > SCREEN_WIDTH - OBJ_WIDTH ) { objPos_x = SCREEN_WIDTH - OBJ_WIDTH; }

	if ( obs != NULL )
	{
		for ( int i=0; i < TOTAL_OBSTACLES; i++ )
		{
			if ( rightCollision( &obs[i] ) ) // && (topCollision( &obs[i] ) || bottomCollision( &obs[i] )) ) // collision at right of the object.
			{
				printf("Right collision.\n");
				handleRightCollision( &obs[i] );
			}


			else if ( leftCollision( &obs[i] ) )// && (topCollision( &obs[i] ) || bottomCollision( &obs[i] )) ) // collision at left of the object.
			{
				printf("Left collision.\n");
				handleLeftCollision( &obs[i] );
			}
		}
	}

	objVel_y += gravity*fallTimer.getTicks()*0.03;
	printf("objVel_y = %f   bCollisions = %d\n", objVel_y, bCollisions );
	objPos_y += objVel_y*timeStep;


	if ( objPos_y < 0 ) { objPos_y = 0; }
	if ( objPos_y + OBJ_HEIGHT >= SCREEN_HEIGHT ) { objPos_y = SCREEN_HEIGHT - OBJ_HEIGHT;  bCollisions = true; }
	else { bCollisions = false; }

	if ( obs != NULL )
	{
		for ( int i=0; i < TOTAL_OBSTACLES; i++ )
		{

			if ( bottomCollision( &obs[i] ) )// && (leftCollision( &obs[i] ) || rightCollision( &obs[i] )) ) // collision at bottom of the object.
			{
				printf("Bottom collision.\n");
				handleBottomCollision( &obs[i] );
				bCollisions = true;
			}
			else { bCollisions = bCollisions || false; }

			if ( topCollision( &obs[i] ) )// && (leftCollision( &obs[i] ) || rightCollision( &obs[i] )) ) // collision at top of the object.
			{
				printf("Top collision.\n");
				handleTopCollision( &obs[i] );
			}
		}
	}

	if ( !bCollisions ) { fallTimer.start(); }
	else { objVel_y = 0; fallTimer.stop(); }


	objTexture.render(objPos_x, objPos_y);
}






























void Object::setTexture( std::string path )
{
	objTexture.load( path.c_str() );
}


















