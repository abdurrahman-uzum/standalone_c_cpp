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

int existingUser;






void Register() {



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


void LogIn(char name[], char password[], int check) {  //call with the following arguments: blankName, blankPassword, existingUser

     for(int j = 0; j<nou; j++) {


        if( strncmp(name, Users[j][0], strlen(name)-1) == 0 && strlen(name)-1 == strlen(Users[j][0]) ) {
                printf("Match for %d.user!\n", j);
                existingUser = 1;

                enterPassword:
                    printf("Please enter you password: ");
                    fgets(password, 20, stdin);

                if( strncmp(password, Users[j][1], strlen(password)-1) == 0 && strlen(password)-1 == strlen(Users[j][1]) ) {
                        printf("You have successfully logged in.\n");
                        break;
                }
                else {
                        printf("Incorrect password. Please try again.\n");
                        goto enterPassword;
                }
        }
    }
}







int main() {


    while(1) {


    existingUser = 0;
    strcpy(blankName, "");
    strcpy(blankPassword, "");
    strcpy(blankSSI, "");

    for (i = 0; Users[i][0][0] != 0; i++) {
            nou = i+1;
    }


    printf("Enter your username: ");
    fgets(blankName, 20, stdin);

    LogIn(blankName, blankPassword, existingUser);



    printf("%d", existingUser); //TEST CODE LINE

    if(existingUser != 1) {
        printf("No matches found.\n");
        char choice[20];
        printf("Please enter the command register for register with this name or press enter to go back: ");

        fgets(choice, 20, stdin);
        if (strncmp(choice, "register", 8) == 0 ) {

            Register();
        }
    }











    }

    return 0;

}
