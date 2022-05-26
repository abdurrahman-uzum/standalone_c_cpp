#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

//Maze settings:
#define SIZE 10
#define FRAME_DELAY 400
#define INIT_X 1
#define INIT_Y 1
#define FINISH_X 8
#define FINISH_Y 8

#define BLOCK 'X'

int maze [SIZE][SIZE] =
{
    {254,254,254,254,254,254,254,254,254,254},
    {254, 48, 48, 48, 48, 48, 48, 48, 48,254},
    {254,254, 48,254, 48,254,254,254, 48,254},
    {254,254, 48,254, 48,254, 48,254, 48,254},
    {254,254, 48,254, 48,254, 48,254, 48,254},
    {254, 48, 48,254, 48,254,254,254, 48,254},
    {254,254, 48,254, 48, 48, 48, 48, 48,254},
    {254,254, 48,254,254,254,254,254, 48,254},
    {254, 48, 48,254, 48, 48, 48, 48, 48,254},
    {254,254,254,254,254,254,254,254,254,254}
};


int blankMaze [SIZE][SIZE] =
{
    {254,254,254,254,254,254,254,254,254,254},
    {254, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,254},
    {254,254, 0 ,254, 0 ,254,254,254, 0 ,254},
    {254,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254},
    {254,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254},
    {254, 0 , 0 ,254, 0 ,254,254,254, 0 ,254},
    {254,254, 0 ,254, 0 , 0 , 0 , 0 , 0 ,254},
    {254,254, 0 ,254,254,254,254,254, 0 ,254},
    {254, 0 , 0 ,254, 0 , 0 , 0 , 0 , 0 ,254},
    {254,254,254,254,254,254,254,254,254,254}
};




/*
int maze [SIZE][SIZE] =
{
    {254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254},
    {254, 48, 48, 48, 48, 48, 48,254, 48,254, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48,254, 48, 48, 48, 48, 48, 48, 48,254, 48, 48, 48, 48, 48,254},
    {254,254,254, 48,254,254, 48,254, 48,254,254,254,254, 48,254,254,254,254,254,254,254,254,254,254, 48,254, 48,254, 48,254, 48,254,254,254, 48,254,254,254, 48,254},
    {254, 48,254, 48,254,254, 48, 48, 48, 48, 48,254,254, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48,254, 48,254, 48,254, 48,254, 48,254, 48, 48, 48,254, 48, 48, 48,254},
    {254, 48,254, 48, 48, 48,254,254, 48,254, 48, 48,254, 48,254,254,254,254, 48,254, 48,254, 48,254, 48,254, 48,254, 48,254, 48,254, 48,254, 48,254,254,254,254,254},
    {254, 48,254, 48,254, 48,254,254,254,254,254, 48, 48, 48, 48, 48,254,254, 48,254, 48,254, 48,254, 48,254,254,254, 48,254, 48,254, 48,254, 48, 48, 48, 48, 48,254},
    {254, 48,254, 48,254, 48, 48, 48, 48,254,254, 48,254,254,254, 48,254,254, 48,254, 48,254, 48,254, 48, 48, 48, 48, 48,254, 48, 48, 48,254,254,254,254,254,254,254},
    {254, 48,254,254,254, 48,254,254, 48,254,254, 48, 48, 48,254, 48,254, 48, 48,254, 48,254, 48,254,254,254,254,254,254,254,254,254,254,254, 48, 48, 48, 48, 48,254},
    {254, 48, 48, 48, 48, 48, 48,254, 48,254,254,254,254,254,254, 48,254, 48,254,254, 48,254, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48,254, 48,254, 48,254, 48,254},
    {254, 48,254,254,254,254,254,254,254,254, 48, 48, 48, 48,254, 48,254, 48,254,254, 48,254,254,254,254,254,254,254,254,254,254,254, 48,254, 48,254, 48,254, 48,254},
    {254, 48,254,254,254,254,254,254,254,254,254,254,254, 48,254, 48,254, 48,254,254, 48,254, 48, 48, 48,254, 48, 48, 48, 48, 48,254, 48,254, 48,254, 48,254, 48,254},
    {254, 48, 48, 48, 48, 48, 48,254, 48,254, 48, 48,254, 48, 48, 48,254, 48,254,254, 48,254, 48,254, 48,254, 48,254,254,254, 48,254, 48,254, 48,254, 48,254, 48,254},
    {254,254,254, 48,254,254, 48,254, 48,254,254, 48,254,254,254,254, 48, 48, 48,254, 48,254, 48,254, 48,254, 48, 48, 48,254, 48,254, 48,254, 48,254,254,254, 48,254},
    {254, 48,254, 48,254,254, 48, 48, 48,254, 48, 48,254, 48, 48, 48, 48,254, 48,254, 48,254, 48,254, 48,254, 48,254, 48,254, 48,254,254,254, 48,254, 48, 48, 48,254},
    {254, 48,254, 48, 48, 48,254,254, 48,254, 48,254,254, 48,254,254,254,254, 48,254, 48,254, 48,254, 48,254, 48,254, 48,254, 48, 48, 48, 48, 48,254, 48,254, 48,254},
    {254, 48,254, 48,254, 48,254,254,254,254, 48,254,254, 48,254, 48, 48, 48, 48,254, 48,254,254,254, 48,254, 48,254, 48,254,254,254,254,254,254,254, 48,254, 48,254},
    {254, 48,254, 48,254, 48, 48, 48, 48,254, 48,254,254, 48,254,254,254,254, 48,254, 48, 48, 48, 48, 48,254, 48,254, 48, 48, 48, 48,254, 48, 48, 48, 48,254, 48,254},
    {254, 48,254,254,254, 48,254,254, 48,254, 48,254, 48, 48, 48, 48, 48, 48,254,254,254,254,254,254, 48,254, 48,254, 48,254,254, 48,254,254,254, 48,254,254, 48,254},
    {254, 48, 48, 48, 48, 48, 48,254, 48, 48, 48,254,254,254,254,254,254, 48, 48, 48, 48, 48, 48,254, 48,254, 48,254, 48, 48,254, 48,254, 48,254, 48,254, 48, 48,254},
    {254, 48,254,254,254,254,254,254,254, 48,254,254, 48, 48, 48, 48, 48, 48,254,254,254,254, 48,254, 48,254, 48,254,254, 48,254,254,254, 48,254, 48,254,254, 48,254},
    {254, 48,254,254,254,254,254,254,254, 48,254,254,254,254,254,254,254, 48,254,254, 48,254, 48,254, 48,254, 48, 48,254, 48,254,254,254, 48,254, 48, 48,254, 48,254},
    {254, 48, 48, 48, 48, 48, 48,254, 48,254, 48, 48, 48, 48, 48,254, 48, 48, 48,254, 48, 48, 48,254, 48,254, 48,254,254, 48, 48, 48,254, 48,254,254,254,254, 48,254},
    {254,254,254, 48,254,254, 48,254, 48,254,254,254,254, 48,254,254,254,254,254,254, 48,254, 48,254,254,254, 48,254,254,254, 48,254, 48, 48, 48, 48, 48, 48, 48,254},
    {254, 48,254, 48,254,254, 48, 48, 48, 48, 48,254,254, 48, 48, 48, 48, 48, 48,254, 48,254, 48,254, 48,254, 48,254, 48,254, 48,254, 48,254,254,254, 48,254,254,254},
    {254, 48,254, 48, 48, 48,254,254, 48,254, 48, 48,254,254,254,254,254,254,254,254, 48,254, 48,254, 48,254, 48,254, 48, 48, 48,254, 48, 48, 48,254, 48,254, 48,254},
    {254, 48,254, 48,254, 48,254,254,254,254,254, 48, 48, 48, 48, 48,254, 48,254, 48, 48,254, 48, 48, 48,254, 48,254, 48,254,254,254, 48,254,254,254, 48,254, 48,254},
    {254, 48,254, 48,254, 48, 48, 48, 48,254,254, 48,254,254,254, 48,254, 48,254,254,254,254, 48,254, 48,254, 48,254, 48, 48, 48,254, 48,254, 48,254, 48, 48, 48,254},
    {254, 48,254,254,254, 48,254,254, 48,254,254, 48, 48, 48,254, 48,254, 48, 48, 48, 48,254, 48,254, 48,254, 48,254,254,254,254,254, 48,254, 48,254,254, 48,254,254},
    {254, 48, 48, 48, 48, 48, 48,254, 48,254,254,254,254,254,254, 48,254, 48,254,254, 48,254, 48,254, 48,254, 48, 48, 48,254, 48,254, 48,254, 48,254,254, 48, 48,254},
    {254, 48,254,254,254,254,254,254,254,254, 48, 48, 48, 48,254, 48,254, 48,254, 48, 48,254, 48,254, 48,254, 48,254, 48,254, 48,254, 48,254, 48,254,254,254,254,254},
    {254, 48,254,254,254,254,254,254,254,254,254,254,254, 48,254, 48,254, 48,254, 48,254,254, 48,254,254,254, 48,254, 48,254, 48,254, 48, 48, 48, 48, 48, 48, 48,254},
    {254, 48, 48, 48, 48, 48, 48,254, 48,254, 48, 48,254, 48, 48, 48,254, 48,254,254, 48,254, 48, 48, 48, 48, 48,254, 48, 48, 48,254,254,254,254,254, 48,254, 48,254},
    {254,254,254, 48,254,254, 48,254, 48,254,254, 48,254,254,254,254, 48, 48, 48,254, 48,254,254,254,254,254,254,254, 48,254, 48, 48, 48, 48,254,254, 48,254, 48,254},
    {254, 48,254, 48,254,254, 48, 48, 48,254, 48, 48,254, 48, 48, 48, 48,254, 48,254, 48,254, 48, 48, 48,254, 48, 48, 48,254,254,254,254,254,254,254, 48,254, 48,254},
    {254, 48,254, 48, 48, 48,254,254, 48,254, 48,254,254, 48,254,254,254,254, 48,254, 48,254, 48,254,254,254, 48,254,254, 48, 48, 48, 48, 48, 48,254, 48,254, 48,254},
    {254, 48,254, 48,254, 48,254,254,254,254, 48,254,254, 48,254, 48, 48, 48, 48,254, 48, 48, 48,254, 48,254, 48, 48, 48, 48,254,254, 48,254,254,254, 48,254,254,254},
    {254, 48,254, 48,254, 48, 48, 48, 48,254, 48,254,254, 48,254,254,254,254, 48,254, 48,254, 48,254, 48,254,254,254, 48,254, 48, 48, 48, 48, 48,254, 48, 48, 48,254},
    {254, 48,254,254,254, 48,254,254, 48,254, 48,254, 48, 48, 48, 48, 48, 48,254,254, 48,254, 48,254, 48,254, 48, 48, 48,254, 48,254, 48,254, 48,254,254,254, 48,254},
    {254, 48, 48, 48, 48, 48, 48,254, 48, 48, 48,254,254,254,254,254,254, 48, 48, 48, 48,254, 48, 48, 48,254, 48,254,254,254, 48,254,254,254, 48, 48, 48,254, 48,254},
    {254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254},
};

int blankMaze [SIZE][SIZE] =
{
    {254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254},
    {254, 0 , 0 , 0 , 0 , 0 , 0 ,254, 0 ,254, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,254, 0 , 0 , 0 , 0 , 0 , 0 , 0 ,254, 0 , 0 , 0 , 0 , 0 ,254},
    {254,254,254, 0 ,254,254, 0 ,254, 0 ,254,254,254,254, 0 ,254,254,254,254,254,254,254,254,254,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254,254,254, 0 ,254,254,254, 0 ,254},
    {254, 0 ,254, 0 ,254,254, 0 , 0 , 0 , 0 , 0 ,254,254, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254, 0 , 0 , 0 ,254, 0 , 0 , 0 ,254},
    {254, 0 ,254, 0 , 0 , 0 ,254,254, 0 ,254, 0 , 0 ,254, 0 ,254,254,254,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254,254,254,254,254},
    {254, 0 ,254, 0 ,254, 0 ,254,254,254,254,254, 0 , 0 , 0 , 0 , 0 ,254,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254,254,254, 0 ,254, 0 ,254, 0 ,254, 0 , 0 , 0 , 0 , 0 ,254},
    {254, 0 ,254, 0 ,254, 0 , 0 , 0 , 0 ,254,254, 0 ,254,254,254, 0 ,254,254, 0 ,254, 0 ,254, 0 ,254, 0 , 0 , 0 , 0 , 0 ,254, 0 , 0 , 0 ,254,254,254,254,254,254,254},
    {254, 0 ,254,254,254, 0 ,254,254, 0 ,254,254, 0 , 0 , 0 ,254, 0 ,254, 0 , 0 ,254, 0 ,254, 0 ,254,254,254,254,254,254,254,254,254,254,254, 0 , 0 , 0 , 0 , 0 ,254},
    {254, 0 , 0 , 0 , 0 , 0 , 0 ,254, 0 ,254,254,254,254,254,254, 0 ,254, 0 ,254,254, 0 ,254, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,254, 0 ,254, 0 ,254, 0 ,254},
    {254, 0 ,254,254,254,254,254,254,254,254, 0 , 0 , 0 , 0 ,254, 0 ,254, 0 ,254,254, 0 ,254,254,254,254,254,254,254,254,254,254,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254},
    {254, 0 ,254,254,254,254,254,254,254,254,254,254,254, 0 ,254, 0 ,254, 0 ,254,254, 0 ,254, 0 , 0 , 0 ,254, 0 , 0 , 0 , 0 , 0 ,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254},
    {254, 0 , 0 , 0 , 0 , 0 , 0 ,254, 0 ,254, 0 , 0 ,254, 0 , 0 , 0 ,254, 0 ,254,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254,254,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254},
    {254,254,254, 0 ,254,254, 0 ,254, 0 ,254,254, 0 ,254,254,254,254, 0 , 0 , 0 ,254, 0 ,254, 0 ,254, 0 ,254, 0 , 0 , 0 ,254, 0 ,254, 0 ,254, 0 ,254,254,254, 0 ,254},
    {254, 0 ,254, 0 ,254,254, 0 , 0 , 0 ,254, 0 , 0 ,254, 0 , 0 , 0 , 0 ,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254,254,254, 0 ,254, 0 , 0 , 0 ,254},
    {254, 0 ,254, 0 , 0 , 0 ,254,254, 0 ,254, 0 ,254,254, 0 ,254,254,254,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254, 0 , 0 , 0 , 0 , 0 ,254, 0 ,254, 0 ,254},
    {254, 0 ,254, 0 ,254, 0 ,254,254,254,254, 0 ,254,254, 0 ,254, 0 , 0 , 0 , 0 ,254, 0 ,254,254,254, 0 ,254, 0 ,254, 0 ,254,254,254,254,254,254,254, 0 ,254, 0 ,254},
    {254, 0 ,254, 0 ,254, 0 , 0 , 0 , 0 ,254, 0 ,254,254, 0 ,254,254,254,254, 0 ,254, 0 , 0 , 0 , 0 , 0 ,254, 0 ,254, 0 , 0 , 0 , 0 ,254, 0 , 0 , 0 , 0 ,254, 0 ,254},
    {254, 0 ,254,254,254, 0 ,254,254, 0 ,254, 0 ,254, 0 , 0 , 0 , 0 , 0 , 0 ,254,254,254,254,254,254, 0 ,254, 0 ,254, 0 ,254,254, 0 ,254,254,254, 0 ,254,254, 0 ,254},
    {254, 0 , 0 , 0 , 0 , 0 , 0 ,254, 0 , 0 , 0 ,254,254,254,254,254,254, 0 , 0 , 0 , 0 , 0 , 0 ,254, 0 ,254, 0 ,254, 0 , 0 ,254, 0 ,254, 0 ,254, 0 ,254, 0 , 0 ,254},
    {254, 0 ,254,254,254,254,254,254,254, 0 ,254,254, 0 , 0 , 0 , 0 , 0 , 0 ,254,254,254,254, 0 ,254, 0 ,254, 0 ,254,254, 0 ,254,254,254, 0 ,254, 0 ,254,254, 0 ,254},
    {254, 0 ,254,254,254,254,254,254,254, 0 ,254,254,254,254,254,254,254, 0 ,254,254, 0 ,254, 0 ,254, 0 ,254, 0 , 0 ,254, 0 ,254,254,254, 0 ,254, 0 , 0 ,254, 0 ,254},
    {254, 0 , 0 , 0 , 0 , 0 , 0 ,254, 0 ,254, 0 , 0 , 0 , 0 , 0 ,254, 0 , 0 , 0 ,254, 0 , 0 , 0 ,254, 0 ,254, 0 ,254,254, 0 , 0 , 0 ,254, 0 ,254,254,254,254, 0 ,254},
    {254,254,254, 0 ,254,254, 0 ,254, 0 ,254,254,254,254, 0 ,254,254,254,254,254,254, 0 ,254, 0 ,254,254,254, 0 ,254,254,254, 0 ,254, 0 , 0 , 0 , 0 , 0 , 0 , 0 ,254},
    {254, 0 ,254, 0 ,254,254, 0 , 0 , 0 , 0 , 0 ,254,254, 0 , 0 , 0 , 0 , 0 , 0 ,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254,254,254, 0 ,254,254,254},
    {254, 0 ,254, 0 , 0 , 0 ,254,254, 0 ,254, 0 , 0 ,254,254,254,254,254,254,254,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254, 0 , 0 , 0 ,254, 0 , 0 , 0 ,254, 0 ,254, 0 ,254},
    {254, 0 ,254, 0 ,254, 0 ,254,254,254,254,254, 0 , 0 , 0 , 0 , 0 ,254, 0 ,254, 0 , 0 ,254, 0 , 0 , 0 ,254, 0 ,254, 0 ,254,254,254, 0 ,254,254,254, 0 ,254, 0 ,254},
    {254, 0 ,254, 0 ,254, 0 , 0 , 0 , 0 ,254,254, 0 ,254,254,254, 0 ,254, 0 ,254,254,254,254, 0 ,254, 0 ,254, 0 ,254, 0 , 0 , 0 ,254, 0 ,254, 0 ,254, 0 , 0 , 0 ,254},
    {254, 0 ,254,254,254, 0 ,254,254, 0 ,254,254, 0 , 0 , 0 ,254, 0 ,254, 0 , 0 , 0 , 0 ,254, 0 ,254, 0 ,254, 0 ,254,254,254,254,254, 0 ,254, 0 ,254,254, 0 ,254,254},
    {254, 0 , 0 , 0 , 0 , 0 , 0 ,254, 0 ,254,254,254,254,254,254, 0 ,254, 0 ,254,254, 0 ,254, 0 ,254, 0 ,254, 0 , 0 , 0 ,254, 0 ,254, 0 ,254, 0 ,254,254, 0 , 0 ,254},
    {254, 0 ,254,254,254,254,254,254,254,254, 0 , 0 , 0 , 0 ,254, 0 ,254, 0 ,254, 0 , 0 ,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254,254,254,254,254},
    {254, 0 ,254,254,254,254,254,254,254,254,254,254,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254,254, 0 ,254,254,254, 0 ,254, 0 ,254, 0 ,254, 0 , 0 , 0 , 0 , 0 , 0 , 0 ,254},
    {254, 0 , 0 , 0 , 0 , 0 , 0 ,254, 0 ,254, 0 , 0 ,254, 0 , 0 , 0 ,254, 0 ,254,254, 0 ,254, 0 , 0 , 0 , 0 , 0 ,254, 0 , 0 , 0 ,254,254,254,254,254, 0 ,254, 0 ,254},
    {254,254,254, 0 ,254,254, 0 ,254, 0 ,254,254, 0 ,254,254,254,254, 0 , 0 , 0 ,254, 0 ,254,254,254,254,254,254,254, 0 ,254, 0 , 0 , 0 , 0 ,254,254, 0 ,254, 0 ,254},
    {254, 0 ,254, 0 ,254,254, 0 , 0 , 0 ,254, 0 , 0 ,254, 0 , 0 , 0 , 0 ,254, 0 ,254, 0 ,254, 0 , 0 , 0 ,254, 0 , 0 , 0 ,254,254,254,254,254,254,254, 0 ,254, 0 ,254},
    {254, 0 ,254, 0 , 0 , 0 ,254,254, 0 ,254, 0 ,254,254, 0 ,254,254,254,254, 0 ,254, 0 ,254, 0 ,254,254,254, 0 ,254,254, 0 , 0 , 0 , 0 , 0 , 0 ,254, 0 ,254, 0 ,254},
    {254, 0 ,254, 0 ,254, 0 ,254,254,254,254, 0 ,254,254, 0 ,254, 0 , 0 , 0 , 0 ,254, 0 , 0 , 0 ,254, 0 ,254, 0 , 0 , 0 , 0 ,254,254, 0 ,254,254,254, 0 ,254,254,254},
    {254, 0 ,254, 0 ,254, 0 , 0 , 0 , 0 ,254, 0 ,254,254, 0 ,254,254,254,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254,254,254, 0 ,254, 0 , 0 , 0 , 0 , 0 ,254, 0 , 0 , 0 ,254},
    {254, 0 ,254,254,254, 0 ,254,254, 0 ,254, 0 ,254, 0 , 0 , 0 , 0 , 0 , 0 ,254,254, 0 ,254, 0 ,254, 0 ,254, 0 , 0 , 0 ,254, 0 ,254, 0 ,254, 0 ,254,254,254, 0 ,254},
    {254, 0 , 0 , 0 , 0 , 0 , 0 ,254, 0 , 0 , 0 ,254,254,254,254,254,254, 0 , 0 , 0 , 0 ,254, 0 , 0 , 0 ,254, 0 ,254,254,254, 0 ,254,254,254, 0 , 0 , 0 ,254, 0 ,254},
    {254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254},
};
*/


enum directions
{
    UP,
    DOWN,
    RIGHT,
    LEFT
};

int positions[3][2];


//Position struct to hold entity's position.
struct Position
{
    int x = 1;
    int y = 1;

} pos, prevPos, beforeDecision;



int decision;

bool loop = false;

int breakPoints[50][2];


void printMaze()
{
    int holder = maze[pos.y][pos.x];
    maze[pos.y][pos.x] = 'o';

    system("cls");
    for (int i=0; i<SIZE; i++)
    {
        for (int j=0; j<SIZE; j++)
        {
            printf(" %c", maze[i][j]);
        }
        printf("\n");
    }

    //For debugging:
    printf("\ndecisions:%d   pos:(%d,%d)   prevPos:(%d,%d)   beforeDecision:(%d,%d)   last breakpoint:(%d,%d)\n", decision, pos.x, pos.y, prevPos.x, prevPos.y, beforeDecision.x, beforeDecision.y, breakPoints[decision][0], breakPoints[decision][1]);

    Sleep(FRAME_DELAY);
    maze[pos.y][pos.x] = holder;
}


void printBlankMaze()
{
    int holder = blankMaze[pos.y][pos.x];
    blankMaze[pos.y][pos.x] = 'o';

    system("cls");
    for (int i=0; i<SIZE; i++)
    {
        for (int j=0; j<SIZE; j++)
        {
            printf(" %c", blankMaze[i][j]);
        }
        printf("\n");
    }

    Sleep(FRAME_DELAY);
    blankMaze[pos.y][pos.x] = holder;
}



//Checks every direction and returns direction to square which has smallest value on it (if more than one, randomly returns one).
int check()
{
    int x = pos.x;
    int y = pos.y;

    int up = (int)maze[y-1][x];
    int down = (int)maze[y+1][x];
    int right = (int)maze[y][x+1];
    int left = (int)maze[y][x-1];

    srand ( time(NULL) );

    while ( 1 )
    {
        switch ( rand()%4 )
        {
            case UP:
                if ( up<=down && up<=right && up<=left )
                {
                    return UP;
                }
            break;

            case DOWN:
                if ( left<=up && left<=down && left<=right )
                {
                    return LEFT;
                }
            break;

            case RIGHT:
                if ( right<=up && right<=down && right<=left )
                {
                    return RIGHT;
                }
            break;

            case LEFT:
                if ( down<=up && down<=right && down<=left )
                {
                    return DOWN;
                }
            break;
        }
    }
}


//Returns how many possible paths there are.
int numberOfChoices()
{
    int x = pos.x;
    int y = pos.y;

    int choices = 0;

    if ( maze[y-1][x] != 254 && maze[y-1][x] != BLOCK )  //UP
    {
        choices++;
    }
    if ( maze[y+1][x] != 254 && maze[y+1][x] != BLOCK )  //DOWN
    {
        choices++;
    }
    if ( maze[y][x+1] != 254 && maze[y][x+1] != BLOCK )  //RIGHT
    {
        choices++;
    }
    if ( maze[y][x-1] != 254 && maze[y][x-1] != BLOCK )  //LEFT
    {
        choices++;
    }

    return choices;
}


//Checks whether a specific path is available.
bool checkHere ( int where )
{
    int x = pos.x;
    int y = pos.y;

    switch ( where )
    {
        case UP:
            if ( maze[y-1][x] != 254 && maze[y-1][x] != BLOCK ) { return true; }
            else { return false; }
            break;

        case DOWN:
            if ( maze[y+1][x] != 254 && maze[y+1][x] != BLOCK ) { return true; }
            else { return false; }
            break;

        case RIGHT:
            if ( maze[y][x+1] != 254 && maze[y][x+1] != BLOCK ) { return true; }
            else { return false; }
            break;
        case LEFT:
            if ( maze[y][x-1] != 254 && maze[y][x-1] != BLOCK ) { return true; }
            else { return false; }
            break;

        default:
            printf("\nIn function: checkHere(int where) FATAL ERROR!");
            exit(-1);
            break;
    }
}



//Moves the entity to a direction (not position).
void moveto( int where )
{
    prevPos = pos;

    (int)maze[pos.y][pos.x]++;

    switch ( where )
    {
        case UP:
            pos.y--;
            break;

        case DOWN:
            pos.y++;
            break;

        case RIGHT:
            pos.x++;
            break;

        case LEFT:
            pos.x--;
            break;

        default:
            printf("\nIn function: moveto(int where)  FATAL ERROR!");
            exit(-1);
    }
    if ( pos.x == FINISH_X && pos.y == FINISH_Y )
    {
        maze[pos.y][pos.x] = '1';
        done = true;
    }
}

//Modified version of 'moveto' function, does not increment value of passed square.
void follow( int where )
{
    switch ( where )
    {
        case UP:
            pos.y--;
            break;

        case DOWN:
            pos.y++;
            break;

        case RIGHT:
            pos.x++;
            break;

        case LEFT:
            pos.x--;
            break;

        default:
            printf("\nIn function: follow(int where)  FATAL ERROR!");
            exit(-1);
    }
    if ( pos.x == FINISH_X && pos.y == FINISH_Y )
    {
        blankMaze[pos.y][pos.x] = '1';
        done = true;
    }
}



//Returns the direction to a square which has non-zero value. (Has built-in mechanism to prevent returning back to where it came.)
int followTrace( int currentDirection )
{
    int x = pos.x;
    int y = pos.y;

    //If <DIRECTION> doesn't point to walls of maze, value of square that it points is assigned to <direction> variable. Else, 48 will be assigned ( ASCII code for 0 ).

    int up = (int)maze[y-1][x] != 254 ? (int)maze[y-1][x] :48;

    int down = (int)maze[y+1][x] != 254 ? (int)maze[y+1][x] :48;

    int right = (int)maze[y][x+1] != 254 ? (int)maze[y][x+1] :48;

    int left = (int)maze[y][x-1] != 254 ? (int)maze[y][x-1] :48;

    bool allChecked = false;


    while ( 1 )
    {
        //If <direction> is available and won't cause entity to return where it was one step ago, return <DIRECTION>

        if ( ( up!=48 && up!=BLOCK ) && ( currentDirection!=DOWN || allChecked ) )
        {
            return UP;
        }
        if ( ( down!=48 && down!=BLOCK ) && ( currentDirection!=UP || allChecked ) )
        {
            return DOWN;
        }
        if ( ( right!=48 && right!=BLOCK ) && ( currentDirection!=LEFT || allChecked ) )
        {
            return RIGHT;
        }
        if ( ( left!=48 && left!=BLOCK ) && ( currentDirection!=RIGHT || allChecked ) )
        {
            return LEFT;
        }

        allChecked = true; //If program run through all possible ways yet function hasn't been terminated,
                           //that means entity has no other chance than returning back where it was one step ago.
                           //This logic variable allows it to do that if there is no other option.
                           //(That actually would mean that algorithm is broken, but still can be useful to have this ability to spot errors.)
    }
}

//Inverses the passed direction.
int inverse( int inputDirection )
{
    int returnDirection;
    switch ( inputDirection )
    {
    case UP:
        returnDirection = DOWN;
        break;
    case DOWN:
        returnDirection = UP;
        break;
    case RIGHT:
        returnDirection = LEFT;
        break;
    case LEFT:
        returnDirection = RIGHT;
        break;
    }
    return returnDirection;
}




//Returns what will the entity encounter if it moves the given direction.
int whatsThere( int where )
{
    struct Position temp;

    temp = pos;

    switch ( where )
    {
        case UP:
            temp.y--;
            break;

        case DOWN:
            temp.y++;
            break;

        case RIGHT:
            temp.x++;
            break;

        case LEFT:
            temp.x--;
            break;

        default:
            printf("\nIn function: moveto(int where)  FATAL ERROR!");
            exit(-1);
    }

    return (int)maze[temp.y][temp.x];
}


struct Position findCoord ( int where )
{
    struct Position temp;
    temp = pos;

    switch ( where )
    {
        case UP:
            temp.y--;
            break;

        case DOWN:
            temp.y++;
            break;

        case RIGHT:
            temp.x++;
            break;

        case LEFT:
            temp.x--;
            break;

        default:
            printf("\nIn function: moveto(int where)  FATAL ERROR!");
            exit(-1);
    }

    return temp;
}









int main()
{
    /// STEP #1 : Solving the maze. ///

    //Setting the starting point.
    pos.x = INIT_X;
    pos.y = INIT_Y;

    beforeDecision.x = 0;
    beforeDecision.y = 0;

    int direction;
    decision = 0;

    breakPoints[0][0] = pos.x;
    breakPoints[0][1] = pos.y;

    direction = check();

    printMaze();
    system("pause");


    while ( !done )
    {

        while (  numberOfChoices() <= 2  && !done )
        {
            direction = check();
            moveto ( direction );
            printMaze();
        }


        if ( numberOfChoices() > 2 )
        {
            decision++;

            breakPoints[decision][0] = pos.x;
            breakPoints[decision][1] = pos.y;

            beforeDecision = prevPos;

            direction = check();

            //moveto(direction);
        }

        while ( decision > 0 && !done )
        {
            //If entity finds itself in a position where it has to go a path where it had already gone,
            //And if it came there while NOT filling the path behind:

            if ( whatsThere(direction) > 48 && whatsThere(direction)!=254 && whatsThere(direction)!=BLOCK )
            {
                direction = inverse(direction);

                while ( !(pos.x == breakPoints[decision][0] && pos.y == breakPoints[decision][1]) && numberOfChoices()<=2 )
                {
                    maze[pos.y][pos.x] = BLOCK-1;

                    printf("\nIn a loop!");
                    system("pause");

                    moveto(direction);

                    direction = check();

                    printMaze();
                }

            }

            if ( !checkHere(direction) )
            {

                if ( numberOfChoices() == 1 )
                {
                    while ( !(pos.x == breakPoints[decision][0] && pos.y == breakPoints[decision][1]) && numberOfChoices() <= 1 )
                    {

                        printf("\nIn a dead end!");
                        system("pause");

                        maze[pos.y][pos.x] = BLOCK -1;

                        direction = check();
                        moveto ( direction );

                        printMaze();
                    }

                    if ( pos.x == breakPoints[decision][0] && pos.y == breakPoints[decision][1] )
                    {
                        decision--;
                    }
                    direction = check();
                }
                else
                {
                    direction = check();
                }
            }

            else
            {
                moveto(direction);
                printMaze();

                /*if ( pos.x == breakPoints[decision][0] && pos.y == breakPoints[decision][1] )
                {
                    printf("\nReturned last breakpoint");
                    system("pause");

                    if ( !(beforeDecision.x == pos.x && beforeDecision.y == pos.y) )
                    {
                        printf("\nLoop detected. I dunno what to do :( \n");
                        system("pause");

                        maze[prevPos.y][prevPos.x] = BLOCK-1;
                    }
                }*/

                if ( numberOfChoices() > 2 )
                {
                    decision++;

                    breakPoints[decision][0] = pos.x;
                    breakPoints[decision][1] = pos.y;

                    beforeDecision = prevPos;

                    direction = check();
                }
            }
        }
    }



    printf("\nMapping is finished.");
    system("pause");



    /// STEP #2 : Starting at the beginning again and following the correct path. ///

    done = false;

    //Reset the position of entity.
    pos.x = INIT_X;
    pos.y = INIT_Y;

    printBlankMaze();
    system("pause");

    //Until it reaches the end, follows the previously constructed path in the mapping phase.
    while ( !done )
    {
        direction = followTrace( direction );
        follow ( direction );
        printBlankMaze();

        if ( pos.x == FINISH_X && pos.y == FINISH_Y ) { done = true; }
    }

    printf("\nMAZE COMPLETED!");






    return 0;
}



















