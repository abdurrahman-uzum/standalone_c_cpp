#include <stdio.h>


int fac( int number ) {  //Be aware: this function overwrites the input argument.

    for (int i=number-1; i>=1; number *= i--) {}

    return number;
}



int main() {

    int x, n;
    double eEx = 1;

    printf("To calculate e^x: \n");
    printf("Enter the number of terms (more terms will increase accuracy) : ");
    scanf("%d", &n);
    printf("Enter the exponent of e: ");
    scanf("%d", &x);

    int i;
    for (i=1; i<=n; i++) {

        eEx += pow(x,i)/fac(i);

    }

    printf("e^%d = %f", x, eEx);







    return 0;
}
