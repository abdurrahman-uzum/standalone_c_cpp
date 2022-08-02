#include <stdio.h>
double mt1, mt2, fnl;
double average;


void main() {
    
     
     printf("Welcome to the average grade calculator\nPlease type in:\n");
     
     printf("Midterm 1: ", mt1);
     scanf("%lf", &mt1);
     
     printf("Midterm 2: ", mt2);
     scanf("%lf", &mt2);
     
     printf("Final: ", fnl);
     scanf("%lf", &fnl);
     
     average = mt1/5 + mt2/5 + 3*fnl/5;
     
     if(average - (int)average >= 0.5) { average = ceil(average); }
     else { average = floor(average); }
     
     printf("Your average grade is: %.0f\n" , average);
     
     system("PAUSE");
     
}
