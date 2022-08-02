#include<stdio.h>
#include<string.h>
#include<stdbool.h>

char blankName[20];
char blankPassword[20];
char blankSSI[20];

char passwordConfirm[20];

bool match;



char Users [][3][20] = {
                    "username", "password", "secret",
                    "Ahmet", "Ahmet", "Ahmet",
                       };

int n;
char user[20];
int i;

int nou;

int Length(int x, int y) {
    int length;
    for (length = 0; length <= 20; length++) {
        if(Users[x][y][length] == '\0') { break; }
    }
    return length;
}



bool Match(int userNumber, int nameOrPassword, char stringToCheck[20]) {
        if (nameOrPassword == 0) {      //for name
            n = Length(userNumber, 0);
        }
        else {      //for password
                n  = strlen(stringToCheck) - 1; //ATTENTION !
        }

        for (i=0; i<20; i++) {

                if(i == n) { break; }
                if( stringToCheck[i] == Users[userNumber][nameOrPassword][i] ) { match = true; continue; }

                match = false;
                break;

        }
    return match;

}

void Register(char tempString[20], int userCounter) {          //call with the arguments: (blankName, nou)


    n = strlen(tempString);

    for ( i=0; i<20; i++) {
            if(i == n) { break; }
            Users[nou][0][i] = tempString[i];
    }
    nou++;


    setPassword:
        printf("Please set a password: ");
        fgets(blankPassword, 20, stdin);

        printf("Please confirm your password: ");
        fgets(passwordConfirm, 20, stdin);

    if ( strcmp(blankPassword, passwordConfirm ) == 0 ) {

            for (i=0; i<strlen(blankPassword)-1; i++) {
                Users[nou][1][i] = blankPassword[i];
            }

            printf("You have sucessfully registered. ");
            printf("Please enter your super secret information: ");
            fgets(blankSSI, 20, stdin);
            for (i=0; i<strlen(blankSSI); i++) {
                Users[nou][2][i] = blankSSI[i];
            }
            for (i=0; i<strlen(blankPassword)-1; i++) {
                    printf("%c", Users[nou][1][i]);
            }


    }
    else {
            printf("Not confirmed.");
            goto setPassword;

    }
}





int j;
int main() {
    nou = 2;

    begin:

    strcpy(blankName, "");
    strcpy(blankPassword, "");
    strcpy(blankSSI, "");


    printf("Enter your username: ");
    fgets(blankName, 20, stdin);



    for (j=0; j<nou; j++) {

        if(Match(j, 0, blankName)) { break; }
    }

bool elma = true;
    if(Match(j, 0, blankName)) {
        printf("Match for %d.user\n", j);

        enterPassword:
            printf("Please enter your password: ");
            fgets(blankPassword, 20, stdin);

        for (i=0; i<strlen(blankPassword); i++) {
                if (Users[nou][1][i] != blankPassword[i]) {
                    elma = false;
                }

        }
        if (elma) {
                printf("You have successfully logged in.\n");
        }
        else {
                printf("Wrong password.\n");
        }


       /* if( Match(j, 1, blankPassword) ) { printf("You have logged in!"); }
        else {
                printf("Wrong password\n");
                goto enterPassword;
        }*/
    }
    else{
        Register(blankName, nou);
    }






    goto begin;
    return 0;

}
