#include <stdio.h>

int main()
{
    long int result, pNum;
    int i, j, d1, d2, d3, d4, d5, d6;

    for ( i = 100; i <= 999; i++ )
    {
        for ( j = i; j<=999; j++ )
        {
            result = i*j;

            d1 = (result%10);
            d2 = (result%100)/10;
            d3 = (result%1000)/100;
            d4 = (result%10000)/1000;
            d5 = (result%100000)/10000;
            d6 = (result%1000000)/100000;

            if ( result < 100000 && d1==d5 && d2==d4 && result>pNum )
            {
                pNum = result;
            }
            if ( result > 100000 && d1==d6 && d2==d5 && d3==d4 && result>pNum )
            {
                pNum = result;
            }
        }
    }

    printf("%lu", pNum);




    return 0;
}
