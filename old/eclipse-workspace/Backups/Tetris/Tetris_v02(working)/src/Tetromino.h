#ifndef TETROMINO_H_
#define TETROMINO_H_

#include <string>
#include "Globals.h"




class Tetromino
{
	public:
		static const int C_LENGTH = 20;
		static const int INIT_POS_X = 300;
		static const int INIT_POS_Y = 100;

	public:
		Tetromino( Type type );
		~Tetromino();

		void rotate( rotationalDirection angDir );
		void render();
		void update( double time );
		void applyEvent( SDL_Event& e );
		bool isLocked();
		void convertSquareToSDL_Rect ( SDL_Rect* rect, Square& square );
		void convertSDL_RectToSquare ( Square* square, SDL_Rect& rect );

		void getSDL_Rect( SDL_Rect* rect, Square& square );

		void handleCollision();

		bool bCollision ( SDL_Rect );
		bool lCollision ( SDL_Rect );
		bool rCollision ( SDL_Rect );

		void fix();

		void recreate( Type type );

	private:

		Type type;
		Point center;
		bool locked;

		Point nextPos;

		Square cells[4];

		bool bottomCollision;
		bool leftCollision;
		bool rightCollision;
};












#endif /* TETROMINO_H_ */
