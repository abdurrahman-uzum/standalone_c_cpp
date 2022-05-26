#include<stdio.h>

double x, y;

void main() {
     
     printf("y = 3/(5x^3 - 3x^2 + 7x - 2)\n");
     printf("To execute the function above, please enter an x value: ");
     scanf("%lf", &x);
     y = 3/(5*x*x*x - 3*x*x + 7*x - 2);
     printf("The y value for given x is: %f\n", y);
     system("PAUSE");
     
}  
