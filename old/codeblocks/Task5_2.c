/*

Preliminary Assignment #5 : Task #2
Date: October 27, 2019

Code Description:
This code finds whether the entered number is a prime or not.

*/




#include <stdio.h>


int main() {

    int num;
    int prime = 1;   //Logic variable to indicate whether number is prime or not.

    printf("Please enter a number >");
    scanf("%d", &num);

    int i;
    for (i=1; i<=num; i++) {  //Checking every number from 1 to entered number.

            if ( num%i == 0 && i != 1 && i != num ) {   // If any divisors has 0 remainder other than 1 and number itself:

                    printf("It is a not prime number.\n");   // Output prime and assign 0 to prime
                    prime = 0;
                    break;
            }
    }
    if ( prime ) { printf("It is a prime number.\n"); }



    return 0;
}


