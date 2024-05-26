int main ( void )
{
    int arr0[0] = {};

    arr0[5] = 1;

    for ( int i=0; i < 10000000; i++ )
    {
        arr0[i] = i;
    }


    return 0;
}