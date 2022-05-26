#include <stdio.h>
int mt1, mt2, fnl;
float average;

float averageCalculator (int, int, int);
float averageCalculator(mt1, mt2, fnl){
      average = (20*mt1 + 20*mt2 + 60*fnl)/100; 
      return average;
      }

void main() {
    
     
     printf("Welcome to the average grade calculator\nPlease type in:\n");
     
     printf("Midterm 1:", mt1);
     scanf("%d", &mt1);
     
     printf("Midterm 2:", mt2);
     scanf("%d", &mt2);
     
     printf("Final:", fnl);
     scanf("%d", &fnl);
     
     int rndavrg = ceil(averageCalculator(mt1, mt2, fnl));
    
     printf("Your average is: %d\n", rndavrg);
     
     system("PAUSE");
}
