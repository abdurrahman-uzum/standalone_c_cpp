#include<stdio.h>
#include<string.h>
#include<stdbool.h>

char blankName[20];
char blankPassword[20];
char blankSSI[20];

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



bool Match(int a, int b, char c[20]) {

    n = Length(a, b);
    bool match;


    for (i=0; i<=20; i++) {
            if(i == n) { break; }
            if( c[i] == Users[a][b][i] ) { match = true; continue; }

            match = false;
            break;

    }
    return match;
}



int main() {

    begin:
    nou = 2;

    printf("Enter your name: ");
    fgets(blankName, 20, stdin);

    int j = 0;


        point1:

        n = Length(j, 0);

        for (i=0; i<20; i++) {

                if(i == n) { break; }
                if( blankName[i] == Users[j][0][i] ) { match = true; continue; }

                printf("Not matching for %d .user.\n", j+1);
                match = false;
                break;

        }
        if(match) {
            printf("Matching for: %d .user\n", j+1);
        }

        j++;

        if (j <= nou-1) { goto point1; }

        printf("End.");


    return 0;

}
