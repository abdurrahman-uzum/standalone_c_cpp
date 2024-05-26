#include <stdio.h>
#include <string.h>



void print_binary( unsigned int input )
{
    unsigned int mask = 0x80000000;
    for( int i=31; i >= 0; i-- )
    {
        printf( "%d", (input & mask)>>i );
        mask = mask >> 1;

        if ( ( i ) % 4 == 0 )
        {
            printf( " " );
        }
    }
}



int main ( void )
{
    unsigned int    ui  = -1;
    double          d   = 0;

    print_binary( ui );
    











    






    return 0;
}