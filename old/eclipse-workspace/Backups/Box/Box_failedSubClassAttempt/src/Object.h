#include "Texture.h"
#include "Timer.h"

#ifndef OBJECT_H_
#define OBJECT_H_

class Object
{
	public:
		Object( int x, int y, int w, int h );
		~Object();

		void render(int x, int y, int cam_x, int cam_y );
		void setTexture ( std::string path );

		int getPos_x() { return objPos_x; }
		int getPos_y() { return objPos_y; }
		int getWidth() { return objWidth; }
		int getHeight() { return objHeight; }

	private:
		Texture objTexture;
		int objPos_x, objPos_y;
		int objWidth, objHeight;
};


class DynamicObject : public Object
{
	public:
		static const int OBJ_VEL = 300L;
	public:
		DynamicObject(int x, int y, int w, int h);

		void applyEvent( SDL_Event& );
		void update( double timeStep, SDL_Rect* = NULL, const int TOTAL_OBSTACLES = 0 );

		void handleRightCollision(SDL_Rect* obs);
		void handleLeftCollision(SDL_Rect* obs);
		void handleTopCollision(SDL_Rect* obs);
		void handleBottomCollision(SDL_Rect* obs);

		bool rightCollision(SDL_Rect*);
		bool leftCollision(SDL_Rect*);
		bool topCollision(SDL_Rect*);
		bool bottomCollision(SDL_Rect*);

	private:
		int d_objPos_x, d_objPos_y;
		int d_objWidth, d_objHeight;
		double vel_x, vel_y;



};







































#endif /* OBJECT_H_ */
