#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Prints the given string in the desired format, prints only asterix' if row is NULL
void print_row( const char* row, const int width )
{
    if ( row == NULL )
    {
        for ( int i = 0; i < width; i++ )
        {
            printf( "*" );
        }
        printf( "\n" );
    }
    else
    {
        int length = strlen( row );                         // Row length
        int spaces = ceil( ( width - 2 - length ) / 2.0);   // # of spaces to be added at each side, -2 for boundary asterix'

        printf( "*" );
        for( int i = 0; i < spaces; i++ ) 
        {
            printf( " " );
        }
        printf( "%s", row );
        for( int i = 0; i < spaces-1; i++ )
        {
            printf( " " );
        }
        printf( "*\n" );        
    }
}

void framed(const char *text, int width ) 
{
    // IMPORTANT! Following buffer allocations assume that "text" is null-terminated.
    int row_size = width - 4; // Maximum allowed writable length, -2 for at least one space, another -2 for boundaries.

    char* word   = NULL;                                            // To hold a single word
    char* row    = calloc( (row_size+1), sizeof(*row) );       // To hold a single row
    char* string = calloc( (strlen(text)+1), sizeof(*string) );    // To copy the passed text so that strtok can work with it
    strcpy( string, text );

    int char_count = 0;

    // Drawing the upper bound
    print_row( NULL, width );

    // Start parsing the input string into words, assumes words are seperated with spaces.
    word = strtok( string, " " );
    while( word != NULL )
    {
        // If the word is larger than the remaining box width
        if ( strlen( word ) > row_size - strlen(row) + 1 )
        {
            int hyphen_at = strlen( word ) - row_size - sizeof(row) - 1;
            char_count += hyphen_at;

            strncat( row, word, hyphen_at );
            strcat( row, "-" );

            word += hyphen_at; // Move the pointer to after the hyphen.
        }
        else
        {
            // Update the current character count
            char_count += strlen(word);

            // If adding the next word won't exceed the limits:        
            if ( char_count < row_size )
            {   
                strcat( row, word ); // Append the current word.

                // Add spaces between words, turns out strcat has problems with trailing spaces.
                int length = strlen( row );
                row[length] = ' ';
                row[length+1] = '\0';
                char_count++;    

                word = strtok( NULL, " " ); // Parse the next word.
            }
        }

        

        // If the limit is reached, or the last word was added to the buffer:
        if ( char_count >= row_size || word == NULL )
        {
            // Print and go newline
            print_row( row, width );

            char_count = 0;                               // Reset the character count
            memset( row, 0, (row_size+1)*sizeof(*row) );  // Clear the row buffer.
        }
    }

    // Drawing the lower bound
    print_row( NULL, width );

    free( string );
    free( row );
}



int main( int argc, char** argv )
{
    const char text[] = "This is word with four characters";

    framed( text, 12 );

    return 0;
}