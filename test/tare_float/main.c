#include<stdio.h>
#include<stdint.h>

int main ( void )
{
    uint32_t tare = 75212;
    float* tare_f = &tare; 

    printf( "%f\n", *tare_f );




    return 0;
}


// 75212 29540 60922 124289 66959 46620 132968
