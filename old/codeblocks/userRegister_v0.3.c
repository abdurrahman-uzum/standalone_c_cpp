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
int i;
int length;

int nou;


bool Match(int userNumber, int nameOrPassword, char testString[20]) {

        length = strlen(Users[userNumber][nameOrPassword]);

        if ( strncmp(testString, Users[userNumber][nameOrPassword], length) == 0 ) { match = true; }
        else { match = false; }

    return match;

}


void Register(char Username[20]) {

    strncpy(Users[nou][0], Username, strlen(Username)-1);

    setPassword:
        printf("Please set a password: ");

}









int main() {


    nou = 2;

    begin:

    strcpy(blankName, "");
    strcpy(blankPassword, "");
    strcpy(blankSSI, "");


    printf("Enter your username: ");
    fgets(blankName, 20, stdin);

    int j = 0;
    check:
        if( strncmp(blankName, Users[j][0], strlen(blankName)-1) == 0 ) {
                printf("Match for %d.user!\n", j);

                enterPassword:
                    printf("Please enter you password: ");
                    fgets(blankPassword, 20, stdin);
                if( strncmp(blankPassword, Users[j][1], strlen(blankPassword)-1) == 0 ) {
                        printf("You have successfully logged in.\n");
                        goto begin;
                }
                else {
                        printf("Incorrect password. Please try again.\n");
                        goto enterPassword;
                }
        }
        else {
                if(j<nou-1) {
                j++;
                goto check;
                }
        }

    printf("No matches found.\n");

    strncpy(Users[nou][0], blankName, strlen(blankName)-1);

    printf("Please set a password: ");
    fgets(blankPassword, 20, stdin);

    strncpy(Users[nou][1], blankPassword, strlen(blankPassword)-1);

    printf("You have successfully registered.");
    nou++;











    goto begin;
    return 0;

}
