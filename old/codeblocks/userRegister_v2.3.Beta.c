///rewrite numberOfLines() to not contain infinite loop.

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





int deleteUser(const int userNumber) {

    int length = strlen(access(userNumber,1)) + strlen(access(userNumber,2)) + strlen(access(userNumber,3))+1;

    fptr = fopen("file.txt", "r+");

    if ( fptr == NULL ) {
            printf("Failed to open file.");
            exit(-1);
    }
    else {

        int i;
        for (i=1; i!=(3*(userNumber - 1)+1); i++) {

                fgets (receiveString, SIZE, fptr);
        }

        int pos = ftell(fptr);

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






int main() {
    char choice[50];

    while(1) {

        strcpy(blankName, "");
        strcpy(blankPassword, "");
        nou = numberOfLines()/3;

        menu: ///menu///

        system("cls");
        printf("Welcome to the Super Secret Information Holder.\n");
        printf("Commands: /signIn  /signUp  /exit \n");
        fgets(choice, 20, stdin);

        if ( !strncmp(choice, "/exit", 5) ) { exit(1); }


        /// sign in ///
        else if ( !strncmp(choice, "/signIn", 7) ) {

                enterUsername: ///enterUsername///
                printf("Enter your username: ");
                fgets(blankName, SIZE, stdin);

                if ( ExistingUser(blankName, nou) ) {

                        int attempt = 0;
                        while ( attempt<5 ) {

                            printf("Please enter your password: ");
                            fgets(blankPassword, SIZE, stdin);

                            if ( PasswordCheck(blankPassword, ExistingUser(blankName, nou)) ) {

                                printf("Welcome, %s", access ( ExistingUser(blankName, nou), 1 ) );

                                getCommand4: /// getCommands4 ///
                                printf("Commands: /view.info   /delete.account: ");
                                fgets(choice, 50, stdin);

                                if ( !strncmp(choice, "/view.info", 10) ) {

                                    printf("Here is your secret information: %s", access ( ExistingUser(blankName, nou), 3 ) );

                                    getCommand5: /// getCommand5 ///
                                    printf("Commands: /back   /menu   /exit: ");
                                    fgets(choice, 50, stdin);
                                        if ( !strncmp(choice, "/back", 5) ) { goto getCommand4; }
                                        else if ( !strncmp(choice, "/menu", 5) ) { goto menu; }
                                        else if ( !strncmp(choice, "/exit", 5) ) { exit(1); }
                                        else { printf("Invalid command. "); goto getCommand5; }

                                }

                                else if ( !strncmp(choice, "/delete.account", 15) ) {

                                        printf("Are you sure to delete your account? All of your information will be lost forever. (very long time...)\n");
                                        printf("Type /confirm to confirm. Do something else to cancel: ");
                                        fgets(choice, 50, stdin);

                                        if ( !strncmp(choice, "/confirm", 8) ) {

                                                deleteUser(ExistingUser(blankName, nou));
                                                printf("You have deleted your account.\n");
                                                printf("Press any key to continue: ");
                                                getch();
                                                goto menu;

                                        }
                                        else {
                                                printf("Huh... I thought you would really do this...\n");
                                                goto getCommand4;
                                        }
                                }
                                else {
                                        printf("Invalid command. ");
                                        goto getCommand4;
                                }

                            }

                            else {

                                attempt++;
                                if ( attempt == 5 ) { LockScreen(300); attempt = 0; }

                                printf("Incorrect password. Please try again. (%d attempt%s left.)\n", 5-attempt, (5-attempt)==1? "" : "s");

                                    printf("Press enter to continue, type /back to go back: ");
                                    fgets(choice, 20, stdin);

                                    if ( !strncmp(choice, "/back", 6) ) { system("cls"); goto enterUsername; }

                                    strcpy(choice, "");

                            }
                        }
                }//(ENDOF) if: sing in -> if: existing user

                //(BEGIN) if: sing in -> if: no matches found:
                else {
                        printf("No matches found.\n");

                        getCommand1: ///getCommand1///

                            printf("Commands: /back   /menu\n");
                            fgets(choice, 20, stdin);

                            if ( !strncmp(choice, "/back", 5) ) { goto enterUsername; }
                            else if ( !strncmp(choice, "/menu", 5) ) { goto menu; }
                            else { printf("Invalid command. Please try again."); goto getCommand1; }
                }

        }//(ENDOF) if: sing in

        /// sign up ///
        else if ( !strncmp(choice, "/signUp", 7) ) {

                 getCommand2: ///getCommand2///
                    printf("Commands: /register  /menu\n");
                    fgets(choice, 20, stdin);

                    if ( !strncmp(choice, "/register", 9) ) {

                            if ( !Register() ) { system("cls"); goto menu; }

                    }

                    else if ( !strncmp(choice, "/menu", 5) ) {
                            goto menu;
                    }

                    else {
                            printf("Invalid command, please try again.\n");
                            goto getCommand2;
                    }

        }
        else {

                printf("Invalid command.");
                goto menu;

        }

        printf("\nTo exit the program; press 0, press anything else to go back to menu:  ");
        int command;
        command = getch();
        if ( command == 48 ) { exit(1); }








    }
    return 0;
}

















