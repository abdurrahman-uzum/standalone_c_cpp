#include<stdio.h>
#include<string.h>
#include<stdbool.h>

char blankName[20];
char blankPassword[20];
char blankSSI[20];

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



int main() {
    begin:
    nou = 2;

    printf("Enter your name: ");
    fgets(blankName, 20, stdin);

    n = Length(0, 0);


    for (i=0; i<=20; i++) {
            if(i == n) { break; }
            if( blankName[i] == Users[0][0][i] ) { continue; }
            else {
                    printf("Not matching.\n");
                    goto begin;
            }
    }
    printf("Matching.\n");

    /*for (i = 0; i<=20; i++) {
            Users[nou][0][i] = blankName[i];
            if(blankName[i] == '\0') { break; }

    }*/





    return 0;

}
