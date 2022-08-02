#include <stdio.h>

int a, b, c;

int main() {

    printf("Please enter three integer values: ");
    scanf("%d%d%d", &a, &b, &c);

    if ( a<b+c && b<a+c && c<a+b && a>abs(b-c) && b>abs(a-c) && c>abs(a-b) ) {
            printf("%d,%d and %d can form sides of a triangle.\n", a,b,c);

            if ( a*a == b*b + c*c || b*b == a*a + c*c || c*c == a*a + b*b ) {
                    printf("This triangle will be a right angle triangle.\n", a,b,c);
            }
    }
    else {
            printf("%d,%d and %d can not form sides of a triangle.\n", a,b,c);
    }

    return 0;
}
