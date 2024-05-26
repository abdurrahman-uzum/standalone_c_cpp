#include<stdio.h>

int main ( void )
{
    unsigned int a = 256;

    char *p = &a;

    printf( "[%d][%d][%d][%d]\n", *(p+3), *(p+2), *(p+1), *(p) );


    return 0;
}