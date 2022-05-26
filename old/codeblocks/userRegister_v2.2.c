
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




void Register( const char nameHolder[] ) {

    char passwordHolder[SIZE];
    char passwordConfirm[SIZE];
    char blankSSI[SIZE];

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


            printf("You have successfully registered.\n");

        }
        else {
                printf("Passwords do not match, please try again.\n");
                goto setPassword;
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






int main() {
    char choice[20];

    while(1) {

        strcpy(blankName, "");
        strcpy(blankPassword, "");
        nou = numberOfLines()/3;


        enterUsername:
        printf("Enter your username: ");
        fgets(blankName, SIZE, stdin);

        if ( ExistingUser(blankName, nou) ) {

                int attempt = 0;
                while ( attempt<5 ) {

                    printf("Please enter your password: ");
                    fgets(blankPassword, SIZE, stdin);

                    if ( PasswordCheck(blankPassword, ExistingUser(blankName, nou)) ) {

                        printf("Welcome, %s", access ( ExistingUser(blankName, nou), 1 ) );
                        printf("Here is your secret information: %s", access ( ExistingUser(blankName, nou), 3 ) );

                            printf("Press enter to log out.");
                            getch();
                            system("cls");
                            break;

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
        }//End of: if existing user


        else {
                printf("No matches found\n");

                getCommand:
                    printf("Please type /register in order to register with this name, /back for going back: ");
                    fgets(choice, 20, stdin);

                    if ( !strncmp(choice, "/back", 5) ) {
                            system("cls");
                            goto enterUsername;
                    }
                    else if ( !strncmp(choice, "/register", 9) ) {
                            Register(blankName);
                    }
                    else {
                            printf("Invalid command, please try again.\n");
                            goto getCommand;
                    }
        }







    }
    return 0;
}

















