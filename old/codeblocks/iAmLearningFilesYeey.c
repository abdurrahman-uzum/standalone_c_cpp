#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *fptr;

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

    while(1) {

    int a;
    int b;

    int i;
    int j;
    char c;
    char blankName[20];
    int desiredValue;
    int getWhat;



    printf("Please enter which user do you want to access: ");
    scanf("%d", &a);
    printf("Please type 1, 2 or 3 in order to access username, password, information: ");
    scanf("%d", &b);

    printf("%s", access(a,b));








    }

    return 0;
}



/*
    printf("Please enter which user do you want to access: ");
    scanf("%d", &desiredValue);
    printf("Please type 1, 2 or 3 in order to access username, password, information: ");
    scanf("%d", &getWhat);

    count = 3*(desiredValue - 1) + getWhat;

    for (i=1; ; i++) {

            fscanf (fptr, "%s", receiveString);

            if ( i == count ) {

                printf ("%s", receiveString);
                printf("/end/\n");
                break;

            }
            strcpy(receiveString, "");
    }

    printf("\n");
    */





/*
for (j=0; ; j++) {
        if (c=='\n') { break; }

        for (i=0; ; i++) {

            c = fgetc(fptr);
            if (c==' ' || c=='\n') { break; }

            printf("%c", c);

        }
        printf("/end/");
        */
