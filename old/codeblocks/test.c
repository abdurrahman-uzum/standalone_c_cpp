#include<stdio.h>

char choice[20];


int main() {

    fgets(choice, 20, stdin);

    if ( strncmp(choice, "register", 8) == 0 ) {
            printf("same");
    }
    else {
            printf("not same");
    }

    return 0;
}
