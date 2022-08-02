#include "Physics.h"
#include "Objects.h"
#include "Screen.h"


Physics::Physics()
{

}

Physics::~Physics()
{

}


//void Physics::apply ( Rectangles* rect )
//{
//	//clock_t t = clock();
//
//	static long int t = 0;
//	static int tempx = 0, tempy = 0;
//	static long double tempvel = 0;
//
//	double velx = rect->velocity.magn * cos(rect->velocity.dir);
//	double vely = rect->velocity.magn * sin(rect->velocity.dir);
//
//	tempy = -480 * vely * t*k; // TODO FIX : mathematically incorrect(?) . maybe not only this but all. :(  I got to sleep.
//
//	std::cout << "   t:" << t << "   y: " << rect->y << "   tempy: " << tempy << "   |v|: " << rect->velocity.magn << "   vely: " << vely << std::endl;
//
//
//	if ( sin(rect->velocity.dir) < 0 ) // == -1
//	{
//		std::cout << "1: " << std::flush;
//
//		rect->velocity.magn = gravity * t*k;
//
//		rect->y = tempy;
//
//	}
//
//	else if ( sin(rect->velocity.dir) > 0 ) // == 1
//	{
//		std::cout << "2: " << std::flush;
//
//		rect->velocity.magn = (tempvel - (gravity * t*k));
//
//		rect->y = Screen::SCREEN_HEIGHT -  rect->h + tempy ;
//
//	}
//
//	if ( rect->y > Screen::SCREEN_HEIGHT - rect->h )//|| rect->velocity.magn == 0 )
//	{
//		std::cout << "at edge" << std::endl;
//
//		rect->y = Screen::SCREEN_HEIGHT - rect->h;
//
//		rect->velocity.dir += M_PI;
//
//		t=0;
//
//		tempvel = 2*rect->velocity.magn; //Why I need to multiply by to to get a closer result? idk. ÇÜNKÜ MOMENTUMUN KORUNUMU AMK KAFAMI SÝKEYÝM...
//		//Ama neden tepeye gelince sýfýrlanmýyor ki...
//	}
//
//
//
//
//	SDL_Delay(1);
//
//	t++;
//
//}


//TODO Find a proper mathematical function which has the correct shape and consist of physical formulas, whose x is time and returns y value. TODO\\

void Physics::apply( Rectangles* rect)
{
	//static int dir = 1;
	static long int t = 0;

	int x = rect->x;
	int y = Screen::SCREEN_HEIGHT - rect->y;

	//std::cout << "start rect->y: " << rect->y << " | " << std::flush;

//	rect->velocity.magn += gravity * t*k;
//	y += ( ( sin(rect->velocity.dir) * rect->velocity.magn * t*k ) + ( 0.5 * gravity * t*k ) );

	y = y + ( sin(rect->velocity.dir) * rect->velocity.magn * t*k ) + ( 0.5 * gravity * pow(t*k,2) );


	//TODO FIX: linear movement.

	if ( y < 10 )
	{
		std::cout << "hit." << std::endl;
		y = 0;

		SDL_Delay(2000);

		rect->velocity.magn *= 2;
		rect->velocity.dir += M_PI;
		t = 0;

	}




	rect->y = Screen::SCREEN_HEIGHT - y;
	t++;

	std::cout << "y: " << y << "  rect->y: " << rect->y << "  v: " << rect->velocity.magn << "  t: " << t << std::endl;

	SDL_Delay(1);
}


































/*
	auto t_start = std::chrono::high_resolution_clock::now();
	// the work...
	auto t_end = std::chrono::high_resolution_clock::now();

	double elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end-t_start).count();
	*/































