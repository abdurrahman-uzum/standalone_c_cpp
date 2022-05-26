#include <stdio.h>
#include <string.h>

#define SIZE 1000000

static char data[SIZE];

int main( void )
{
    // for ( int i = 0; i < SIZE; i++ )
    // {
    //     data[i] = 1;
    // }

    memset( data, '1', sizeof data );

    //printf( "%lu\n", sizeof data );

    for ( int i = 0; i < 10; i++ )
    {
        printf( "%d\n", data[i] );
    }



    return 0;
}