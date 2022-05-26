// DO NOT TRY TO CREATE NEW USER !



#include<stdio.h>
#include<string.h>
#include<stdbool.h>

FILE *fptr;

char receiveString[100];
char receiveString1[100];

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



char *access(int userNumber, int getWhat) {

    fptr = fopen("file.txt", "r");
    int count = 4*(userNumber - 1) + getWhat;

    int i;
    for (i=1; ; i++) {

            fscanf (fptr, "%s", receiveString);
            if ( i == count ) { break; }

            strcpy(receiveString, "");
    }

    return receiveString;
}

void writeData(char blankString1[100], char blankString2[100], char blankString3[1000]) {


    fptr = fopen("file.txt", "r+");
    fseek (fptr, -9, SEEK_END);      //You may wanna make that nine eight.

    fprintf(fptr, "%s", blankString1);
    fprintf(fptr, "%s", blankString2);
    fprintf(fptr, "%s", blankString3);
    fprintf(fptr, "%s", "/end/\n");
    fprintf(fptr, "%s", "/endDoc/");

    fclose(fptr);

}


/*
int numberOfLines() {

    fptr = fopen("file.txt", "r");

        while (1) {
                c = fgetc(fptr);

                if(c=='\n') { howManyLines++; continue; }
                if(isalpha(c)==0 && isdigit(c)==0) { break; }

        }
        fclose(fptr);
        return howManyLines+1;
    }*/



    //TEST ONGOING !

int numberOfLines() {

    fptr = fopen("file.txt", "r");

    for (howManyLines = 0; strncmp(receiveString1, "/endDoc/", 8); howManyLines++) {

        fgets(receiveString1, 100, fptr);

    }
    strcpy(receiveString1, "");
    //pos = ftell(fptr);

    fclose(fptr);
    return howManyLines - 1;
}
        //fseek (fptr, pos - 9, SEEK_SET);

















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



void LogIn(char name[], char password[], int numberOfUsers) {  //call with the following arguments: blankName, blankPassword, blankSSI

    for(int j = 1; j<nou+1; j++) {

        if ( !strncmp(name, access(j, 1), strlen(name)-1 ) && strlen(name)-1 == strlen(access(j,1)) ) {
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




int main() {


    while(1) {


    existingUser = 0;

    strcpy(blankName, "");
    strcpy(blankPassword, "");
    strcpy(blankSSI, "");

    printf("Enter your username: ");
    fgets(blankName, 100, stdin);

    nou = numberOfLines()/4;
    LogIn(blankName, blankPassword, nou);

    printf("%d", existingUser);

    if( existingUser != 1 ) {

        printf("No matches found.\n");
        char choice[20];
        printf("Please enter the command register for register with this name or press enter to go back: ");

        fgets(choice, 20, stdin);
        if ( !strncmp(choice, "register", 8) ) { Register(); }

    }



    }
    return 0;
}
