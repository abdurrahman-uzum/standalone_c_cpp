#include "Texture.h"
#include "Timer.h"

#ifndef OBJECT_H_
#define OBJECT_H_


class StaticObject
{
	public:
		enum Type { PASSIVE = 1, DEADLY = 2, DESTROYABLE = 3 };

	public:
		StaticObject() { collisionBox = { 0, 0, 0, 0 }; type = PASSIVE; };
		~StaticObject() { sTexture.free(); };

		void setTexture( std::string );
		//void render( int cam_x, int cam_y );
		void render( SDL_Rect& );

		void initialize( int x, int y, int w, int h, Type type ) {	collisionBox = { x, y, w, h };  this->type = type; }

		SDL_Rect getCollisionBox() { return collisionBox; }

		Type getType() { return type; }


	private:
		Texture sTexture;
		SDL_Rect collisionBox;
		Type type;

};



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

		void update( double timeStep, StaticObject* statics, const int TOTAL_OBSTACLES = 0 );
		void render( int cam_x, int cam_y );

		void setTexture ( std::string path );

		int getPos_x() { return dPos_x; }
		int getPos_y() { return dPos_y; }

		void handleRightCollision(SDL_Rect obs);
		void handleLeftCollision(SDL_Rect obs);
		void handleTopCollision(SDL_Rect obs);
		void handleBottomCollision(SDL_Rect obs);

		bool rightCollision(SDL_Rect);
		bool leftCollision(SDL_Rect);
		bool topCollision(SDL_Rect);
		bool bottomCollision(SDL_Rect);

		void respawn();


	private:
		Texture dTexture;
		Timer fallTimer;

		int dPos_x, dPos_y;
		double dVel_x, dVel_y;

		bool resultBottomCollision;
		bool bCollisions;

};





















#endif /* OBJECT_H_ */
