#include <stdio.h>

int main () {

    while(1) {

    int value;

    printf("Value: ");
    scanf("%d", &value);

    printf("%s\n", value>40 ? "Greater" : "Less");


    }


    return 0;
}
