

/// file.txt content:
/*
username
password
secret
abdurrahman
1234
elma is a nice fruit
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
abdurrahman2
4321
I hate apples.
abdurrahman3
12344321
fuck you all.
hello
1234
no i won't.
testingRegister
1234
i am testing

*/




#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<windows.h>

#define SIZE 1000

FILE *fptr;

char receiveString[SIZE];

char blankName[SIZE];
char blankPassword[SIZE];

int i,j;

int nou;

int howManyLines;

char c;

int pos;

char putString[SIZE];





char *access(const int userNumber, const int getWhat) {

    fptr = fopen("file3.txt", "r");

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

    fptr = fopen("file3.txt", "a");

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

    fptr = fopen("file3.txt", "r");
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




int Register() {

    char nameHolder[SIZE];

    char passwordHolder[SIZE];
    char passwordConfirm[SIZE];
    char blankSSI[SIZE];

    int command;


    setUsername: ///setUsername///

    printf("Please set a username: ");
    fgets(nameHolder, SIZE, stdin);


    if ( ExistingUser(nameHolder, nou) ) {
            printf("Username already taken. Please select another one.\n");
            goto setUsername;
    }
    else {

            getCommand0: ///getCommand0///

            printf("You will be registering with username: %s", nameHolder);
            printf("Press enter for confirm, 1 for select another username, 0 for go menu: \n");

            command = getch();

            if ( command == 48 ) { // ASCII 0

                  return 0;

            }
            else if ( command == 49 ) { // ASCII 1

                    goto setUsername;

            }
            else if ( command == 13 ) { //ASCII <enter>

                    setPassword:

                        printf("Please set a password: ");
                        fgets(passwordHolder, SIZE, stdin);

                        printf("Please confirm your password: ");
                        fgets(passwordConfirm, SIZE, stdin);

                        if( !strncmp(passwordHolder, passwordConfirm, strlen(passwordHolder)) && strlen(passwordHolder) == strlen(passwordConfirm) ) {

                            printf("Please type in your information: ");
                            fgets(blankSSI, SIZE, stdin);
                                writeData(nameHolder);
                                writeData(passwordHolder);
                                writeData(blankSSI);

                            strcpy(passwordHolder, "");
                            strcpy(passwordConfirm, "");
                            strcpy(blankSSI, "");


                            printf("You have successfully registered. Press any key to continue: \n");
                            getch();
                            return 1;

                        }
                        else {
                                getCommand0_1: ///getCommand0_1///

                                printf("Passwords don't match. Press 1 for going back, <enter> for trying again: ");
                                command = getch();

                                if ( command == 13 ) { goto setPassword; }
                                else if ( command == 49 ) { goto getCommand0; }
                                else { printf("Invalid command."); goto getCommand0_1; }


                        }
                    }
    }
}




int ExistingUser( const char name[], const int numberOfUsers ) {

    for( j = 1; j<nou; j++ ) {

        if ( !strncmp(name, access(j, 1), strlen(name)-1 ) && strlen(name) == strlen(access(j,1)) ) {
                return j;
        }
    }

    return 0;
}





int PasswordCheck( const char password[], const int userNumber ) {

        if(  !strncmp(password, access(userNumber,2), strlen(password)-1) && strlen(password) == strlen(access(userNumber,2)) ) {
               return 1;
        }
        else {
                return 0;
        }
}





void LockScreen( const int duration ) {

    for (i=duration; i>0; i--) {
            printf("%d\n", i);
            Sleep(1000);
    }
}

int Access(const int userNumber, const int getWhat) {

    fptr = fopen("file3.txt", "r");

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
        pos = ftell(fptr);
        fclose(fptr);
        return pos;
    }

}

int deleteUser(const int userNumber) {

    int length = strlen(access(userNumber,1)) + strlen(access(userNumber,2)) + strlen(access(userNumber,3))+1;

    fptr = fopen("file3.txt", "r+");

    if ( fptr == NULL ) {
            printf("Failed to open file.");
            exit(-1);
    }
    else {

        int count = 3*(userNumber - 1);

        int i;
        for (i=1; ; i++) {

                fgets (receiveString, SIZE, fptr);
                if ( i == count ) { break; }

                strcpy(receiveString, "");
        }
        pos = ftell(fptr);

        fseek( fptr, pos, SEEK_SET);

        for (i=0; i<length; i++) {
                fprintf(fptr, "%c", NULL);
        }
        fseek( fptr, pos, SEEK_SET);
        fprintf(fptr, "%c\n%c\n%c", '*', '*', '*');



        fclose(fptr);


    }



    return 1;
}





int main() {

    deleteUser(2);






























    return 0;
}

















