#include <iostream>
#include <SDL.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#include "Screen.h"
#include "Particle.h"
#include "Swarm.h"

using namespace std;
using namespace au;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;


int main ( int argc, char* argv[] )
{
	srand( time(NULL) );
	Screen screen;

	if ( !screen.init() )
	{
		printf("Error");
	}

	Swarm swarm;

	while ( true )
	{
		int elapsed = SDL_GetTicks();

		//screen.clear();

		swarm.update(elapsed);

		unsigned char red = (1 + sin(elapsed * 0.002)) * 128;
		unsigned char green = (1 + sin(elapsed * 0.005)) * 128;
		unsigned char blue = (1 + sin(elapsed * 0.009)) * 128;

		const Particle * const pParticles = swarm.getParticles();

		for ( int i=0; i<Swarm::NPARTICLES; i++ )
		{
			Particle particle = pParticles[i];

			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2;
			int y = particle.m_y * Screen::SCREEN_WIDTH / 2 + Screen::SCREEN_HEIGHT / 2;

			screen.setPixel ( x, y, 255, 255, 255 );

		}

		screen.boxBlur();

		screen.update();


		if ( !screen.processEvents() ) { break; }

	}


	screen.close();

	return 0;
}
