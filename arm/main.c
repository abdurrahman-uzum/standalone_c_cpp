#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

// defines special type for ( 3 x 4 ) of integers.
typedef int Special3D[ 3 ][ 4 ];

void arrays_multiDimensional() {

    char valuesA[ 5 ][ 2 ] = { {0,1}, {2,3}, {4,5}, {6,7}, {8,9} };

	int valuesB[   ][ 3 ] = { {1,3,5} , {2,4,6} };
	int valuesC[ 2 ][ 3 ] = { {1,3,5} , {2,4,6} };
	//int valuesC[ 2 ][  ] = { {1,3,5} , {2,4,6} };// error : array type has incomplete element type

	int valuesE[ 2 ][ 3 ][ 4 ] = {
		{
			{111, 112, 113, 114} ,  {121, 122, 123, 124} ,  {131, 132, 133, 134}
		},
		{
			{211, 212, 213, 214} ,  {221, 222, 223, 224} ,  {231, 232, 233, 234}
		}
	};

	int distanceAsBytes = (int)&valuesA[0][0] - (int)&valuesA[1][0];

	// see disassembly
	int value = 0;
	value = valuesA[0][0];
	value = valuesA[0][1];

	value = valuesA[1][0];
	value = valuesA[1][1];

	value = valuesA[2][0];
	value = valuesA[3][1];

	const int lengthI = 4;
	const int lengthJ = 3;
	const int lengthK = 2;

	size_t size = sizeof valuesE;

	for ( int k = 0; k < lengthK; k++ ) {

		for ( int j = 0; j < lengthJ; j++ ) {

			for ( int i = 0; i < lengthI; i++ ) {

				int hundreds = k + 1;
				int tens     = j + 1;
				int ones     = i;

				valuesE[ k ][ j ][ i ] = 100*hundreds + 10*tens + ones;
				printf( "%d%d%d ", hundreds, tens, ones );

			}//fori

		}//forj

	}//fork

	Special3D* p3D = NULL;
	size_t allocateBytes = sizeof(Special3D) * lengthK;

	void* buffer = malloc( allocateBytes );
	if ( buffer == NULL ) {
		// not enough memory, terminate the program with failure
	    exit( EXIT_FAILURE );
	}

	// Casting void* to int(*)[3][4]. Same effect as casting to Special3D*
	p3D = (int(*)[3][4]) buffer;

	for ( int k = 0; k < lengthK; k++ ) {

		for ( int j = 0; j < lengthJ; j++ ) {

			for ( int i = 0; i < lengthI; i++ ) {

				int hundreds = k + 1;
				int tens     = j + 1;
				int ones     = i;

				p3D[ k ][ j ][ i ] = 100*hundreds + 10*tens + ones;

			}//fori

		}//forj

	}//fork

    // free the previously allocated memory
	free( p3D );

}//arrays_multiDimensional

//-----------------------------------------------------------------------------

void arrays_multiDimensionalJagged() {

	// jagged array sample
	// refer https://en.wikipedia.org/wiki/Jagged_array
	int** values = NULL;

    // TODO : implement check for return value of all "malloc()"s for an allocation error
    int arrayCount = 3;
    values = (int**) malloc( arrayCount * sizeof(int*) );

    const int leastElementCount = 2;
	for ( int i = 0; i < arrayCount; i++ ) {

		int  length = i + leastElementCount;
		int* buffer = malloc( length * sizeof(int) );

		values[ i ] = buffer;

		// fill the buffer
		for ( int j = 0; j < length; j++ ) {

			values[ i ][ j ] = i*10 + j;

		}//forj

	}//fori


	int distanceAsBytes = (int)&values[0][0] - (int)&values[1][0];

	// see disassembly
	int value = 0;
	value = values[0][0];
	value = values[0][1];
	value = values[0][2];

	value = values[1][0];
	value = values[1][1];
	value = values[1][2];

	value = values[2][0];
	value = values[2][1];
	value = values[2][2];

	// TODO : we need lots of "free()"s here...

}//arrays_multiDimensionalJagged

//-----------------------------------------------------------------------------

void arrays_multiDimensionalJaggedvsFlat() {

	// jagged array sample
	// refer https://en.wikipedia.org/wiki/Jagged_array

	int** jagged = NULL;
    int   flat[3][3] = { {0,1,2}, {10,11,12}, {20,21,22} };

    // TODO : implement check for return value of all "malloc"s for an allocation error
    int arrayCount = 3;
    jagged = (int**) malloc( 2 * sizeof(int*) );

    const int leastElementCount = 2;
	for ( int i = 0; i < arrayCount; i++ ) {

		int  length = i + leastElementCount;
		int* buffer = malloc( length * sizeof(int) );

		jagged[ i ] = buffer;

		// fill the buffer
		for ( int j = 0; j < length; j++ ) {

			jagged[ i ][ j ] = i*10 + j;

		}//forj

	}//fori

	int distanceAsBytes = 0;
	distanceAsBytes = (int)&jagged[0][0] - (int)&jagged[1][0];
	distanceAsBytes = (int)&flat[0][0]   - (int)&flat[1][0];

	// see disassembly
	int value = 0;

	value = flat[0][0];
	value = jagged[0][0];

	value = jagged[0][0];
	value = jagged[0][1];
	value = jagged[0][2];

	value = jagged[1][0];
	value = jagged[1][1];
	value = jagged[1][2];

	value = flat[0][0];
	value = flat[0][1];
	value = flat[0][2];

	value = flat[1][0];
	value = flat[1][1];
	value = flat[1][2];

	// TODO : we need lots of "free()"s here...

}//arrays_multiDimensionalJagged

//-----------------------------------------------------------------------------
