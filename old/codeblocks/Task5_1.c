#include <stdio.h>

int main() {
    int i = 1;
    for(;;) {
            printf("%d\t", i++);

            if ( i < 10 ) { break; }

    }
    return 0;
}
