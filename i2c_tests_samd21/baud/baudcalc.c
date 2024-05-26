



#include <stdio.h>
#include <inttypes.h>






int main ( void )
{

    uint32_t fgclk =  48000000;
    uint32_t fscl = 100000;




    float f_temp, f_baud;
    f_temp = ((float)fgclk/(float)fscl) - (((float)fgclk/(float)1000000)*0.3);
    f_baud = (f_temp/2)-5;
    
    
    printf( "Baud: %d\n", (uint32_t)f_baud );





    return 0;
}


















































