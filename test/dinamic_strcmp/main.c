#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main ( void )
{
    char request[64] = { 0 };

    char compare[] = "tare";

    strcpy( request, "tare my ass" );

    int result = strcmp( request, compare );

    if ( result == 0 || result < 0 )
    {
        printf( "No target provided" );
    }
    else if ( result > 0 )
    {
        char copy_request[64];
        strcpy( copy_request, request );

        char *token = strtok( copy_request, " " );
        token = strtok( NULL, " " );

        if ( token == NULL )
        {
            printf( "Could not parse target index (err 1)\n");
            return -1;
        }

        printf( "orig: %s, token: %s|\n", copy_request, token );

        if ( !strcmp( token, "all" ) )
        {
            printf( "Tare all\n" );
        }
        else
        {
            char *end ;
            int index = strtol( token, &end, 10 );

          
            if ( token == end )
            {
                printf( "Could not parse target index (err 2)\n");
                return -1;
            }
            else if ( index <= 0 )
            {
                printf( "Invalid index of %d\n", index );
                return -1;
            }
            else
            {
                printf( "Tare on adc %d\n", index );
            }
        }
    }

    return 0;
}