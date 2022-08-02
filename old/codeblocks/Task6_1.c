/*
    Abdurrahman ÜZÜM
    Date: 13.10.2019
    Code Description: This code calculates pi.

*/


#include <stdio.h>

int main()
{
    double pi;
    int terms = 0;

    int i;
    for ( i=1; terms<20000; i+=2, terms++)
    {
        pi += terms%2==0? 4.0/i : -4.0/i;

        printf("For %d terms: pi=%f\n", terms+1, pi);
    }
    getchar();


    return 0;
}


