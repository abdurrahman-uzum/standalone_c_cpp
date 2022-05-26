#include <stdio.h>

int main () {

    int i = -3;
    int j = 3;
    int k = 0;
    int m;

    m = ++i && ++j && ++k;
    printf("TASK 3-A\n\n");
    printf("i=%d, j=%d, k=%d, m=%d\n", i, j, k, m);
    printf("The code (m = ++i && ++j && ++k;) increments initial values of i, j, and k, then sets a double 'and' operator and assigns the result to m.\n");
    printf("As far as i understand, any number but 0 counts as true in computer logic.\n");
    printf("So -2 && 4 && 1 is equivalent to 1&&1&&1 thus returns logic 1.\n");
    printf("Note that 'and' operator returns 1 only if both operands are true");


    printf("\n\n--------------------\n\n");



    int x = 12, y=7, z;

    z = x!=4 || y==2;

    printf("TASK 3-B\n\n");
    printf("z = %d\n", z);

    printf("On the code (z = x!=4 || y==2;) with x=12 and y=7, x!=4 statement is true, and y==2 statement is false.\n");
    printf("Thus the 'or' operator returns logic 1.\n");
    printf("Note that 'or' operator returns logic 1 if any of the operands is true.\n\n\n");




    return 0;

}


