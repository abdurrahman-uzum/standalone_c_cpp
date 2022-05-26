/*
 * EED1010 / Example #05 / Task #1
 *
 * Abdurrahman ÜZÜM / 2019502099
 *
 * Date: 25.03.2020 13:30
 */


#include <stdio.h>


int main ( void )
{
	union Union
	{
		int i;
		float f;
		char c;
	}data;

	printf("Size of <data>: %d\n", sizeof(data));
	printf("Size of int:%d, float:%d, char:%d\n", sizeof(int), sizeof(float), sizeof(char));
	// Size of the union <data> is the size of largest element in the union. In this case, int and float are same size and 4 bytes.
	// If float was changed to double at the union <data>, size of union would then have size of double, which is 8 bytes.


	printf("Addresses:\nint: %p\nfloat: %p\nchar: %p\n", &data.i, &data.f, &data.c);
	// All at the same memory address.


	data.i = 5;
	data.f = 1.2;
	data.c = 'A';

	printf("Values #1:\nint: %d\nfloat: %f\nchar: %c\n", data.i, data.f, data.c );
	// data.i and data.f are corrupted.



	data.i = 5;
	data.c = 'A';
	data.f = 1.2;

	printf("Values #2:\nint: %d\nfloat: %f\nchar: %c\n", data.i, data.f, data.c );
	// data.i and data.c are corrupted.



	data.f = 1.2;
	data.c = 'A';
	data.i = 5;

	printf("Values #3:\nint: %d\nfloat: %f\nchar: %c\n", data.i, data.f, data.c );
	// data.f and data.c are corrupted.











	return 0;
}
