#include <stdio.h>

unsigned long long fac ( const int number )  // unsigned long long because why not? xD
{
    int i;
    unsigned long long holder = number;

    for ( i=holder-1; i>=1; i-- )
    {
        holder *= i;
    }
    return holder;
}


unsigned long long pow ( const int base, const int exponent )
{
    unsigned long long holder = base;

    int i;
    for ( i=1; i < exponent; i++ )
    {
        holder *= base;
    }

    return holder;
}




int main()
{
    int x, exp, n;
    double sin;
    int terms = 1;

    printf("To calculate sin(x), enter the x in radians: ");
    scanf("%d", &x);
    printf("Enter the number of terms, (more terms will increase accuracy): ");
    scanf("%d", &n);

    for ( exp=1; terms<=(n+1)/2; exp+=2, terms++ )
    {
        sin += terms%2==0 ? pow(x,exp)/(-1.0*fac(exp)) : (1.0*pow(x,exp))/fac(exp);
    }
    printf("sin(x) = %f", sin);








    return 0;
}
