#include<stdio.h>
#include<stdlib.h>
#include<string.h>



int main(int argc, char *argv[])
{
    char filename[255];
    char* word;

    if ( argv[1] != NULL )
    {
        char* temp = malloc( strlen(argv[1]) + 1 );
        strcpy( temp, argv[1] );

        printf( ">>%s\n", temp );

        word = strtok( temp, "/" );

        while ( word != NULL )
        {
            printf( "%s\n", word );

            word = strtok( NULL, "/" );
        }
    }

    
    




    return 0;
}