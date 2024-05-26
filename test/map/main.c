#include<stdio.h>



int map ( int val, int source_lower, int source_upper, int target_lower, int target_upper )
{
    return (val - source_lower) * (target_upper - target_lower) / (source_upper - source_lower) + target_lower;
}




int main ( void )
{

    int val = 1024;

    printf( "Original:%d, mapped:%d\n", val, map(val, 0, 1024, 512, 1024 ) );







    return 0;
}