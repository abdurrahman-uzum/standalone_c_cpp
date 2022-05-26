#include <stdio.h>
#include <math.h>


int fac ( int number )
{
    int i;
    for ( i=number-1; i>=1; i-- )
    {
        number *= i;
    }
    return number;
}




int main()
{
    int x;
    double sin;
    int terms = 1;
    int exp;
    int n;

    printf("To calculate sin(x), enter the x in radians: ");
    scanf("%d", &x);
    printf("Enter the number of terms, (more terms will increase accuracy): ");
    scanf("%d", &n);

    for ( exp=1; terms<5; exp+=2, terms++ )
    {
        sin += terms%2==0? pow(x,exp)/-fac(exp) : pow(x,exp)/fac(exp);
    }
    printf("sin(x) = %f", sin);








    return 0;
}
