#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printarray ( unsigned char** cells, int size )
{
    for ( int j = 0; j < size; j++ )
    {
        for ( int i = 0; i < size; i++ )
        {
            printf( " %2d", cells[i][j] );
        }

        printf( "\n" );
    }
}

void init_offset_array ( unsigned char** cells, int size )
{
    for ( int j = 1; j < size+1; j++ )
    {
        for ( int i = 1; i < size+1; i++ )
        {
            cells[i][j] = 10*(i-1) + (j-1);
        }
    }
}

void print_cols( unsigned char* p, unsigned char* c, unsigned char* n, int size )
{
    printf( "\nPR CU NE\n" );
    for ( int j = 0; j < size; j++ )
    {
        printf( "%2d %2d %2d\n", p[j], c[j], n[j] );
    }
}

void iterate_columns ( unsigned char** cells, int size )
{
    unsigned char* prev_col = nullptr;
    unsigned char* curr_col = nullptr;
    unsigned char* next_col = nullptr;

    prev_col = (unsigned char*)malloc( sizeof(cells[0]) );
    curr_col = (unsigned char*)malloc( sizeof(cells[0]) );
    next_col = (unsigned char*)malloc( sizeof(cells[0]) );

    memcpy( prev_col, cells[0], size+2 );
    memcpy( curr_col, cells[1], size+2 );
    memcpy( next_col, cells[2], size+2 );

    for ( int i = 1; i < size+1; i++ )
    {
        print_cols( prev_col, curr_col, next_col, size+2 );
        
        for ( int j = 1; j < size+1; j++ )
        {
            cells[i][j] = 3;
        }

        if ( i+2 < size+2 )
        {
            memcpy( prev_col, curr_col, size+2 );
            memcpy( curr_col, next_col, size+2 );
            memcpy( next_col, cells[i+2], size+2 );
        }
    }
}

int allocate_cells( unsigned char*** cells, int size )
{
    if ( cells == NULL )
    {
        printf( "Passed null pointer.\n" );
        return -1;        
    }

    *cells = (unsigned char**)malloc( (size+2)*sizeof(**cells) );
    if ( *cells == NULL )
    {
        printf( "Memory allocation failed.\n" );
        return -1;    
    }

    for ( int i = 0; i < size; i++ )
    {
        (*cells)[i] = (unsigned char*)malloc( (size+2)*sizeof((*cells)[0]) );
        if ( (*cells)[i] == NULL )
        {
            printf( "Column memory allocation failed.\n" );
            return -1;
        }
    }

    return 0;
}




int main ( int argc, char** argv )
{

    const int size = 10;

    unsigned char** cells = NULL;

    // cells = (unsigned char**)malloc( (size+2)*sizeof(*cells) );
    // for ( int i = 0; i < size+2; i++ )
    // {
    //     cells[i] = (unsigned char*)malloc( (size+2)*sizeof(cells[0]) );
    // }

    if ( allocate_cells( &cells, size ) != 0 )
    {
        printf( "Function: allocate_cells failed.\n" );
        return -1;
    }

    if ( cells == NULL )
    {
        printf("CELLS ARE NULL EEEHHHHYYHHY !!!!!'11!!1\n" );
        return -1;
    }

    for ( int i = 0; i < size+2; i++ )
    {
        for ( int j=0; j < size+2; j++ )
        {
            cells[i][j] = 0;
        }
    }

    printf( "Going in init_offset_array\n" );
    init_offset_array( cells, size );
    printf( "Left init_offset_array\n" );
    
    printf( "Going in print_array\n" );
    printarray( cells, (size+2) );
    printf( "Left printarray\n" );

    printf( "Going in iterate_columns\n" );
    iterate_columns( cells, size );
    printf( "Left iterate_columns\n" );

    printarray( cells, (size+2) );


    

    






    return 0;
}