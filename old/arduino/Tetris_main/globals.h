#ifndef _GLOBALS_H
#define _GLOBALS_H

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>




extern Adafruit_PCD8544 display;

extern int const SCREEN_WIDTH;
extern int const SCREEN_HEIGHT;

struct Square { int x; int y; int w; int h; };
struct Point { int x; int y; };

extern const Square nullRect;

extern Square statics[12][21];

enum class Button { UP = 13, LEFT = 14, DOWN = 27, RIGHT = 26, TOP_LEFTE = 25, TOP_RIGHT = 33 };
enum class Type { I, O, L, J, S, Z, T };
enum class Rotation { CW, CCW };

const int UP = 13;
const int LEFT = 14;
const int DOWN = 27;
const int RIGHT = 26;
const int TOP_LEFT = 25;
const int TOP_RIGHT = 33;









#endif
