#include <stdio.h>

unsigned long long fac ( int number )
{
    unsigned long long holder = number;

    int i;
    for ( i=holder-1; i>=1; i-- )
    {
        holder *= i;
    }
    return holder;
}

unsigned long long pow ( int base, int exponent )
{
    unsigned long long holder = base;

    int i;
    for ( i=1; i<exponent; i++ )
    {
        holder *= base;
    }
    return holder;
}






int main()
{
    double sin;
    int terms = 1;

    int x, n, exp;

    printf("To calculate sin(x), enter x in radians: ");
    scanf("%d", &x);

    printf("Enter n: ");
    scanf("%d", &n);


    for ( exp=1; terms<=(n+1)/2; exp+=2, terms++ )
    {
        sin += terms%2 == 0 ? pow(x,exp)/(-1.0*fac(exp)) : pow(x,exp)/(1.0*fac(exp));
    }

    printf("%f", sin);
















    return 0;
}





















