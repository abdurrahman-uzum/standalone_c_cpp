#include <stdio.h>


int main()
{
    int age[10] = { 24,15,54,35,13,40,38,21,18,32 };

    int sum = 0;
    double average;

    for ( int i=0; i<10; i++ )
    {
        sum += age[i];
    }

    average = sum/10.0;

    printf("Average is: %f", average);



    return 0;
}
