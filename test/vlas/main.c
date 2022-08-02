#include<stdio.h>
#include<string.h>

int main(void)
{
    int size;

    scanf( "%d", &size );

    char array[size];

    for( int i = 0; i < size; i++ )
    {
        array[i] = i+1;
    }

    array[size] = '\0';

    printf( "%d\n", strlen(array) );




    return 0;
}