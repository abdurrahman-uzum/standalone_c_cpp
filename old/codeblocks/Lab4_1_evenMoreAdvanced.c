#include <stdio.h>

int i;
int *numbers;
int hold;
int check;
int n;

int main() {
    numbers = (int*)malloc(sizeof(int)+1);

    printf("Please enter integer numbers separated by spaces: ");

    for (i=0; numbers[i]!= EOF; i++) {


            scanf("%d", &numbers[i]);
            numbers = (int *)realloc(numbers, (i+2)*sizeof(int));

    }




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
