#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int L = 10;

void modify( char arr[L][L], int size_x, int size_y )
{
    for ( int i = 0; i < L; i++ )
    {
        for ( int j = 0; j < L; j++ )
        {
            arr[i][j] = -1*(L*j + i);
        }        
    }     
}

int main( int argc, char** argv )
{
    char array[L][L] = { 0 };

    for ( int i = 0; i < L; i++ )
    {
        for ( int j = 0; j < L; j++ )
        {
            array[i][j] = L*j + i;
        }        
    } 

    printf( "Original:\n" );
    for ( int i = 0; i < L; i++ )
    {
        for ( int j = 0; j < L; j++ )
        {
            printf( "%3d ", array[i][j] );
        }        
        printf( "\n" );
    } 

    modify( array, L, L );

    printf("\n\n");
    printf( "Modified:\n" );
    for ( int i = 0; i < L; i++ )
    {
        for ( int j = 0; j < L; j++ )
        {
            printf( "%3d ", array[i][j] );
        }        
        printf( "\n" );
    } 






    return 0;    
}