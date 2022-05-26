#ifndef PHYSICS_H_
#define PHYSICS_H_

#include <math.h>
#include <iostream>
#include "Objects.h"
#include <chrono>
#include <time.h>

//std::chrono::high_resolution_clock::time_point


//std::chrono::time_point<std::chrono::high_resolution_clock> armut = std::chrono::high_resolution_clock::now();

class Physics
{

public:
	double gravity = -9.81;
	double k = 0.001;

//	std::chrono::high_resolution_clock::time_point t_start;// = std::chrono::high_resolution_clock::now();
//	std::chrono::high_resolution_clock::time_point t_end;// = std::chrono::high_resolution_clock::now();

//	clock_t t_start;
//	clock_t t_end;


public:
	Physics();
	virtual ~Physics();


	void apply( Rectangles* rect);


};




#endif /* PHYSICS_H_ */
