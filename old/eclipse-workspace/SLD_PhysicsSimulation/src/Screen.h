#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL.h>
#include <stdio.h>




class Screen
{

public:
	const static int SCREEN_WIDTH = 640;
	const static int SCREEN_HEIGHT = 480;

private:
	SDL_Window* window;
    SDL_Renderer* renderer;


public:
	Screen();
	virtual ~Screen();

	bool init();
	void close();
	void update();
	void print();
	void renderObject( SDL_Rect );
	void clear();


};






#endif /* SCREEN_H_ */
