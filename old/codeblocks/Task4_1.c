/*
    PRELIMINARY ASSIGNMENT 4 Task 1
    Abdurrahman ÜZÜM 2019502099

    October 21th, 2019

    Code Description: This code requests two inputs from user and
    print whether their sum is positive or negative.
*/


#include <stdio.h> //Including C Standard Input/Output Library

int num1, num2;

int main() {

    printf("Please enter two numbers separated by space: ");
    scanf("%d%d", &num1, &num2);   //Assigning two values to num1 and num2 variables.


    if ( (num1 + num2) == 0 ) {   //Checking whether sum is 0.
            printf("Sum of these numbers is 0.\n");
    }
    else {  //Checking whether sum is positive or negative and printing appropriate statement.
        printf("Sum of these numbers is %s", num1 + num2 > 0 ? "positive.\n" : "negative.\n" );
    }




    return 0;  //Indication of program terminated normally.
}
