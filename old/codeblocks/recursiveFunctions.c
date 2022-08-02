#include <stdio.h>
#include <math.h>



double pi ( double rec )
{
    static int n = 0;

    if ( n <= 20000 )
    {
        printf("%f\n", rec);
        return  ( rec + pi( pow(-1,1+n++)*(4.0 / (2.0*n + 1)) ) );
    }
    else
    {
        return rec;
    }
}



int fac ( int input )
{
    if ( input <= 1 ) { return 1; }

    return input*fac(input-1);
}



int fib ( int input )
{
    if ( input == 0 || input == 1 ) { return 1; }

    return ( fib(input-1)+fib(input-2) );
}




int main()
{
    printf("%d", fib(7));






    return 0;
}














