#include <stdio.h>

int main()
{
    //Declaration of t:
    int t [3][2];

    //t has 3 rows and 2 columns, in total, 6 elements.

    //Names of elements in 3rd row are: t[2][0] and t[2][1].

    //This part will initialize each element to 0:
    for ( int i=0; i<3; i++ )
    {
        for ( int j=0; j<2; j++ )
        {
            t[i][j] = 0;
        }
    }

    return 0;
}
