#include <stdio.h>
void display();

int largest(int[], int);
int smallest(int[], int);
float Average(int[]);


int main(){
    int arr[10];
    int i;
    char operation;
    
    for(i = 0; i < 10; i++){
        printf("Input a number at index %d: ", i);
        scanf("%d", &arr[i]);
       }

    printf("Enter a choice.\n");
    printf("a. find the largest number\n");
    printf("b. find the smallest number\n");
    scanf("%c", &operation);
   
switch(operation)
    {
        case 'a':
            printf("Largest integer is %d\n", largest(arr, 10));
            break;
        case 'b':
            printf("Smallest integer is %d\n", smallest(arr, 10));
            break;
        case 'c':
            printf("The average of the array is: %.2f\n", Average(arr));
            break;
        default:
            printf("Error! operator is not correct");
        }
}
    int largest(int arr[], int n)
{
    int i;
    int max = arr[0];
    for (i = 1; i < 10; i++)
    if (arr[i] > max)
        max = arr[i];

    return max;
}
int smallest(int arr[], int n)
{
    int i;
    int small = arr[0];
    for (i = 1; i < 10; i++)
    if (arr[i] < small)
        small = arr[i];

    return small;
}
float Average(int x[10])
{
    int i;
    double avg, sum = 0;

    for(i = 0; i < 10; i++)
        sum += x[i];

    avg = sum / 10;

    return avg;
}    