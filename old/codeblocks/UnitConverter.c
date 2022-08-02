#include<stdio.h>
double km, kg, C, mi, lbs, F;
int pref;

void main() {
     printf("Welcome to the UnitConventer.\n");
     
     beginning:
     printf("Please enter 1, 2, or 3 in order to convert distance, weight, temparature: ");
     
     scanf("%d", &pref);
     
     switch (pref) {
                  case 1:
                       printf("Please enter distance in kilometers: ");
                       scanf("%lf", &km);
                       mi = km*0.6214;
                       printf("%.2f kilometers = %.2f miles\n", km, mi);
                       system("PAUSE");
                       break;
                  
                  case 2: 
                       printf("Plesae enter weight in kilograms: ");
                       scanf("%lf", &kg);
                       lbs = kg*2.205;
                       printf("%.2f kilograms = %.2f pounds\n", kg, lbs);
                       system("PAUSE");
                       break;
                  
                  case 3:
                       printf("Please enter temparature in Celcius: ");
                       scanf("%lf", &C);
                       F = (9*C)/5 + 32;
                       printf("%.2f Celcius = %.2f Fahrenheit\n", C, F);
                       system("PAUSE");
                       break;
                  
                  default:
                       printf("Invalid choice, please try again\n");
                       system("PAUSE");
                       break;
                  }
                  goto beginning;
                  
}
