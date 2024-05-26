#include <stdio.h>
#include <conio.h>

#define size_h 128
#define size_v 32

#define clear() printf("\e[1;1H\e[2J")



void create_world ( int world[][size_v] )
{
    // fill with spaces
    for ( int i = 0; i < size_h; i++ )
    {
        for ( int j = 0; j < size_v; j++ )
        {
            world[i][j] = ' ';
        }
    }


    // floor:
    for( int i = 0; i < size_h; i ++ )
    {
        world[ i ][ size_v -1 ] = 254;
    }

    // ceiling:
    for( int i = 0; i < size_h; i ++ )
    {
        world[ i ][ 0 ] = 254;
    }

    // left wall:
    for( int j = 0; j < size_v; j++ )
    {
        world[ 0 ][ j ]= 254;
    }

    // right wall:
    for( int j = 0; j < size_v; j++ )
    {
        world[ size_h - 1 ][ j ] = 254;
    }

    
}

void draw ( int world[][size_v] )
{
    for ( int j = 0; j < size_v; j++ )
    {
        for ( int i = 0; i < size_h; i++ )
        {
            putchar( world[i][j] );
        }
        putchar( '\n' );
    }
}


int main ( void )
{
    clear();
    
    for( int i = 0; i < 10; i++ )
    {
        printf( "\n" );
    }

    int world [size_h][size_v] = { 0 };

    create_world( world );

    draw( world );

    // game loop
    for ( ;; )
    {
        draw( world );
        clear();
    }



    return 0;
}