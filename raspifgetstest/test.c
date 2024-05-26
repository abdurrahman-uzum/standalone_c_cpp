#include <stdio.h>
#include <string.h>



int main ( int argc, char **argv )
{
    char command[ 64 ] = { 0 };

    if ( fgets( command, sizeof command, stdin ) != 0 )
    {
        fprintf( stderr, "Failed\n" );
    }
    else
    {
        printf( "Got: %s\n", command );
    }



    return 0;
}