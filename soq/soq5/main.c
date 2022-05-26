#include<stdio.h>
#include<math.h>
#include<string.h>

#define PI 3.14 // We define pi number with this code.

int main() {
    printf(" Welcome to the geometric shapes calculator. \n (Press the number you want to operate from 1 to 9.) ");
    char lastChoice[30];

    do {
        printf("\n Please choose the geometric shapes you want to calculate");
        printf("\n GEOMETRIC SHAPES \n 1-Square \n 2-Triangle \n 3-Rectangle \n 4-Parallelogram \n 5-Rhombus \n 6-Circle \n 7-Trapezoid \n");
        int choice1;
        scanf("%d", &choice1);
        if (choice1 > 7 || choice1 < 1) {
            printf("\n You chose wrong operate.");
            printf("\n Do you want to do calculation ? \n (Please press y if you want to continue to calculation)");
            scanf("%s", lastChoice);
        }

        if (choice1 == 1) {
            printf("Please choose the measurement you want to calculate. \n ");
            printf("\n 1-Perimeter \n 2-Area \n 3-Volume \n 4-All of them \n");
            int choice2;
            scanf("%d", &choice2);
            if (choice2 == 1) {
                printf("Please write the length of edge. \n");
                float squareEdge;
                scanf("%f", &squareEdge);
                printf("Perimeter of the square : %.2f", 4 * squareEdge);
            }
            if (choice2 == 2) {
                printf("Please write the length of edge. \n");
                float squareEdge;
                scanf("%f", &squareEdge);
                printf("Area of the square : %.2f", squareEdge * squareEdge);
            }
            if (choice2 == 3) {
                printf("2D geometric shapes have not volume. \n");
                printf("\n Do you want to do calculation ? \n (Please press y if you want to continue to calculation.)");
                scanf("%s", lastChoice);
              }
       }
     }while (strcmp(lastChoice, "y")==0);

     return 0;
}