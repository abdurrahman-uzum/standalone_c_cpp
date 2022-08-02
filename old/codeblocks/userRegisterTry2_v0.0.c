#include<stdio.h>
#include<string.h>
#include<stdbool.h>

char blankName[20];
char blankPassword[20];
char passwordConfirm[20];

int nou = 2;

char Users[][3][20] = {
                    "username", "password", "secret",
                    "Ahmet", "Ahmet", "Ahmet",
                                                    };

void Register() {

    strcmp(Users[nou][0], blankName);
    printf("/begin/%s/end/", Users[2][0]);

    setPassword:

    printf("Please set a password: ");
    scanf("%s", &blankPassword);
    printf("Please confirm your password: ");
    scanf("%s", &passwordConfirm);

    if(strcmp(blankPassword, passwordConfirm) == 0) {
            printf("Confirmed.\n");
    }
    else {
            printf("Not confirmed, please try again.\n");
            goto setPassword;
    }
}




int main() {

    fgets(blankName, 20, stdin);
    strncmp(Users[2][0], blankName, strlen(blankName));
    printf("%s", Users[2][0]);

    setPassword:

    printf("Please set a password: ");
    scanf("%s", &blankPassword);
    printf("Please confirm your password: ");
    scanf("%s", &passwordConfirm);

    if(strcmp(blankPassword, passwordConfirm) == 0) {
            printf("Confirmed.\n");
    }
    else {
            printf("Not confirmed, please try again.\n");
            goto setPassword;
    }

    return 0;
}
