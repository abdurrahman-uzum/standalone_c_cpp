#include<stdio.h>
int pref;
double km, mi, kg, lbs, C, F;

int main() {
    
    beginning:
              
              printf("Please type 1, 2 or 3 in order to convert distance, weight and temparature: ");
              scanf("%d", &pref);
    
    
              switch(pref) {
                           case 1: 
                                printf("Please enter distance in kilometers: ");
                                scanf("%lf", &km);
                                mi = km*0.6214;
                                printf("%f km = %f mi\n", km, mi);
                                system("Pause");
                                break;
                                
                           case 2:
                                printf("Please enter weight in kilograms: ");
                                scanf("%lf", &kg);
                                lbs = kg*2.205;
                                printf("%f kg = %f lbs\n", kg, lbs);
                                system("PAUSE");
                                break;
                                
                           case 3:
                                printf("Please enter temparature in Celcius: ");
                                scanf("%lf", &C);
                                F = (9*C)/5 + 32;
                                printf("%f C = %f F\n", C, F);
                                system("PAUSE");
                                break;
                                
                           default: 
                                    printf("Invalid choice! \n");
                                    break;
                           }
                           goto beginning;
                           }
                                
