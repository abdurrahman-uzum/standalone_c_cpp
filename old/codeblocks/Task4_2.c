/*
    PRELIMINARY ASSIGNMENT 4 Task 2
    Abdurrahman ÜZÜM 2019502099

    October 21th, 2019

    Code Description: This code takes user input of grades based on points
    and prints the equivalent letter grade.
    Note: I have no idea why i have use switch while it's clearly a horrible way to go in this case...

*/

#include <stdio.h>  //Including C Standard Input/Output Library

int grade;

int main() {

    printf("Please enter your grade in points out of 100: ");
    scanf("%d", &grade);  //assigning the value entered by user to the variable "grade".

    switch ((int)grade/5) {   //Working with grade/5 makes the switch ten times shorter while still working.
        case 20:
            printf("AA");
            break;
        case 19:
            printf("AA");
            break;
        case 18:
            printf("AA");
            break;
        case 17:
            printf("BA");
            break;
        case 16:
            printf("BB");
            break;
        case 15:
            printf("CB");
            break;
        case 14:
            printf("CC");
            break;
        case 13:
            printf("DC");
            break;
        case 12:
            printf("DD");
            break;
        case 11:
            printf("FD");
            break;
        default:
            printf("FF");
            break;
    }




    return 0; //Indication of program terminated normally.
}


