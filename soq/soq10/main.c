#include<stdio.h>



int main(void)
{
    char string[] = "12345";

    char somearray[10] = { 0 };

    int size = sizeof string;

    printf( "%d %d\n", sizeof string, sizeof somearray );






    return 0;
}