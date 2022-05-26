#ifndef OBJECTS_H_
#define OBJECTS_H_

#include <iostream>
#include <SDL.h>
#include <math.h>


class Rectangles
{

public:

public:
	int x,y;
	int w,h;

	double mass = 0;
	struct Velocity  { double magn = 0; double dir = (3*M_PI)/2; } velocity;

	double energy = 0;



public:
	Rectangles( int, int, int, int );
	~Rectangles();

	SDL_Rect getRect();



};




#endif /* OBJECTS_H_ */
