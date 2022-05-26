///Working file content: If something goes wrong, try to mess with consts.
/*
username
password
secret
abdurrahman
1234
elma
bot1
bot1pass
info
bot2
bot2pass
info2
bot3
bot3pass
info3
mahmut
12345678
ehuehuehue
botbot
botbot
botbot
thisisatest
test
testInfo
letstryagain
testagain
thisissecondtest
somethingelse
1234
shitgonnahappen
somethingelse2
4321
shitalwayshappens
somethingelse3
9876
shitmayhappen
*/




#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define SIZE 1000

FILE *fptr;

char receiveString[SIZE];

char blankName[SIZE];
char blankPassword[SIZE];
char blankSSI[SIZE];
char passwordConfirm[SIZE];

int i;

int nou;

int existingUser;

int howManyLines;

char c;



char *access(const int userNumber, const int getWhat) {

    fptr = fopen("file.txt", "r");

    if ( fptr == NULL ) {
            printf("Failed to open file.");
            exit(-1);
    }
    else {

        int count = 3*(userNumber - 1) + getWhat;

        int i;
        for (i=1; ; i++) {

                fgets (receiveString, SIZE, fptr);
                if ( i == count ) { break; }

                strcpy(receiveString, "");
        }

        fclose(fptr);
        return receiveString;
    }

}


void writeData(const char blankString[SIZE]) {

    fptr = fopen("file.txt", "a");

    if ( fptr == NULL ) {
            printf("Failed to open file.");
            exit(-1);
    }
    else {
        fprintf(fptr, "%s", blankString);
    }

    fclose(fptr);

}

int numberOfLines() {

    fptr = fopen("file.txt", "r");
    if( fptr == NULL ) {
            printf("Failed to open file.");
            exit(-1);
    }
    else {

        while (1) {
                c = fgetc(fptr);

                if(c=='\n') { howManyLines++; continue; }
                if( c == EOF ) { break; }


        }
        fclose(fptr);
        return howManyLines;
    }
}




void Register() {

    setPassword:

        printf("Please set a password: ");
        fgets(blankPassword, SIZE, stdin);

        printf("Please confirm your password: ");
        fgets(passwordConfirm, SIZE, stdin);

        if( !strncmp(blankPassword, passwordConfirm, strlen(blankPassword)) && strlen(blankPassword) == strlen(passwordConfirm) ) {

            printf("Please type in your information: ");
            fgets(blankSSI, SIZE, stdin);
            writeData(blankName);
            writeData(blankPassword);
            writeData(blankSSI);

            printf("You have successfully registered.\n");

        }
        else {
                printf("Passwords do not match, please try again.\n");
                goto setPassword;
        }
}



void LogIn(const char name[], const char password[], const int numberOfUsers) {  //call with the following arguments: blankName, blankPassword, blankSSI

    for(int j = 1; j<nou; j++) {

        if ( !strncmp(name, access(j, 1), strlen(name)-1 ) && strlen(name) == strlen(access(j,1)) ) {
                printf("Match for %d.user!\n", j);
                existingUser = 1;

                enterPassword:
                    printf("Please enter your password: ");
                    fgets(password, SIZE, stdin);

                if(  !strncmp(password, access(j,2), strlen(password)-1) && strlen(password) == strlen(access(j,2)) ) {
                        printf("You have successfully logged in.\n");
                        printf("Here is your super secret information: ");
                        printf("%s\n", access(j, 3));

                        printf("Press enter to exit.");
                        getch();
                        system("cls");
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
        fgets(blankName, SIZE, stdin);

        nou = numberOfLines()/3;
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
