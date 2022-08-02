#include <stdio.h>
#include <math.h>



int main()
{
    int number = 79;
    int even;
    even = number%2 == 0 ? 1 : 0;

    printf("79 is an %s number. (used %% operator)", even? "even" : "odd");
    return 0;

}
