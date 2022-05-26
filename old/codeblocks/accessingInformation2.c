#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#define SIZE 100


FILE *fptr;

char c;
int i, j, a, b;
int numberOfLines;
int len;
int escape;

int count;

char receivedString[SIZE];
char returnString[SIZE];


/*
int NumberOfLines() {

    fptr = fopen("file2.txt", "r");

    for ( i=0; c!=EOF; i++ ) {

            c = fgetc(fptr);
            if ( c == '/' ) { numberOfLines++; }

    }
    fclose(fptr);

    return numberOfLines;
}

/*
char *access (int whichUser, int getWhat) {

    fptr = fopen("file2.txt", "r");

    count = (whichUser-1)*3 + getWhat-1;

    while(c!=EOF) {
            for (i=0; i<SIZE; i++) {
                    c = fgetc(fptr);

                    if ( c == '/' ) { numberOfLines++; }

                    if(numberOfLines == count) {

                            while (receivedString[i]!='/') {

                                receivedString[i] = fgetc(fptr);
                            }
                    }
            }
    }
    fclose(fptr);
    return receivedString;
}
*/

char *access (int userNumber, int getWhat) {

    count = (userNumber - 1)*3 + getWhat;

    fptr = fopen("file2.txt", "r");

    for ( i=0; c!=EOF; i++ ) {

            if ( numberOfLines == count -1 ) { break; }
            c = fgetc(fptr);
            if ( c == '/' ) { numberOfLines++; }

    }

    for (i=0; ; i++) {  //Attempted alternative for fgets(), same problem occurred anyway...

        receivedString[i] = fgetc(fptr);
        if ( receivedString[i] == '/' ) { break; }

    }


    return receivedString;
}





int main () {

    while(1) {

        printf("Which user do you want to access: ");
        scanf("%d", &a);

        printf("What do you want to access: ");
        scanf("%d", &b);


        printf("%s\n\n", access(a,b));

    }







    return 0;
}






















