#include <stdio.h>

int mt1, mt2, fnl;

void main() {
     printf("Welcome to the average grade calculator!\nPlease type in:\nMidterm 1: ");
     scanf("%d", &mt1);
     printf("Midterm 2: ");
     scanf("%d", &mt2);
     printf("Final: ");
     scanf("%d", &fnl);
     
     int average = (20*mt1 + 20*mt2 + 60*fnl)/100;
     
     printf("Your average is: %d\n", average);
     
     system("PAUSE");
}
     
