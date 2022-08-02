/*
	COLOUR-MAP CREATOR FOR NEWTON-RAPHSON ITERATION
	
	Abdurrahman ÜZÜM
	20.12.2020

	This program produces a colour map in a given area, based on 
	Newton-Raphson Iteration to [ z^3 - 1 ] function. Resultant 
	image is shown using SDL.

	If you want to compile and run this code yourself, you will
	need to link against SDL2.lib and SDL2main.lib, put SDL2.dll
	in the same directory with executable. Also specify the path 
	of SDL header files.

	To get SDL:
	https://www.libsdl.org/

*/



#include <SDL.h>
#include <stdio.h>     
#include <complex>    

typedef std::complex<double> complex;


//Dimentions of the popping window, nothing special with the default values.
const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 700;

//Globally defining roots so I don't bother to pass them to functions
const complex z1 = complex(  1,    0 );
const complex z2 = complex( -0.5,  0.8660254038 );
const complex z3 = complex( -0.5, -0.8660254038 );

//Pixels per unit length. Increase/decrease to zoom in/out
const double ppul = 100;

/*
	Limits for area to be scanned.
	'scan' function scans from -lim to +lim (pixels)
	or -lim/ppul to +lim/ppul (mathematically)

	DO NOT modify these parameters, weird stuff happens.
*/
const int xlim = SCREEN_WIDTH/2;
const int ylim = SCREEN_HEIGHT/2;

//Tolerance for an approximation to be acceptable. I randomly chosed a small value.
const double tol = 0.00001;

//Maximum number of attempts before concluding that iteration diverges.
const int max_itr = 100;


SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

//Function to initialize & prepare SDL
bool init()
{
	if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "ERR0\n" );
		return 0;
	}

	if ( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
	{
		printf( "WR1\n" );
	}

	window = SDL_CreateWindow( "", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
	if ( window == NULL )
	{
		printf( "ERR1\n" );
		return false;
	}

	renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
	if ( renderer == NULL )
	{
		printf( "ERR2\n" );
		return false;
	}

	SDL_SetRenderDrawColor( renderer, 0xff, 0xff, 0xff, 0xff );
	
	return true;
}

//Function to properly shutdown SDL
void close()
{
	SDL_DestroyRenderer( renderer );
	renderer = NULL;

	SDL_DestroyWindow( window );
	window = NULL;

	SDL_Quit();
}


/* 
	Functions to convert conventional cartesian coordinate system (origin at centre)
	to computer screen coordinate system (origin at top left).
*/
double X ( double xi )
{
	return SCREEN_WIDTH/2 + xi ;
}
double Y ( double yi )
{
	return SCREEN_HEIGHT/2 - yi ;
}


// Given mathematical function: f = x^3 - 1
complex f ( complex z )
{
	return pow(z, 3) - 1.0;
}

// Derivative of f: f' = 3z^2
complex derf ( complex z )
{
	return 3.0 * pow(z, 2);
} 

/*
	Calculates: z(n+1) = f(z(n))/f'(z(n))
	As n approaches infinity, z(n) approaches one of the roots, 
	if the iteration is convergent for given input.

	Could have been recursive, which would make more sense
	but I don't like recursive functions. So it's going to be 
	called by 'iterate' function in a for loop.
*/
complex N ( complex z )
{
	return z - f(z)/derf(z);
}


/*
	Applies Newton-Raphson iteration.
	If distance of the 'i'th result of iteration to any root
	is within the range determined by the 'tol' global variable,
	returns 1, 2 or 3 according to approached root.

	If after 'max_itr' iterations result still does not approach
	a root, iteration is colcluded divergent for given input and
	function aborts.
*/
int iterate( complex z )
{
	for ( int i=0; i < max_itr; i++ )
	{
		z = N( z );

		if ( abs( z - z1 ) < tol )
		{
			return 1;
		}
		if ( abs( z - z2 ) < tol )
		{
			return 2;
		}
		if ( abs( z - z3 ) < tol )
		{
			return 3;
		}
	}

	return 0;
}


/*
	Scans a rectangular area: 2*xlim by 2*ylim.
	Calls iterate function for each pixel.
	Colours the given pixel based on the results of iterate function.
*/
void scan()
{
	for( int y = ylim; y > -ylim; y-- )
	{
		for( int x = -xlim; x < xlim; x++ )
		{
			//Passing current coordinates into iterate function as a complex number.
			//And chosing the colour based on the result.
			switch ( iterate( complex(x/ppul, y/ppul) ) )
			{
				case 1:
					SDL_SetRenderDrawColor( renderer, 0xff, 0x00, 0x00, 0xff );
				break;

				case 2:
					SDL_SetRenderDrawColor( renderer, 0x00, 0xff, 0x00, 0xff );
				break;

				case 3:
					SDL_SetRenderDrawColor( renderer, 0x00, 0x00, 0xff, 0xff );
				break;

				default:
					SDL_SetRenderDrawColor( renderer, 0x00, 0x00, 0x00, 0xff );
			}

			//Colour the current pixel.
			SDL_RenderDrawPoint( renderer, X(x), Y(y) );

			//Uncomment the code below to see colouring in real time. ( Very slow and not as impressive as it sounds )
			//SDL_RenderPresent( renderer );
		}
	}
}



int main ( int argc, char* argv[] )
{
	//Initializing & preparing SDL
	if ( !init() ) { return -1; }

	//Scan the entire window.
	scan();

	//Draw Axis
	SDL_SetRenderDrawColor( renderer, 0xff, 0xff, 0xff, 0xff );
	SDL_RenderDrawLine( renderer, 0, SCREEN_HEIGHT/2, SCREEN_WIDTH, SCREEN_HEIGHT/2 );
	SDL_RenderDrawLine( renderer, SCREEN_WIDTH/2, 0, SCREEN_WIDTH/2, SCREEN_HEIGHT );


	//Markings of the roots at screen. Yes, rectangles look ugly, I know.
	SDL_Rect mark_z1 = { X(real(z1)*ppul) - 5, Y(imag(z1)*ppul) - 5, 10, 10 };
	SDL_Rect mark_z2 = { X(real(z2)*ppul) - 5, Y(imag(z2)*ppul) - 5, 10, 10 };
	SDL_Rect mark_z3 = { X(real(z3)*ppul) - 5, Y(imag(z3)*ppul) - 5, 10, 10 };

	SDL_RenderFillRect( renderer, &mark_z1 );
	SDL_RenderFillRect( renderer, &mark_z2 );
	SDL_RenderFillRect( renderer, &mark_z3 );

		
	//Rendering the result on to screen.
	SDL_RenderPresent( renderer );


	//A very poor way to keep the window open until user closes.
	SDL_Event e;
	for(;;)
	{
		while( SDL_PollEvent( &e ) != 0 )
		{
			if ( e.type == SDL_QUIT )
			{
				goto Close;
			}
		}
	}

	Close:

	close();

	return 0;
}


