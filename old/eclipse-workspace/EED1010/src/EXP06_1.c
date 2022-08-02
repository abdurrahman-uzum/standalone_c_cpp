#include <stdio.h>

typedef enum Months { JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEPT, OCT, NOV, DEC } Months;
typedef enum Seasons { WINTER, SPRING, SUMMER, AUTUMN } Seasons;

int main( void )
{
	Months month;
	Seasons season;

	char* months[12] = { "December", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November" };
	char* seasons[4] = { "Winter", "Spring", "Summer", "Autumn" };

	for ( month = 1; month < 13; month++ )
	{
		season = ( month % 12 ) / 3;
		printf( "No:%3d   %9s     %s\n", month, months[month%12], seasons[season] );
	}


	return 0;
}

// What's the point?
