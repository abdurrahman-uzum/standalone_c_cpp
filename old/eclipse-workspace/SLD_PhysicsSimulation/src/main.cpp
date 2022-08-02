#include <stdio.h>
#include <SDL.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>



#include "Screen.h"
#include "Objects.h"
#include "Physics.h"

using namespace std;




int main ( int argc, char* argv[] )
{
	Screen screen;
	Physics physics;

	if ( !screen.init() )
	{
		printf("ERROR1 !\n");
	}
	else
	{

		Rectangles rectangle(315, 0, 10, 10);

		screen.clear();
		screen.renderObject( rectangle.getRect() );

		SDL_Event event;
		bool quit = false;


		while ( !quit )
		{
			while ( SDL_PollEvent ( &event ) != 0 )
			{
				if ( event.type == SDL_QUIT )
				{
					quit = true;
				}
			}

			screen.clear();

			physics.apply(&rectangle);

			screen.renderObject(rectangle.getRect());

			screen.update();
		}


	}
	screen.close();







	return 0;
}
