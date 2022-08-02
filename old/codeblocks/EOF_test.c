#include <stdio.h>
#include <string.h>

FILE *fptr;
char x;

int main() {
    fptr = fopen("file2.txt", "r");


    while (x!=EOF) {

        x = getc(fptr);

        printf("%c", x);
    }

    printf("END");






    return 0;
}
