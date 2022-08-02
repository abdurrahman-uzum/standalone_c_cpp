#include <stdio.h>

int i;
int *numbers;
int hold;
int check;
int n;

int main() {

    printf("How many numbers you want to enter? ");
    scanf("%d", &n);

    numbers = (int*)malloc(n*sizeof(int));

    printf("Please enter %d integer numbers separated by spaces: ", n);
    for (i=0; i<n; i++) { scanf("%d", &numbers[i]); }

    for (i=0; check<n; i++) {
            i = i%(n-1);

            if ( numbers[i] > numbers[i+1] ) {

                    hold = numbers[i+1];
                    numbers[i+1] = numbers[i];
                    numbers[i] = hold;
                    check = 0;
                    continue;

            }
            check++;

    }

    printf("Smallest: %d\tLargest: %d", numbers[0], numbers[n-1]);

    free(numbers);












    return 0;
}
