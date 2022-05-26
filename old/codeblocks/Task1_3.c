#include <stdio.h>


int main() {

    int a,b;

    printf("TASK 1 - A\t(a=5; b=++a;)\n\n");
    a=5;
    b=++a;

    printf("a=%d\tb=%d\n", a, b);
    printf("This code first increments a by one (a++) then assigns the incremented value of a to b.\n\n--------------------------\n\n");

    printf("TASK 1 - B\t(a=5; b=a++;)\n\n");

    a=5;
    b=a++;

    printf("a=%d\tb=%d\n", a, b);
    printf("This code first assigns value of a to b, then increments a by one (a++).\n\n--------------------------\n\n");

    printf("TASK 1 - C\n\n");

    printf("14 * 4 / 2 %% 4 * 7 = %d\n", 14 * 4 / 2 % 4 * 7);
    printf("Since all math operators used here (*/%%) are on the same hierarchical level, computer basically runs them left to right order.\n\n--------------------------\n\n");

    printf("TASK 1 - D\n\n");

    printf("30 + 7 / 2 - 80 %% 5 * 2 - 2 = %d\n\n", 30+7/2-80%5*2-2);
    printf("Hierarchical order between math operators are as following:  () > *,/,%% > +,- Computer executes mathematical operations accordingly. \n");
    printf("-First calculates 7/2, adds it to 30, obtains 33.5.\n");
    printf("-Then finds the remainder of 80/5 and multiplies that with 2, resulting 0. \n");
    printf("-Subtracts 0 from 33.5, finally subtracts 2 from 33.5, resulting 31.5 \n");
    printf("Reason why apparent result happened to be integer is because calculation is made with integer numbers.\n");
    printf("Also note that modulus operator works only with integers in C.\n\n--------------------------\n\n");

    printf("TASK 1 - E\n\n");

    printf("(9-4) * 2 +80 / (5%2) = %d\n", (9-4) * 2 +80 / (5%2));
    printf("As said above; order of execution is () > *,/,%% > +,-\n");
    printf("Computer first calculates parenthesis, then multiplications, divisions and modulus, and finally additions and subtractions.\n\n");






    return 0;
}
