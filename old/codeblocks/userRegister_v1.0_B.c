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
                        //"Ahmet", "Ahmet", "Ahmet",
                       };

int n;
int i;
int length;

int nou;


int main() {




    begin:

    strcpy(blankName, "");
    strcpy(blankPassword, "");
    strcpy(blankSSI, "");

    for (int i = 0; Users[i][0][0] != 0; i++) {
            nou = i+1;
    }


    printf("Enter your username: ");
    fgets(blankName, 20, stdin);

    for(int j = 0; j<nou; j++) {


        if( strncmp(blankName, Users[j][0], strlen(blankName)-1) == 0 && strlen(blankName)-1 == strlen(Users[j][0]) ) {
                printf("Match for %d.user!\n", j);

                enterPassword:
                    printf("Please enter you password: ");
                    fgets(blankPassword, 20, stdin);

                if( strncmp(blankPassword, Users[j][1], strlen(blankPassword)-1) == 0 && strlen(blankPassword)-1 == strlen(Users[j][1]) ) {
                        printf("You have successfully logged in.\n");
                        goto begin;
                }
                else {
                        printf("Incorrect password. Please try again.\n");
                        goto enterPassword;
                }
        }
    }

    printf("No matches found.\n");
    char choice[20];
    printf("Please enter the command register for register with this name or press enter to go back.");

    fgets(choice, 20, stdin);
    if (strncmp(choice, "register", 8) == 0 ) {


    strncpy(Users[nou][0], blankName, strlen(blankName)-1);

    setPassword:

        printf("Please set a password: ");
        fgets(blankPassword, 20, stdin);

        printf("Please confirm your password: ");
        fgets(passwordConfirm, 20, stdin);

        if( strncmp(blankPassword, passwordConfirm, strlen(blankPassword)) == 0 && strlen(blankPassword) == strlen(passwordConfirm) ) {

            strncpy(Users[nou][1], blankPassword, strlen(blankPassword)-1);

            printf("You have successfully registered.\n");

        }
        else {
                printf("Passwords do not match, please try again.\n");
                goto setPassword;
        }
    }
    else {
            goto begin;
    }













    goto begin;
    return 0;

}
