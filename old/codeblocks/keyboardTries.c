#include <stdio.h>

int c;

int main() {


    c = getch();
    printf("%d", c);

    if ( c == 49 ) {
            printf("Yeeey");
    }
    else if ( c == 48 ) {
            printf("Nooooo");
    }
    else {
            printf("wtf!?");
    }


    return 0;
}

