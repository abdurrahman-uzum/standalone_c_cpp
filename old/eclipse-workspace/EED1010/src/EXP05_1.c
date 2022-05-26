/*
 * EED1010 / Example #05 / Task #1
 *
 * Abdurrahman ÜZÜM / 2019502099
 *
 * Date: 25.03.2020 02:32
 *
 * An application for -supposedly- a bus firm to keep track of seat reservations.
 *
 * Notes from the creator:
 *
 * 		U/I> stands for user input ( appears where user input is needed ), C/O> stands for computer output.
 *
 * 		Canceling a reservation does NOT delete existing information, but allows overwriting.
 *
 * 		I don't see any use of the ID member here, so it's initialized to 0 and never bothered with it again.
 * 		If you really want to, you can initialize it from 1 to 25 at the for loop in the main. Or give random values, idk...
 *
 * 		I made the functions return an integer value, and implemented the ability the error handling, yet never did so.
 *
 * 		I believe the code is pretty self-explanatory so I kept the comments at the minimal level.
 *
 * 		Running the application on full-screen console is recommended.
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SOI 100 // size of input
#define SOB 26  // size of bus ( showImage() function does NOT check size. Better not mess with that )


struct Seats
{
	int ID;
	char name[SOI];
	char surname[SOI];
	int available;

}seats[SOB];




int addNewReservation( void )
{
	int seatNumber;
	int command = 0;

	printf("\n\n----------Add New Reservation----------\n");
	printf("U/I> Enter seat number: ");

	scanf("%d", &seatNumber);
	if ( seatNumber >= SOB || seatNumber < 1 )
	{
		printf("C/O> Invalid number entered.\n");
		return -1;
	}

	getchar();  // Consuming the '\n' character left in the stdin buffer after scanf()

	if( !seats[seatNumber].available )
	{
		printf("Seat not available!\n");
		return -1;
	}


	printf("U/I> Enter your name ");
	fgets(seats[seatNumber].name, SOI, stdin);
	strcpy(seats[seatNumber].name, strtok(seats[seatNumber].name, "\n"));  // Removing the '\n' character that fgets() takes alongside with the input string.


	printf("U/I> Enter your surname ");
	fgets(seats[seatNumber].surname, SOI, stdin);
	strcpy(seats[seatNumber].surname, strtok(seats[seatNumber].surname, "\n"));


	printf("\nU/I> Enter 1 to confirm the following information:\n");
	printf(" Seat number: %d\n Name: %s\n Surname: %s\n", seatNumber, seats[seatNumber].name, seats[seatNumber].surname );
	scanf("%d", &command);


	if ( command == 1 )
	{
		printf("C/O> Reservation successfully completed.\n");

		seats[seatNumber].available = 0;

		return 0;
	}
	else
	{
		printf("C/O> Reservation failed!\n");
		seats[seatNumber].available = 1;
		return -1;
	}
}



int cancelReservation( void )
{
	int seatNumber = 0;
	int command = 0;
	printf("\n\n----------Cancel Reservation----------\n");

	printf("U/I> Enter the seat number to cancel reservation ");

	scanf("%d", &seatNumber);

	if ( seatNumber >= SOB || seatNumber < 1 )
	{
		printf("C/O> Invalid number entered.\n");
		return -1;
	}


	if ( seats[seatNumber].available )
	{
		printf("C/O> No reservations found for this seat.\n");
		return -1;
	}


	printf("U/I> Enter 1 to confirm canceling the following reservation:\n");

	printf(" Seat number: %d\n Name: %s\n Surname: %s\n", seatNumber, seats[seatNumber].name, seats[seatNumber].surname );

	scanf("%d", &command);

	if ( command )
	{
		seats[seatNumber].available = 1;

		printf("C/O> Reservation successfully cancelled.\n");

		return 0;
	}
	else
	{
		printf("C/O> Canceling failed!\n");

		return -1;
	}
}



void showSeats( void )
{
	printf("\n\n");
	printf("C/O>\n");

	printf("  -------------------------------------  \n");
	printf("  ||     |                           ||  \n");
	printf("  ||  D  |     <#: Reserved>         ||  \n");
	printf("  ||     |                           ||  \n");
	printf("  -------------------------------------  \n");
	printf("  ||     |     |         |     |     ||  \n");
	printf("  || %s  | %s  |         | %s  | %s  ||  \n", seats[1].available ? " 1":" #", seats[2].available ? " 2":" #", seats[3].available ? " 3":" #", seats[4].available ? " 4":" #");
	printf("  ||     |     |         |     |     ||  \n");
	printf("  -------------------------------------  \n");
	printf("  ||     |     |         |     |     ||  \n");
	printf("  || %s  | %s  |         | %s  | %s  ||  \n", seats[5].available ? " 5":" #", seats[6].available ? " 5":" #", seats[7].available ? " 7":" #", seats[8].available ? " 8":" #");
	printf("  ||     |     |         |     |     ||  \n");
	printf("  -------------------------------------  \n");
	printf("  ||     |     |         |     |     ||  \n");
	printf("  || %s  | %s  |         | %s  | %s  ||  \n", seats[9].available ? " 9":" #", seats[10].available ? "10":" #", seats[11].available ? "11":" #", seats[12].available ? "12":" #");
	printf("  ||     |     |         |     |     ||  \n");
	printf("  -------------------------------------  \n");
	printf("  ||     |     |         |     |     ||  \n");
	printf("  || %s  | %s  |         | %s  | %s  ||  \n", seats[13].available ? "13":" #", seats[14].available ? "14":" #", seats[15].available ? "15":" #", seats[16].available ? "16":" #");
	printf("  ||     |     |         |     |     ||  \n");
	printf("  -------------------------------------  \n");
	printf("  ||     |     |         |     |     ||  \n");
	printf("  || %s  | %s  |         | %s  | %s  ||  \n", seats[17].available ? "17":" #", seats[18].available ? "18":" #", seats[19].available ? "19":" #", seats[20].available ? "20":" #");
	printf("  ||     |     |         |     |     ||  \n");
	printf("  -------------------------------------  \n");
	printf("  ||     |     | |     | |     |     ||  \n");
	printf("  || %s  | %s  | | %s  | | %s  | %s  ||  \n", seats[21].available ? "21":" #", seats[22].available ? "22":" #", seats[23].available ? "23":" #", seats[24].available ? "24":" #", seats[25].available ? "25":" #");
	printf("  ||     |     | |     | |     |     ||  \n");
	printf("  -------------------------------------  \n");
}




void showCommands( void )
{
	printf("\n\n---------------COMMANDS---------------\n");
	printf(" 0 : Exit\n 1 : Add new reservation\n 2 : Cancel reservation\n 3 : Show available & reserved seats\n" );
	printf("U/I> Please type a command...   ");
}







int main( void )
{
	printf("\n\n");
	printf("------------------------------------------------------------\n");
	printf("|                 S E A T   M A N A G E R                  |\n");
	printf("------------------------------------------------------------\n");

	int command = 0;

	// Creating a default seat:
	seats[0].ID = 0;
	strcpy( seats[0].name, "" );
	strcpy( seats[0].surname, "" );
	seats[0].available = 1;

	// Initializing all seats to default.
	for ( int i=0; i < SOB; i++ ) { seats[i] = seats[0]; }

	showSeats();

	// Main loop, to be ended if user requests exit.
	while ( 1 )
	{
		showCommands();
		scanf( "%d", &command );

		switch ( command )
		{
			case 0:
				exit(0);
			break;

			case 1:
				addNewReservation();
			break;

			case 2:
				cancelReservation ();
			break;

			case 3:
				showSeats();
			break;

			default:
				printf("C/O> Invalid number entered.\n");
			break;
		}
	}



	return 0;
}
