#ifndef TETROMINO_H_
#define TETROMINO_H_

#include <string>
#include "Globals.h"

struct Point { int x; int y; };

class Tetromino
{
	public:
		static const int C_LENGTH = 20;
		static const int T_VEL = 300;


	public:
		Tetromino( Type type );
		~Tetromino();

		void rotate( std::string dir);
		void render();
		void update( double time );
		void applyEvent( SDL_Event& e );
		int getType();
		bool isLocked();
		void getCollisionBox( SDL_Rect* );
		SDL_Rect* getCellPosition();



	private:

		Type type;
		Point center;
		bool locked;
		SDL_Rect cells[4];
		SDL_Rect collisionBox[2];
		int vel_x;
		int vel_y;

		Point nextPos;



};




#endif /* TETROMINO_H_ */
