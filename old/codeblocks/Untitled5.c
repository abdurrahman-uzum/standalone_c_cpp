#include<stdio.h>
#include<string.h>
#include<stdbool.h>

char blankName[20];
char blankPassword[20];
char blankSSI[20];

char Users [][3][20] = {
                    "username", "password", "secret"
                    "Ahmet", "Ahmet", "Ahmet"
                       };

int n;
char user[20];

int main() {
    for (int i = 0; i<=20; i++) {
            printf("%c", Users[0][0][i]);

            user[i] = Users[0][0][i];

                if(Users[0][0][i] == '\0') {
                        printf("/end/");
                        break;
                }
    }
    printf("%s", user);

    return 0;

}
