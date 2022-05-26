#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *fptr;

char receiveString[100];

    int a;
    int b;

    int i;
    int j;
    char c;
    char blankName[20];
    int desiredValue;
    int getWhat;
    int numberOfLines = 1;
    long pos;



char *access(int userNumber, int getWhat) {

    fptr = fopen("file.txt", "r");

    int count = 4*(userNumber - 1) + getWhat;

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

    fptr = fopen("file2.txt", "r+");


    for (numberOfLines = 0; strncmp(receiveString, "/endDoc/", 8); numberOfLines++) {

        fgets(receiveString, 100, fptr);

    }
    pos = ftell(fptr);
    fseek (fptr, pos - 9, SEEK_SET);



    printf("%d", numberOfLines);
    printf("\n%ld", pos);




    fprintf(fptr, "This line has been deleted.");









    fclose(fptr);
    return 0;
}


















