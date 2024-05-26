#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int hammingise( char* target, char* source )
{
    if ( target == NULL || source == NULL ) { return -1; }

    int k = 0;
   
    for( int i=0; i < 16; i++ )
    {
        if ( i!=0 && i!=1 && i!=4 && i!=8 )
        {
            target[i] = source[k++];
        }
    }

    return k;
}



int main( int argc, char** argv )
{

    char message[12] = { 0 };
    char sent[17] = { 0 };
    char rcvd[17] = { 0 };
    strcpy( message, "11111111111" );

    int ret = hammingise( sent, message );

    printf( "Modified: |%s| with k=%d", sent, ret );
    

    // srand(time(NULL));

    // for ( int i = 0; i < 16; i++ )
    // {
    //     if ( rand()%2 )
    //     {
    //         rcvd[i] ^= 1;
    //         printf("%dth bir is flipped.\n", i);
    //         break;
    //     }

    //     printf("sent passed with no errors.\n");        
    // }

    // printf( "\nOriginal: %s\n", sent );
    // printf( "Received: %s", rcvd );









    return 0;
}