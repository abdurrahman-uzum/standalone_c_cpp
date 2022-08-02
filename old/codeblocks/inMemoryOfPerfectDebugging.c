#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#define SIZE 100


FILE *fptr;

char c;
int i, j;
int numberOfLines;
int len;
int escape;

int count;

char receivedString[SIZE];

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





int main () {

    fptr = fopen("file2.txt", "r");

    count = (2-1)*3;

    while(c!=EOF && escape!=-1) {
            printf("Entered while\n");

            for (i=0; escape!=-1; i++) {
                    printf("Entered for\n");
                    c = fgetc(fptr);

                    if ( c == '/' ) {
                            printf("Entered if\n");
                            numberOfLines++;
                    }

                    if(numberOfLines == 3) {
                            printf("Entered second if\n");

                            for (j=0; j<100; j++) {

                                printf("ENTERED SECOND FOR\n");
                                receivedString[j] = fgetc(fptr);
                                if(receivedString[j] == '/') {break;}

                            }
                            printf("Second for ended\n");
                            escape = -1;

                    }
            }
            printf("Exited first for\n");
    }
    printf("Exited while\n");
    fclose(fptr);


    printf("Received string is: %s", receivedString);














    return 0;
}
