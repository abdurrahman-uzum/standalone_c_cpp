#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

void flip ( int*, int, int )
{









}

int main()
{
    int arr[SIZE] = { 2, 6, 3, 1, 7, 9, 0, 5 }
    int* array;

    array = (int*)malloc(SIZE*sizeof(int));

    array = arr;

    int middle = SIZE/2;

    if ( SIZE%2 == 0 )
    {
        flip ( array, SIZE, 0 );
    }
    else
    {
        flip ( array, SIZE, 1 );
    }












    return 0;
}
