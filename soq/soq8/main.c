#include<stdio.h>

struct Fraction { int x1, x2; };

void function(struct Fraction p, int *d)
{
p.x1=d[0];
p.x2=d[1];
}

int main()
{

struct Fraction frac;
int d[2];
for(int i=0;i<2;i++)
{
    scanf("%d",&d[i]);
}
function(frac,d);
printf("%d/%d",frac.x1,frac.x2);
return 0;
}