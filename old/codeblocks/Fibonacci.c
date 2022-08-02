#include<stdio.h>

int main() {
    int Fibonacci[50] = {0, 1};

    for (int i=0; Fibonacci[i] <= 5000; i++) {

            printf("%d\n", Fibonacci[i]);

            Fibonacci[i+2] = Fibonacci[i+1] + Fibonacci[i];
    }

    return 0;
}
