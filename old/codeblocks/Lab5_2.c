#include <stdio.h>



int fac( int number ) {  //Be aware: this function overwrites the input argument.

    for (int i=number-1; i>=1; number *= i--) {}

    return number;
}





int main() {

    int combination, n, k;

    printf("Please type the combination you want to calculate (n k) : ");
    scanf("%d%d", &n, &k);

    combination = fac(n)/(fac(k)*fac(n-k));

    printf("%d", combination);



    return 0;
}
