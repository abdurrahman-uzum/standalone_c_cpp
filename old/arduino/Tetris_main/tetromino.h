#ifndef _TETROMINO_H
#define _TETROMINO_H

#include "globals.h"

class Tetromino
{
    public:
        static int const C_LENGTH = 4;
        static int const INIT_POS_X = ( 48 / 2 ) + C_LENGTH;
        static int const INIT_POS_Y = 0;

        int score;

    public:
        Tetromino( Type type );

        void rotate( Rotation dir );
        void render();
        void update();
        void applyEvent();
        
        bool handleCollision();

        bool bCollision( Square );
        bool lCollision( Square );
        bool rCollision( Square );

        void fix();

        void recreate( Type type );

    private:
        Type type;
        Point center;

        Point nextPos;
        Square cells[4];

        bool bottomCollision;
        bool leftCollision;
        bool rightCollision;

        double gamespeed;

};


#endif
