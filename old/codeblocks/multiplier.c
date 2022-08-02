#include<stdio.h>


void multiplier(int, int);
void multiplier(int x, int y) {
     printf("%d times %d is equal to %d\n", x, y, x*y);
}

void main(void) {
     int number1;
     int number2;
     
     printf("Welcome to the multiplier program, please follow the commands\n");
     sleep(400);
     printf("Please type your first number\n");
     scanf("%d", &number1);
     printf("Please type your second number\n");
     scanf("%d", &number2);
     multiplier(number1, number2);
     system("PAUSE");
}
