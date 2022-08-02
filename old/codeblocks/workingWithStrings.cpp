#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

string Stack[100] = "\0";

string ways;



string stack ( string command, string input )
{
    static int lineHolder = 0;

    if ( command == "pop" )
    {
        return Stack[(lineHolder--)-1];

    }

    else if ( command == "push" )
    {
        Stack[lineHolder++] = input;
        return "0";
    }
}



int main()
{
    //stack ( "push", "elma" );

    ways = "armut";

    stack("push", ways);

    string holder = stack("pop","");

    cout << holder << endl;





























    return 0;
}
