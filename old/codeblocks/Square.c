#include<stdio.h>

void square(int);
void square(int x) {
     printf("The square of %d = %d\n", x, x*x);
}

void main() {
     int number;
     printf("Enter a number to square it.\n");
     scanf("%d", &number);
     square(number);
     system("PAUSE");
}
     
