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




int main()
{
    printf("%f", pi(4));










    return 0;
}





























































