#include<stdio.h>

int main ( void )
{
    float var = 0;

    for ( ;; )
    {
        printf( "Value: " );
        scanf( "%f", &var );

        var =  var < 5000  ? 0 : var;

        printf( "Value: %f\n", var );

    }
  



    return 0;
}