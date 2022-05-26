#include <stdio.h>

int main() {

    int a = 0;
    int b = 1;
    int c;

    printf("%d\n%d\n", a, b);

    while (c + a <= 5000) {
            c = a + b;
            a = b;
            b = c;

            printf("%d\n", c);
    }

    return 0;
}
