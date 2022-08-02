#include <stdio.h>
#include <iostream>
void print ( const char* input )
{
    printf(input);
}


int main()
{
    std::string someString = "elma";

    print(someString.c_str());













    return 0;
}
