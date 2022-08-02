#include<stdio.h>
#include<string.h>
#include<stdbool.h>



bool match;

char blankName[20];

int nou;

char Users [][3][20] = {
                        "username", "password", "secret",
                        "Ahmet", "Ahmet", "Ahmet",
                        "asdasdasd",
                       };

int main() {

    for (int i = 0; Users[i][0][0] != 0; i++) {
            nou = i;
    }
    printf("%d", nou);






    return 0;

}
