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

    strncpy(Users[nou][0], blankName, strlen(blankName)-1);

    setPassword:

        printf("Please set a password: ");
        fgets(blankPassword, 20, stdin);

        printf("Please confirm your password: ");
        fgets(passwordConfirm, 20, stdin);

        if( strncmp(blankPassword, passwordConfirm, strlen(blankPassword)) == 0 && strlen(blankPassword) == strlen(passwordConfirm) ) {

            strncpy(Users[nou][1], blankPassword, strlen(blankPassword)-1);

            printf("You have successfully registered.\n");
            nou++;
        }
        else {
                printf("Passwords do not match, please try again.\n");
                goto setPassword;
        }











    goto begin;
    return 0;

}
