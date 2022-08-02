#include <stdio.h>


int main() {

    int a,b;

    //---------------------
    a=5;
    b=++a;

    printf("a=%d\tb=%d\n", a, b);
    printf("This code first increments a by one (a++) then assigns the incremented value of a to b.\n\n");

    //---------------------

    a=5;
    b=a++;

    printf("a=%d\tb=%d\n", a, b);
    printf("This code first assigns value of a to b, then increments a by one (a++).\n\n");

    //---------------------

    printf("14 * 4 / 2 %% 4 * 7 = %d\n", 14 * 4 / 2 % 4 * 7);
    printf("Since all math operators used here (*/%%) are on the same hierarchical level, computer basically runs them left to right order.\n\n");

    //---------------------
    int calc = 30 + 7 / 2 – 80 % 5 * 2 - 2;
    //printf("30 + 7 / 2 – 80 %% 5 * 2 - 2 = %d", calc);




    return 0;
}
