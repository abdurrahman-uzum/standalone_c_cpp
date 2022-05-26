#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define SIZE 100


FILE *fptr;

char receivedString[100];
char receiveString1[100];
char returnString[100];

char blankName[100];
char blankPassword[100];
char blankSSI[1000];
char passwordConfirm[100];

int i;

int nou;

int existingUser;

int howManyLines;

char c;

long pos;

int count;

int numberOfLines;

int numberOfLines1;


/*
char *access(int userNumber, int getWhat) {

    fptr = fopen("file.txt", "r");
    int count = 4*(userNumber - 1) + getWhat;

    int i;
    for (i=1; ; i++) {

            fscanf (fptr, "%s", receiveString);

            //fgets (returnString, 100, fptr);
            //strncpy(receiveString, returnString, strlen(returnString)-1);

            if ( i == count ) { break; }

            strcpy(receiveString, "");
    }
    //strncpy (returnString, receiveString, strlen(receiveString)-1 );

    fclose(fptr);
    return receiveString;
}
*/

char *access(int userNumber, int getWhat) {

    count = (userNumber - 1)*3 + getWhat;

    fptr = fopen("file2.txt", "r");

    for ( i=0; c!=EOF; i++ ) {

            if ( numberOfLines == count -1 ) { break; }
            c = fgetc(fptr);
            if ( c == '/' ) { numberOfLines++; }

    }

    c = fgetc(fptr);
    for (i=0; receivedString!='/'; i++) {
            c = fgetc(fptr);
            receivedString[i] = c;
    }




    strncpy( returnString, receivedString, strlen(receivedString)-2 );

    return returnString;
}




void writeData(const char string1[100], const char string2[100], const char string3[1000]) {


    fptr = fopen("file2.txt", "r+");
    fseek (fptr, -9, SEEK_END);

    fprintf(fptr, "%s", string1);
    fprintf(fptr, "%s", string2);
    fprintf(fptr, "%s", string3);
    fprintf(fptr, "%s", "/end/\n");
    fprintf(fptr, "%s", "/endDoc/");

    fclose(fptr);

}


/*
int numberOfLines() {

    fptr = fopen("file.txt", "r");

    for (howManyLines = 0; strncmp(receiveString1, "/endDoc/", 8); howManyLines++) {

        fgets(receiveString1, 100, fptr);

    }
    strcpy(receiveString1, "");

    fclose(fptr);
    return howManyLines - 1;

}*/

int NumberOfLines() {

    fptr = fopen("file2.txt", "r");

    for ( i=0; c!=EOF; i++ ) {

            c = fgetc(fptr);
            if ( c == '/' ) { numberOfLines++; }

    }
    fclose(fptr);

    return numberOfLines1;
}





void Register() {

    setPassword:

        printf("Please set a password: ");
        fgets(blankPassword, 100, stdin);

        printf("Please confirm your password: ");
        fgets(passwordConfirm, 100, stdin);

        if( !strncmp(blankPassword, passwordConfirm, strlen(blankPassword)) && strlen(blankPassword) == strlen(passwordConfirm) ) {

            printf("Please type in your information: ");
            fgets(blankSSI, 1000, stdin);
            writeData(blankName, blankPassword, blankSSI);


            printf("You have successfully registered.\n");

        }
        else {
                printf("Passwords do not match, please try again.\n");
                goto setPassword;
        }
}


/*
void LogIn ( const char name[], const char password[] ) {  //call with the following arguments: blankName, blankPassword, blankSSI

    for(int j=1; j<7; j++) {          ///ATTENTION

        if ( !strncmp(name, access(j, 1), strlen(name)-1 ) ) {
                printf("Match for %d.user!\n", j);
                existingUser = 1;

                enterPassword:
                    printf("Please enter your password: ");
                    fgets(password, 100, stdin);

                if(  !strncmp(password, access(j,2), strlen(password)-1) && strlen(password)-1 == strlen(access(j,2)) ) {
                        printf("You have successfully logged in.\n");
                        printf("Here is your super secret information: ");
                        printf("%s\n\n", access(j, 3));
                }
                else {
                        printf("Wrong password, try again. ");
                        goto enterPassword;
                }
                break;
        }
    }
}
*/

int LogIn(char name[SIZE], char password[SIZE] ) {

    if ( !strncmp(name, access(2,1), strlen(name)-1) ) {
            printf("Match!");
    }
    else {
            printf("No matches found!");
    }

}






int main() {

    printf("%s\n", access(1,1));





    while(1) {

        existingUser = 0;

        strcpy(blankName, "");
        strcpy(blankPassword, "");
        strcpy(blankSSI, "");


        printf("Enter your username: ");
        fgets(blankName, 100, stdin);

        if ( !strncmp(blankName, access(3,1), strlen(blankName)-1 ) ) {
                printf("Match!");
        }
        else {
                printf("Nope!");
        }


        /*
        printf("%d", existingUser);

        if( existingUser != 1 ) {

            printf("No matches found.\n");
            char choice[20];
            printf("Please enter the command register for register with this name or press enter to go back: ");

            fgets(choice, 20, stdin);
            if ( !strncmp(choice, "register", 8) ) { Register(); }

        }*/



    }
    return 0;
}
