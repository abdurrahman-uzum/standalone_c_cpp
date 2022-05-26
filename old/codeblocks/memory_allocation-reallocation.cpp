#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* decisions;

    int dsize = 1;

    decisions = (int*)malloc(0*sizeof(int));

    decisions[0] = 8;

    for ( int i=0; i<dsize; i++ )
    {
        printf("%d\n", decisions[i]);
    }
    printf("/END");
    system("pause");

    printf("\n\n");

    dsize++;

    decisions = realloc(decisions, dsize * sizeof(int));

    decisions[1] = 9;

    for ( i=0; i<dsize; i++ )
    {
        printf("%d\n", decisions[i]);
    }
    printf("/END");
    system("pause");

    printf("\n\n");

    dsize--;

    decisions = realloc(decisions, dsize * sizeof(int));

    for ( i=0; i<dsize; i++ )
    {
        printf("%d\n", decisions[i]);
    }
    printf("/END");
















    return 0;
}
