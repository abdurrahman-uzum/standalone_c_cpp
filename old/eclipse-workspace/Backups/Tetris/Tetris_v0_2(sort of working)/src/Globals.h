#ifndef GLOBALS_H_
#define GLOBALS_H_




#include <stdio.h>
#include <SDL.h>

#include "Timer.h"

#define LIGHT_GREEN 0xA8, 0xC6, 0x4E, 0xFF
#define DARK_GREEN 0x3C, 0x41, 0x2C, 0xFF


extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

extern const SDL_Rect gameBoundary;
extern const SDL_Rect scoreBox;
extern const SDL_Rect nextTetrBox;
extern const SDL_Rect pauseBox;
extern const SDL_Rect exitBox;

enum Type { I, O, J, L, S, Z, T };
enum rotationalDirection { CCW, CW };

extern SDL_Window* window;
extern SDL_Renderer* gRenderer;

struct Square
{
	int x;
	int y;
	int w;
	int h;
};

struct Point { int x; int y; };

extern SDL_Rect statics[];




#endif
