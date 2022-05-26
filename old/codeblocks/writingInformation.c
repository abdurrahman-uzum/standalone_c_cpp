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

void writeData(char blankString[100]) {

    fptr = fopen("file.txt", "a");
    fprintf(fptr, " %s", blankString);
    fclose(fptr);

}




int main() {

    while(1) {

    int a;
    int b;

    int i;
    int j;

    char c;

    char blankName[20] = "botName";
    char blankPassword[20] = "botPassword";
    char blankInfo[20] = "botInfo";

    int desiredValue;
    int getWhat;

    int writeWhat;
    char writeWhere[100];





    writeData(blankName);
    break;






















    }

    return 0;
}



