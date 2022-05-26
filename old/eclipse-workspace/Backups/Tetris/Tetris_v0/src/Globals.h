#ifndef GLOBALS_H_
#define GLOBALS_H_




#include <stdio.h>
#include <SDL.h>

#include "Timer.h"

#define LIGHT_GREEN 0xA8, 0xC6, 0x4E, 0xFF
#define DARK_GREEN 0x3C, 0x41, 0x2C, 0xFF


extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

extern SDL_Window* window;
extern SDL_Renderer* gRenderer;

enum Type { I, O, J, L, S, Z, T };

extern const SDL_Rect gameBoundary;
extern const SDL_Rect scoreBox;
extern const SDL_Rect nextTetrBox;
extern const SDL_Rect pauseBox;
extern const SDL_Rect exitBox;




#endif
