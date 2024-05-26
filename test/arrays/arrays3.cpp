#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int SIZE = 10;

int update( unsigned char** cells )
{
    if ( cells == NULL ) { return -1; }

    // Works only as static.
    unsigned char* buffer = (unsigned char*)malloc( SIZE * sizeof(**cells) );
    if ( buffer == NULL ) { return -1; }

    for ( int i = 0; i < SIZE; i++ )
    {
        memcpy( buffer, cells[i], SIZE*sizeof(**cells) );

        //do stuff
    }

    return 0;
}

int main ( int argc, char** argv )
{
    unsigned char** cells = NULL;

    cells = (unsigned char**)malloc( SIZE*sizeof(*cells) );
	if ( cells == NULL )
	{
		return -1;
	}
	for ( int i = 0; i < SIZE; i++ )
	{
		cells[i] = (unsigned char*)malloc( SIZE*sizeof(**cells) );
		if ( cells[i] == NULL )
		{
			return -1;
		}
	}


    for ( int i = 0; i < SIZE; i++ )
    {
        for ( int j = 0; j < SIZE; j++ )
        {
            cells[i][j] = SIZE*i + j;
        }        
    }

    for ( int i = 0; i < SIZE; i++ )
    {
        for ( int j = 0; j < SIZE; j++ )
        {
            printf( "%2d ", cells[i][j] );
        }        
        printf( "\n" );
    } 


    for( int i=0; i<10; i++ )
    {
        int returned = 0;
         update( cells );

        // do stuff

        printf( "Function returned : %d\n", returned );
    }

    

    return 0;
}