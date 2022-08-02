#ifndef GLOBALS_H_
#define GLOBALS_H_

#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <math.h>
#include <string>
#include <time.h>

#include "Texture.h"


#define LIGHT_GREEN 0xA8, 0xC6, 0x4E, 0xFF
#define DARK_GREEN 0x3C, 0x41, 0x2C, 0xFF


extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

extern SDL_Window* window;
extern SDL_Renderer* gRenderer;

extern Texture gameOverTexture;

extern Texture number[];
extern Texture nextTetrTexture[];

extern const SDL_Rect nullRect;
extern SDL_Rect statics[23][35];


enum Type { I, O, J, L, S, Z, T };
enum rotationalDirection { CCW, CW };

extern Type nextTetrominoType;


struct Square
{
	int x;
	int y;
	int w;
	int h;
};

struct Point
{
	int x;
	int y;
};
















#endif
