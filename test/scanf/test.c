#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main ()
{
    char string[100] = { 0 };

    //for(;;)
    {
        printf( "Enter:\n" );

        scanf( "%99[^',']", string );

        printf( "Read: <%s>\n\n", string );

        scanf( "%99[^\n]", string );

        printf( "Remaining: <%s>\n\n", string );

    }




    return 0;
}