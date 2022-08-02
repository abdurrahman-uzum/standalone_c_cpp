#include "Tetromino.h"
#include <iostream>

Tetromino::Tetromino( Type type )
{
	this->type = type;

	center = { 300, 110 };
	nextPos = center;
	locked = false;

	vel_x = 0;
	vel_y = 0;

	for ( int i=0; i < 4; i++ )
	{
		cells[i].w = C_LENGTH;
		cells[i].h = C_LENGTH;
	}

	switch ( type )
	{
		case I:
			cells[0].x = -C_LENGTH/2;
			cells[0].y = -2*C_LENGTH;

			cells[1].x = -C_LENGTH/2;;
			cells[1].y = -C_LENGTH;

			cells[2].x = -C_LENGTH/2;
			cells[2].y = 0;

			cells[3].x = -C_LENGTH/2;;
			cells[3].y = C_LENGTH;
		break;

		case O:
			cells[0].x = 0;
			cells[0].y = -C_LENGTH;

			cells[1].x = -C_LENGTH;
			cells[1].y = -C_LENGTH;

			cells[2].x = -C_LENGTH;
			cells[2].y = 0;

			cells[3].x = 0;
			cells[3].y = 0;
		break;

		case J:
			cells[0].x = -C_LENGTH;
			cells[0].y = C_LENGTH/2;

			cells[1].x = 0;
			cells[1].y = C_LENGTH/2;

			cells[2].x = 0;
			cells[2].y = -C_LENGTH/2;

			cells[3].x = 0;
			cells[3].y = (-3.0/2.0)*C_LENGTH;
		break;

		case L:
			cells[0].x = 0;
			cells[0].y = C_LENGTH/2;

			cells[1].x = -C_LENGTH;
			cells[1].y = C_LENGTH/2;

			cells[2].x = -C_LENGTH;
			cells[2].y = -C_LENGTH/2;

			cells[3].x = -C_LENGTH;
			cells[3].y = (-3.0/2.0)*C_LENGTH;
		break;

		case S:
			cells[0].x = (-3.0/2.0)*C_LENGTH;
			cells[0].y = 0;

			cells[1].x = -C_LENGTH/2;
			cells[1].y = 0;

			cells[2].x = -C_LENGTH/2;
			cells[2].y = -C_LENGTH;

			cells[3].x = C_LENGTH/2;
			cells[3].y = -C_LENGTH;
		break;

		case Z:
			cells[0].x = C_LENGTH/2;
			cells[0].y = 0;

			cells[1].x = -C_LENGTH/2;
			cells[1].y = 0;

			cells[2].x = -C_LENGTH/2;
			cells[2].y = -C_LENGTH;

			cells[3].x = (-3.0/2.0)*C_LENGTH;
			cells[3].y = -C_LENGTH;
		break;

		case T:
			cells[0].x = (-3.0/2.0)*C_LENGTH;;
			cells[0].y = (-2.0/3.0)*C_LENGTH;

			cells[1].x = -C_LENGTH/2;
			cells[1].y = (-2.0/3.0)*C_LENGTH;

			cells[2].x = C_LENGTH/2;
			cells[2].y = (-2.0/3.0)*C_LENGTH;

			cells[3].x = -C_LENGTH/2;
			cells[3].y = (1.0/3.0)*C_LENGTH;
		break;

		default:
			cells[0].x = 0;
			cells[0].y = 0;

			cells[1].x = 0;
			cells[1].y = 0;

			cells[2].x = 0;
			cells[2].y = 0;

			cells[3].x = 0;
			cells[3].y = 0;
		break;
	}

}

Tetromino::~Tetromino()
{


}


void Tetromino::render()
{
	SDL_SetRenderDrawColor( gRenderer, 0x3C, 0x41, 0x2C, 0xFF );

	SDL_Rect renderRect;

	for ( int i=0; i < 4; i++ )
	{
		renderRect = cells[i];

		renderRect.x = cells[i].x + center.x;
		renderRect.y = cells[i].y + center.y;

		SDL_RenderFillRect( gRenderer, &renderRect );
	}
}


void Tetromino::rotate( std::string dir )
{
	SDL_Rect temp;

	for ( int i=0; i < 4; i++ )
	{
		temp = cells[i];

		if ( dir == "cw" )
		{
			cells[i].x = -temp.y;
			cells[i].y = temp.x;

			cells[i].x -= C_LENGTH/2;

//			if ( (cells[i].x - 30 ) % C_LENGTH != 0 )
//			{
//				cells[i].x -= ( cells[i].x - 30 ) % C_LENGTH ;
//			}
			if ( (cells[i].y - 10) % C_LENGTH != 0 )
			{
				cells[i].y -= ( cells[i].y - 10 ) % C_LENGTH;
			}


		}
		else if ( dir == "ccw" )
		{
			cells[i].x = temp.y;
			cells[i].y = -temp.x;

			cells[i].y -= C_LENGTH/2;

			if ( (cells[i].x - 30 ) % C_LENGTH != 0 )
			{
				cells[i].x -= ( cells[i].x - 30 ) % C_LENGTH ;
			}
//			if ( (cells[i].y + 10) % C_LENGTH != 0 )
//			{
//				cells[i].y -= ( cells[i].y + 10 ) % C_LENGTH;
//			}
		}


	}

}


void Tetromino::update( double time )
{
	center = nextPos;

}


//void Tetromino::applyEvent( SDL_Event& e )
//{
//	if ( e.type == SDL_KEYDOWN && !e.key.repeat )
//	{
//		switch ( e.key.keysym.sym )
//		{
//			case SDLK_LEFT:
//				vel_x -= T_VEL;
//			break;
//
//			case SDLK_RIGHT:
//				vel_x += T_VEL;
//			break;
//
//			case SDLK_UP:
//				vel_y -= T_VEL;
//			break;
//
//			case SDLK_DOWN:
//				vel_y += T_VEL;
//			break;
//
//			case SDLK_q:
//				rotate( "ccw" );
//			break;
//
//			case SDLK_e:
//				rotate( "cw" );
//			break;
//
//		}
//	}
//	else if ( e.type == SDL_KEYUP && !e.key.repeat )
//	{
//		switch ( e.key.keysym.sym )
//		{
//			case SDLK_LEFT:
//				vel_x += T_VEL;
//			break;
//
//			case SDLK_RIGHT:
//				vel_x -= T_VEL;
//			break;
//
//			case SDLK_UP:
//				vel_y += T_VEL;
//			break;
//
//			case SDLK_DOWN:
//				vel_y -= T_VEL;
//			break;
//
//		}
//	}
//}






void Tetromino::applyEvent( SDL_Event& e )
{
	if ( e.type == SDL_KEYDOWN && !e.key.repeat )
	{
		switch ( e.key.keysym.sym )
		{
			case SDLK_LEFT:
				nextPos.x -= C_LENGTH;
			break;

			case SDLK_RIGHT:
				nextPos.x += C_LENGTH;
			break;

			case SDLK_UP:
				nextPos.y -= C_LENGTH;
			break;

			case SDLK_DOWN:
				nextPos.y += C_LENGTH;
			break;

			case SDLK_q:
				rotate( "ccw" );
			break;

			case SDLK_e:
				rotate( "cw" );
			break;

		}
	}
}

























void Tetromino::getCollisionBox( SDL_Rect* cb )
{
	switch ( type )
	{
		case I:
			cb[0].x = cells[0].x + center.x;
			cb[0].y = cells[0].y + center.y;
			cb[0].w = cells[0].w;
			cb[0].h = 4*cells[0].h;

			cb[1] = cb[0];
		break;



	}


}























