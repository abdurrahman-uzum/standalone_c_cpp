#include <stdio.h>

int i;
int numbers[5];
int hold;
int check;

int main() {

    printf("Please enter five integer numbers separated by spaces: ");
    for (i=0; i<5; i++) { scanf("%d", &numbers[i]); }

    for (i=0; check<5; i++) {
            i = i%4;

            if ( numbers[i] > numbers[i+1] ) {

                    hold = numbers[i+1];
                    numbers[i+1] = numbers[i];
                    numbers[i] = hold;
                    check = 0;
                    continue;

            }
            check++;

    }

    printf("Smallest: %d\tLargest: %d", numbers[0], numbers[4]);












    return 0;
}
