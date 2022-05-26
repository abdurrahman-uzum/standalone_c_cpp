#include <stdio.h>



int function() {

    printf("This is a function which will return 1.\n");


    return 1;
}





int main() {

    if ( function() ) {
            printf("This is an if loop within which a function being called.\n");
    }






    return 0;
}
