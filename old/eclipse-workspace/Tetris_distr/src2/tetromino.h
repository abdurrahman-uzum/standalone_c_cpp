#ifndef TETROMINO_H_
#define TETROMINO_H_

#include "globals.h"


class Tetromino
{
	public:
		static const int C_LENGTH = 20;
		static const int INIT_POS_X = 20 + 11*20;
		static const int INIT_POS_Y = 60;

		int score;


	public:
		Tetromino( Type type );

		void rotate( rotationalDirection angDir );
		void render();
		void update();
		void applyEvent( SDL_Event& e );
		void convertSquareToSDL_Rect ( SDL_Rect* rect, Square& square );

		bool handleCollision();

		bool bCollision ( SDL_Rect );
		bool lCollision ( SDL_Rect );
		bool rCollision ( SDL_Rect );

		void fix();

		void recreate( Type type );


	private:

		Type type;
		Point center;

		Point nextPos;
		Square cells[4];

		bool bottomCollision;
		bool leftCollision;
		bool rightCollision;

		double gamespeed;



};












#endif /* TETROMINO_H_ */
