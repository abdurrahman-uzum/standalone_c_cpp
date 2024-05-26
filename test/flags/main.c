#include <stdio.h>
#include <stdint.h>

int main ( void )
{
    unsigned int flags = 0;

    flags |= 0x000F;
    printf( "0x000F : %d\n", flags & 0xFFFF );

    flags |= 0x00F0;
    printf( "0x00F0 : %d\n", flags & 0xFFFF );
    
    flags |= 0x0F00;
    printf( "0x0F00 : %d\n", flags & 0xFFFF );
    
    flags |= 0xF000;
    printf( "0xF000 : %d\n", flags & 0xFFFF );
    
}