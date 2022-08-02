#include "Texture.h"
#include "Timer.h"

#ifndef OBJECT_H_
#define OBJECT_H_

class Object
{
	public:
		static const int OBJ_WIDTH = 39;
		static const int OBJ_HEIGHT = 39;
		static const int OBJ_VEL = 300;

	public:
		Object();
		~Object();

		void applyEvent( SDL_Event& );

		void update( double timeStep, SDL_Rect* = NULL, const int TOTAL_OBSTACLES = 0 ); // and render eheheeh.(not anymore)
		void render( int cam_x, int cam_y );

		void setTexture ( std::string path );

		int getPos_x() { return objPos_x; }
		int getPos_y() { return objPos_y; }

		//int handleCollision(SDL_Rect* obs);

		void handleRightCollision(SDL_Rect* obs);
		void handleLeftCollision(SDL_Rect* obs);
		void handleTopCollision(SDL_Rect* obs);
		void handleBottomCollision(SDL_Rect* obs);

		bool rightCollision(SDL_Rect*);
		bool leftCollision(SDL_Rect*);
		bool topCollision(SDL_Rect*);
		bool bottomCollision(SDL_Rect*);


	private:
		Texture objTexture;
		int objPos_x, objPos_y;
		double objVel_x, objVel_y;



};
















#endif /* OBJECT_H_ */
