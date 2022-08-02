/*
 * Working principle of reverseBits function:
 *
 * Loop through the bits array whose size is number of bits in an unsigned integer.
 * 		+ sizeof(unsigned) returns the number of bytes that can be stored in an unsigned int.
 * 		+ One byte consists of 8 bits, therefore sizeof(unsigned)*8 gives the number of bits stored in an unsigned int.
 *
 * Assign rightmost bit of the number to the array's corresponding element
 * 		+ Number 1's rightmost bit is 1 and all the remaining bits are 0.
 * 		+ Therefore the statement < 1 & number > returns rightmost bit of the number, since all the other bits of number will encounter < 0 & (nth bit) > statement and imitate 0.
 *
 * Right shift the number by one bit.
 * 		+ Since the rightmost bit of number is handled now, shifting the number by one bit will make the second rightmost bit be first.
 * 		+ This is necessary because algorithm is designed to work only on the rightmost bit.
 *
 * Repeat until all the bits are handled
 *
 */

#include <stdio.h>


void reverseBits( unsigned int number, int* bits )
{
	for ( int i=0; i < sizeof(unsigned)*8; i++ )
	{
		bits[i] = 1 & number;

		number >>= 1;
	}
}


void revealBits( unsigned int number, int* bits )
{
	for ( int i=0; i < sizeof(unsigned)*8; i++ )
	{
		bits[ sizeof(unsigned)*8 - i - 1 ] = 1 & number;

		number >>= 1;
	}
}


void printBits( const int* const bits )
{
	for ( int i=1; i <= sizeof(unsigned)*8; i++ )
	{
		printf("%d", bits[i-1] );

		if ( i % 8 == 0  &&  i >= 8 )
		{
			printf(" ");
		}
	}
}



int main( void )
{
	unsigned int number;

	printf("Enter a non-negative integer: ");
	scanf("%u", &number );

	int bits[ sizeof(unsigned int)*8 ];

	printf( "Bits of %u:\n", number );

	revealBits( number, bits );
	printBits( bits );

	printf( "\n\nReversed bits of %u:\n", number );

	reverseBits( number, bits );
	printBits( bits );




	return 0;
}
