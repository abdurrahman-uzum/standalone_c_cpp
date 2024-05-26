#include<stdio.h>
#include"test.h"

int main( void )
{
    printf( "Testing main entry point, file: %s\n", __FILE__ );

    first_test_function();
    second_test_function();



    return 0;
}