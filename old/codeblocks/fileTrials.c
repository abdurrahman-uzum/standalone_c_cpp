#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *fptr;
char blankString[100];
char receiveString[100];

char *access(int userNumber, int getWhat) {

    fptr = fopen("file.txt", "r");

    int count = 3*(userNumber - 1) + getWhat;

    int i;
    for (i=1; ; i++) {

            fscanf (fptr, "%s", receiveString);

            if ( i == count ) {


                break;

            }

            strcpy(receiveString, "");
    }
    return receiveString;


}


int main() {

    fptr = fopen("file.txt", "r");

    printf("Please enter a string: ");
    fgets(blankString, 20, stdin);

    if (strncmp(blankString, access(1,1), strlen(blankString)-1) == 0) {
            printf("Match!");
    }
    else {
            printf("No match!");
    }
}
