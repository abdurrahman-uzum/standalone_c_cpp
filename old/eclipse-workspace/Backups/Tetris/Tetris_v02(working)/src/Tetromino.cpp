#include "Tetromino.h"
#include <iostream>


void destroyFullLine( int );
void detectFullLine(  );
void blinkLine( int );


Tetromino::Tetromino( Type type )
{
	this->type = type;

	center = { INIT_POS_X, INIT_POS_Y };

	nextPos = center;
	locked = false;

	bottomCollision = false;
	leftCollision = false;
	rightCollision = false;

	for ( int i=0; i < 4; i++ )
	{
		cells[i].w = C_LENGTH;
		cells[i].h = C_LENGTH;
	}

	switch ( type )
	{
		case I:
			cells[0].x = C_LENGTH/2;
			cells[0].y = -1.5*C_LENGTH;

			cells[1].x = C_LENGTH/2;
			cells[1].y = -C_LENGTH/2;

			cells[2].x = C_LENGTH/2;
			cells[2].y = C_LENGTH/2;

			cells[3].x = C_LENGTH/2;
			cells[3].y = 1.5*C_LENGTH;


		break;

		case O:
			cells[0].x = C_LENGTH/2;
			cells[0].y = C_LENGTH/2;

			cells[1].x = C_LENGTH/2;
			cells[1].y = -C_LENGTH/2;

			cells[2].x = -C_LENGTH/2;
			cells[2].y = -C_LENGTH/2;

			cells[3].x = -C_LENGTH/2;
			cells[3].y = C_LENGTH/2;

		break;

		case J:
			cells[0].x = -C_LENGTH/2;
			cells[0].y = C_LENGTH/2;

			cells[1].x = C_LENGTH/2;
			cells[1].y = C_LENGTH/2;

			cells[2].x = C_LENGTH/2;
			cells[2].y = -C_LENGTH/2;

			cells[3].x = C_LENGTH/2;
			cells[3].y = -1.5*C_LENGTH;

		break;

		case L:
			cells[0].x = C_LENGTH/2;
			cells[0].y = C_LENGTH/2;

			cells[1].x = -C_LENGTH/2;
			cells[1].y = C_LENGTH/2;

			cells[2].x = -C_LENGTH/2;
			cells[2].y = -C_LENGTH/2;

			cells[3].x = -C_LENGTH/2;
			cells[3].y = -1.5*C_LENGTH;

		break;

		case S:
			cells[0].x = -C_LENGTH/2;
			cells[0].y = C_LENGTH/2;

			cells[1].x = C_LENGTH/2;
			cells[1].y = C_LENGTH/2;

			cells[2].x = C_LENGTH/2;
			cells[2].y = -C_LENGTH/2;

			cells[3].x = 1.5*C_LENGTH;
			cells[3].y = -C_LENGTH/2;

		break;

		case Z:
			cells[0].x = C_LENGTH/2;
			cells[0].y = C_LENGTH/2;

			cells[1].x = -C_LENGTH/2;
			cells[1].y = C_LENGTH/2;

			cells[2].x = -C_LENGTH/2;
			cells[2].y = -C_LENGTH/2;

			cells[3].x = -1.5*C_LENGTH;
			cells[3].y = -C_LENGTH/2;

		break;

		case T:
			cells[0].x = C_LENGTH/2;
			cells[0].y = -C_LENGTH/2;

			cells[1].x = -C_LENGTH/2;
			cells[1].y = C_LENGTH/2;

			cells[2].x = C_LENGTH/2;
			cells[2].y = C_LENGTH/2;

			cells[3].x = 1.5*C_LENGTH;
			cells[3].y = C_LENGTH/2;
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
		convertSquareToSDL_Rect( &renderRect, cells[i] );

		renderRect.x += center.x;
		renderRect.y += center.y;

		SDL_RenderFillRect( gRenderer, &renderRect );
	}
}


void Tetromino::rotate( rotationalDirection rotDir )
{
	Square temp;

	for ( int i=0; i < 4; i++ )
	{
		temp = cells[i];

		if ( rotDir == CW )
		{
			cells[i].x = -temp.y;
			cells[i].y = temp.x;

			//cells[i].x -= C_LENGTH/2;
		}
		else if ( rotDir == CCW )
		{
			cells[i].x = temp.y;
			cells[i].y = -temp.x;

			//cells[i].y -= C_LENGTH/2;

		}

	}
}


void Tetromino::update( double time )
{
	static int i = 0;

	i++;

	if ( i%10 == 0 )
	{
		nextPos.y += C_LENGTH;
	}
	center = nextPos;
	handleCollision();
}




void Tetromino::applyEvent( SDL_Event& e )
{
	if ( e.type == SDL_KEYDOWN && !e.key.repeat )
	{
		switch ( e.key.keysym.sym )
		{
			case SDLK_LEFT:
				if ( !leftCollision ) { nextPos.x -= C_LENGTH; }
			break;

			case SDLK_RIGHT:
				if ( !rightCollision ) { nextPos.x += C_LENGTH; }
			break;

			case SDLK_UP:
				nextPos.y -= C_LENGTH;
			break;

			case SDLK_DOWN:
				nextPos.y += C_LENGTH;
			break;

			case SDLK_q:
				rotate( CCW );
			break;

			case SDLK_e:
				rotate( CW );
			break;

		}
	}
}



void Tetromino::convertSquareToSDL_Rect( SDL_Rect* rect, Square& square )
{
	rect->x = square.x - C_LENGTH/2;
	rect->y = square.y - C_LENGTH/2;
	rect->w = square.w;
	rect->h = square.h;
}




bool Tetromino::rCollision(SDL_Rect obs)
{
	bool temp = false;
	for ( int i=0; i < 4; i++ )
	{
		temp = temp || ( (cells[i].x + center.x + C_LENGTH >= obs.x && cells[i].x + center.x + C_LENGTH <= obs.x+obs.w) && !( (cells[i].y + center.y + C_LENGTH/2 <= obs.y) || (cells[i].y + center.y >= obs.y + obs.h) ) );
	}

	return temp;
}


bool Tetromino::lCollision(SDL_Rect obs)
{
	bool temp = false;
	for ( int i=0; i < 4; i++ )
	{
		temp = temp || ( ( (cells[i].x + center.x - C_LENGTH/2 <= obs.x+obs.w)  &&  (cells[i].x + center.x - C_LENGTH/2 >= obs.x) ) && !( (cells[i].y + center.y + C_LENGTH/2 <= obs.y) || (cells[i].y + center.y >= obs.y + obs.h) ) );
	}

	return temp;
}


bool Tetromino::bCollision(SDL_Rect obs)
{
	bool temp = false;
	for ( int i=0; i < 4; i++ )
	{
		temp = temp || ( ( ( cells[i].y + center.y + C_LENGTH/2 > obs.y)  &&  (cells[i].y + center.y + C_LENGTH/2 <= obs.y+obs.h)  )   &&   !( (cells[i].x + center.x - C_LENGTH/2  >= obs.x + obs.w) || (cells[i].x + center.x + C_LENGTH/2 <= obs.x) ) );
	}

	return temp;
}






void Tetromino::handleCollision()
{
	leftCollision = false;
	bottomCollision = false;
	rightCollision = false;

	// Check for right collision
	for ( int i=0; i < 4; i++ )
	{
		if ( center.x + cells[i].x + C_LENGTH/2 > gameBoundary.x + gameBoundary.w )
		{
			rightCollision = true;
			center.x = gameBoundary.x + gameBoundary.w - C_LENGTH/2 - cells[i].x;
			nextPos = center;
		}

		if ( center.x - C_LENGTH/2 + cells[i].x < gameBoundary.x )
		{
			leftCollision = true;
			center.x = gameBoundary.x + C_LENGTH/2 - cells[i].x;
			nextPos = center;
		}
	}

	// gameBoundary vertical collision:
	for ( int i=0; i < 4; i++ )
	{
		if ( center.y + cells[i].y + C_LENGTH/2 > gameBoundary.y + gameBoundary.h )
		{
			bottomCollision = true;
			break;
		}
	}

	for ( int j=0; j < PLAYGROUND_HEIGHT; j++ )
	{
		for ( int i=0; i < PLAYGROUND_WIDTH; i++ )
		{
			bottomCollision = bottomCollision || bCollision( statics[i][j] );

			rightCollision = rightCollision || rCollision( statics[i][j] );

			leftCollision = leftCollision || lCollision( statics[i][j] );
		}
	}

//	std::cout << "Bottom: " << bottomCollision << std::endl;
//
//	std::cout << "Left: " << leftCollision << std::endl;
//
//	std::cout << "Right: " << rightCollision << std::endl;

	if ( bottomCollision )
	{
		center.y -= C_LENGTH;

		fix();

		detectFullLine();

		int nextTetromino = rand()%7;

		recreate( Type(nextTetromino) );
	}

}




void Tetromino::fix()
{
	render();
	SDL_RenderPresent(gRenderer);

	SDL_Rect temp;

	for ( int i=0; i < 4; i++ )
	{
		convertSquareToSDL_Rect( &temp, cells[i] );

		temp.x += center.x;
		temp.y += center.y;

		statics [temp.x/C_LENGTH][temp.y/C_LENGTH] = temp;
	}
}



void Tetromino::recreate( Type type )
{
	this->type = type;

	center = { INIT_POS_X, INIT_POS_Y };

	nextPos = center;

	locked = false;

	switch ( type )
	{
		case I:
			cells[0].x = C_LENGTH/2;
			cells[0].y = -1.5*C_LENGTH;

			cells[1].x = C_LENGTH/2;
			cells[1].y = -C_LENGTH/2;

			cells[2].x = C_LENGTH/2;
			cells[2].y = C_LENGTH/2;

			cells[3].x = C_LENGTH/2;
			cells[3].y = 1.5*C_LENGTH;


		break;

		case O:
			cells[0].x = C_LENGTH/2;
			cells[0].y = C_LENGTH/2;

			cells[1].x = C_LENGTH/2;
			cells[1].y = -C_LENGTH/2;

			cells[2].x = -C_LENGTH/2;
			cells[2].y = -C_LENGTH/2;

			cells[3].x = -C_LENGTH/2;
			cells[3].y = C_LENGTH/2;

		break;

		case J:
			cells[0].x = -C_LENGTH/2;
			cells[0].y = C_LENGTH/2;

			cells[1].x = C_LENGTH/2;
			cells[1].y = C_LENGTH/2;

			cells[2].x = C_LENGTH/2;
			cells[2].y = -C_LENGTH/2;

			cells[3].x = C_LENGTH/2;
			cells[3].y = -1.5*C_LENGTH;

		break;

		case L:
			cells[0].x = C_LENGTH/2;
			cells[0].y = C_LENGTH/2;

			cells[1].x = -C_LENGTH/2;
			cells[1].y = C_LENGTH/2;

			cells[2].x = -C_LENGTH/2;
			cells[2].y = -C_LENGTH/2;

			cells[3].x = -C_LENGTH/2;
			cells[3].y = -1.5*C_LENGTH;

		break;

		case S:
			cells[0].x = -C_LENGTH/2;
			cells[0].y = C_LENGTH/2;

			cells[1].x = C_LENGTH/2;
			cells[1].y = C_LENGTH/2;

			cells[2].x = C_LENGTH/2;
			cells[2].y = -C_LENGTH/2;

			cells[3].x = 1.5*C_LENGTH;
			cells[3].y = -C_LENGTH/2;

		break;

		case Z:
			cells[0].x = C_LENGTH/2;
			cells[0].y = C_LENGTH/2;

			cells[1].x = -C_LENGTH/2;
			cells[1].y = C_LENGTH/2;

			cells[2].x = -C_LENGTH/2;
			cells[2].y = -C_LENGTH/2;

			cells[3].x = -1.5*C_LENGTH;
			cells[3].y = -C_LENGTH/2;

		break;

		case T:
			cells[0].x = C_LENGTH/2;
			cells[0].y = -C_LENGTH/2;

			cells[1].x = -C_LENGTH/2;
			cells[1].y = C_LENGTH/2;

			cells[2].x = C_LENGTH/2;
			cells[2].y = C_LENGTH/2;

			cells[3].x = 1.5*C_LENGTH;
			cells[3].y = C_LENGTH/2;
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




void blinkLine( int j )
{
	SDL_SetRenderDrawColor( gRenderer, 0xff, 0xff, 0xff, 0xff );

	for ( int i=0; i < PLAYGROUND_WIDTH; i++ )
	{
		SDL_RenderFillRect( gRenderer, &statics[i][j] );
	}

	SDL_RenderPresent( gRenderer );
}



void destroyFullLine( int row )
{
//	for ( int i=0; i < PLAYGROUND_WIDTH; i++ )
//	{
//		statics[i][row] = nullRect;
//	}
//
//	for ( int j=row-1; j > 1; j-- )
//	{
//		for ( int i=0; i < PLAYGROUND_WIDTH; i++ )
//		{
//			statics[i][j].y += Tetromino::C_LENGTH;
//		}
//	}


	for ( int j=row; j > 1; j-- )
	{
		for ( int i=0; i < PLAYGROUND_WIDTH; i++ )
		{
			statics[i][j] = statics[i][j-1];
			statics[i][j].y += Tetromino::C_LENGTH;
		}
	}

}




void detectFullLine()
{
	int filled = 0;

	for ( int j=0; j < PLAYGROUND_HEIGHT; j++ )
	{
		for ( int i=0; i < PLAYGROUND_WIDTH; i++ )
		{
			if ( statics[i][j].w != 0 )
			{
				filled++;
				std::cout << "FILLED BLOCK ! filled = " << filled << std::endl;
				//SDL_Delay(200);
			}
		}
		if ( filled >= 22 )
		{
			std::cout << "FILLED LINE ! " << j << std::endl;

			SDL_Delay(500);
			blinkLine(j);
			SDL_Delay(500);

			destroyFullLine(j);
		}
		filled = 0;
	}



}
















