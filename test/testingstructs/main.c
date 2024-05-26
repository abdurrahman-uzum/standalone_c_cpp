#include <stdio.h>

typedef struct 
{
    int a;
    int b;
} tdstruct;

int main ( void )
{
    tdstruct stc1;
    tdstruct stc2;

    stc2 = stc1;

    printf( "%p, %p\n", &stc1, &stc2 );

    




    return 0;
}