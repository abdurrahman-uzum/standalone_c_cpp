#include "Texture.h"
#include "Timer.h"

#ifndef OBJECT_H_
#define OBJECT_H_

class DynamicObject
{
	public:
		static const int D_OBJ_WIDTH = 39;
		static const int D_OBJ_HEIGHT = 39;
		static const int D_OBJ_VEL = 300;

		const double GRAVITY = 1.5;

	public:
		DynamicObject();
		~DynamicObject();

		void applyEvent( SDL_Event& );

		void update( double timeStep, SDL_Rect* = NULL, const int TOTAL_OBSTACLES = 0 );
		void render( int cam_x, int cam_y );

		void setTexture ( std::string path );

		int getPos_x() { return dPos_x; }
		int getPos_y() { return dPos_y; }

		void handleRightCollision(SDL_Rect* obs);
		void handleLeftCollision(SDL_Rect* obs);
		void handleTopCollision(SDL_Rect* obs);
		void handleBottomCollision(SDL_Rect* obs);

		bool rightCollision(SDL_Rect*);
		bool leftCollision(SDL_Rect*);
		bool topCollision(SDL_Rect*);
		bool bottomCollision(SDL_Rect*);


	private:
		Texture dTexture;
		Timer fallTimer;

		int dPos_x, dPos_y;
		double dVel_x, dVel_y;

		bool resultBottomCollision;
		bool bCollisions;

};




class StaticObject
{
	public:
		StaticObject() { collisionBox = { 0, 0, 0, 0 }; };
		~StaticObject() { sTexture.free(); };

		void setTexture( std::string );
		void render( int cam_x, int cam_y );

		void initialize( int x, int y, int w, int h ) {	collisionBox = { x, y, w, h }; }

		SDL_Rect getCollisionBox() { return collisionBox; }



	private:
		Texture sTexture;
		SDL_Rect collisionBox;

};
















#endif /* OBJECT_H_ */
