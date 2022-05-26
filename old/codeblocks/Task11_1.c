#include <stdio.h>

int main()
{
    int A[] = { 0, 7, 3, 1, 4 };
    int *p;
    p = A;

    printf("1: *p           : %p\n", *p);
    printf("2: *p+2         : %p\n", *p+2);
    printf("3: *(p+2)       : %p\n", *(p+2));
    printf("4: &p           : %p\n", &p);
    printf("5: &p+1         : %p\n", &p+1);
    printf("6: p            : %p\n", p);
    printf("7: A            : %p\n", A);
    printf("8: &A[0]        : %p\n", &A[0]);
    printf("9: &A[0]+3      : %p\n", &A[0]+3);
    printf("10: A+3         : %p\n", A+3);
    printf("11: p+(*(p+4)-3): %p\n", p+(*(p+4)-3));

    printf("%d", sizeof(int));














    return 0;
}
