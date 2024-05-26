#include<stdio.h>


struct data
{
    char a;
    int b;
    char c;
};


int main( void )
{
    struct data data1;

    printf( "char:%llu, int:%llu, total:%llu\n", sizeof data1.a, sizeof data1.b, sizeof data1 );





    return 0;
}