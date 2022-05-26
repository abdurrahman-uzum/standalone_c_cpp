#include "Object.h"
#include <math.h>
#include "Texture.h"

bool dead = false;
Timer L_keyPressTimer;
Timer R_keyPressTimer;
Timer U_keyPressTimer;

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
				if ( bCollisions )
				{
					dVel_y -= D_OBJ_VEL;
					fallTimer.start();
				}
			break;
		}
	}
	else if ( (e.type == SDL_KEYUP && !e.key.repeat) ) //TODO
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





//void DynamicObject::applyEvent( SDL_Event& e )
//{
//	if ( e.type == SDL_KEYDOWN )
//	{
//		if ( e.key.keysym.sym == SDLK_LEFT )
//		{
//			if ( !e.key.repeat ) { L_keyPressTimer.restart(); }
//			dVel_x -= D_OBJ_VEL*L_keyPressTimer.getTicks()*0.1;
//			if ( abs(dVel_x) > D_OBJ_VEL ) { dVel_x = -D_OBJ_VEL; }
//		}
//		if ( e.key.keysym.sym == SDLK_RIGHT )
//		{
//			if ( !e.key.repeat )  { R_keyPressTimer.restart(); }
//			dVel_x += D_OBJ_VEL*R_keyPressTimer.getTicks()*0.1;
//			if ( abs(dVel_x) > D_OBJ_VEL ) { dVel_x = D_OBJ_VEL; }
//		}
//		if ( !e.key.repeat && e.key.keysym.sym == SDLK_UP && bCollisions )
//		{
//			dVel_y -= D_OBJ_VEL;
//			fallTimer.start();
//		}
//	}
//
//	else if ( e.type == SDL_KEYUP ) //TODO
//	{
//		if ( e.key.keysym.sym == SDLK_LEFT )
//		{
//			if ( !e.key.repeat ) { L_keyPressTimer.start(); }
//			dVel_x -= D_OBJ_VEL*L_keyPressTimer.getTicks()*0.1;
//			if ( abs(dVel_x) > D_OBJ_VEL ) { dVel_x = -D_OBJ_VEL; }
//		}
//		if ( e.key.keysym.sym == SDLK_RIGHT )
//		{
//			if ( !e.key.repeat )  { R_keyPressTimer.start(); }
//			dVel_x += D_OBJ_VEL*R_keyPressTimer.getTicks()*0.1;
//			if ( abs(dVel_x) > D_OBJ_VEL ) { dVel_x = D_OBJ_VEL; }
//		}
//	}
//}





void DynamicObject::handleRightCollision(SDL_Rect obs)
{
	dPos_x = obs.x - D_OBJ_WIDTH;
}
void DynamicObject::handleLeftCollision(SDL_Rect obs)
{
	dPos_x = obs.x + obs.w;
}
void DynamicObject::handleTopCollision(SDL_Rect obs)
{
	dPos_y = obs.y + obs.h;
}
void DynamicObject::handleBottomCollision(SDL_Rect obs)
{
	dPos_y = obs.y - D_OBJ_WIDTH;
}



bool DynamicObject::rightCollision(SDL_Rect obs)
{
	return (dPos_x + D_OBJ_WIDTH >= obs.x && dPos_x + D_OBJ_WIDTH <= obs.x+obs.w) && !( (dPos_y + D_OBJ_HEIGHT <= obs.y) || (dPos_y >= obs.y + obs.h) );
}
bool DynamicObject::leftCollision(SDL_Rect obs)
{
	return (dPos_x <= obs.x+obs.w && dPos_x >= obs.x) && !( (dPos_y + D_OBJ_HEIGHT <= obs.y) || (dPos_y >= obs.y + obs.h) );
}
bool DynamicObject::topCollision(SDL_Rect obs)
{
	return (dPos_y <= obs.y+obs.h && dPos_y >= obs.y) && !( (dPos_x >= obs.x + obs.w) || (dPos_x + D_OBJ_WIDTH <= obs.x) );
}
bool DynamicObject::bottomCollision(SDL_Rect obs)
{
	return (dPos_y + D_OBJ_HEIGHT >= obs.y && dPos_y + D_OBJ_HEIGHT <= obs.y+obs.h) && !( (dPos_x  >= obs.x + obs.w) || (dPos_x + D_OBJ_WIDTH <= obs.x) );
}




void DynamicObject::update ( double timeStep, StaticObject* statics, const int TOTAL_OBSTACLES )
{
	dead = false;

	dPos_x += dVel_x * timeStep;

	if ( dPos_x < 0 ) { dPos_x = 0; }
	else if ( dPos_x > TOTAL_WIDTH - D_OBJ_WIDTH ) { dPos_x = TOTAL_WIDTH - D_OBJ_WIDTH; }

	if ( statics != nullptr )
	{
		for ( int i=0; i < TOTAL_OBSTACLES; i++ )
		{
			if ( rightCollision( statics[i].getCollisionBox() ) )
			{
				handleRightCollision( statics[i].getCollisionBox() );
				if ( statics[i].getType() == StaticObject::DEADLY ) { dead = true; }
			}


			else if ( leftCollision( statics[i].getCollisionBox() ) )
			{
				handleLeftCollision( statics[i].getCollisionBox() );
				if ( statics[i].getType() == StaticObject::DEADLY ) { dead = true; }
			}
		}
	}

	dVel_y += GRAVITY*fallTimer.getTicks()*0.04;
	dPos_y += dVel_y*timeStep;


	if ( dPos_y < 0 ) { dPos_y = 0; }
	if ( dPos_y + D_OBJ_HEIGHT >= TOTAL_HEIGHT ) { dPos_y = TOTAL_HEIGHT - D_OBJ_HEIGHT;  bCollisions = true; }
	else { bCollisions = false; }

	if ( statics != nullptr )
	{
		for ( int i=0; i < TOTAL_OBSTACLES; i++ )
		{

			if ( bottomCollision( statics[i].getCollisionBox() ) )
			{
				handleBottomCollision( statics[i].getCollisionBox() );
				bCollisions = true;
				if ( statics[i].getType() == StaticObject::DEADLY ) { dead = true; }
			}
			else { bCollisions = bCollisions || false; }

			if ( topCollision( statics[i].getCollisionBox() ) )
			{
				handleTopCollision( statics[i].getCollisionBox() );
				dVel_y = 50;
				if ( statics[i].getType() == StaticObject::DEADLY ) { dead = true; }
			}
		}
	}

	if ( !bCollisions ) { fallTimer.start(); }
	else { dVel_y = 0; fallTimer.stop(); }

	if ( dead )
	{
		respawn();
	}


}


void DynamicObject::render( int cam_x, int cam_y )
{
	dTexture.render(dPos_x - cam_x, dPos_y -  cam_y );
}

void DynamicObject::setTexture( std::string path )
{
	dTexture.load( path.c_str() );
}

void DynamicObject::respawn()
{
	SDL_Delay(200);

	dPos_x = 0;
	dPos_y = 0;

	resultBottomCollision = false;
	bCollisions = false;

}


//////////////////////////////////////////////////////////////////////////////


void StaticObject::setTexture( std::string path )
{
	sTexture.load( path.c_str() );
}

void StaticObject::render( SDL_Rect& cam )
{
//	if (
//		 (collisionBox.x + collisionBox.w >= cam.x) &&
//		 (collisionBox.x < cam.x + cam.w) &&
//		 (collisionBox.y + collisionBox.h <= cam.y) &&
//		 (collisionBox.y > cam.y + cam.h)
//	   )
	{
		sTexture.render(collisionBox.x - cam.x, collisionBox.y - cam.y);
	}
}
















