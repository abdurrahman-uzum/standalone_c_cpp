#include <stdio.h>

int main() {

    int x1,x2,x3,x4,x5;

    printf("Please enter 5 numbers in order to calculate their harmonic meaning: ");
    scanf("%d%d%d%d%d", &x1, &x2, &x3, &x4, &x5);

    printf("Harmonic mean: %f", 5/( (1/(double)x1)+(1/(double)x2)+(1/(double)x3)+(1/(double)x4)+(1/(double)x5) ));


    return 0;
}
