#include<stdio.h>

int main(){

    int a = 25;
    int *p = &a; // just stored the address of a  but did'nt use it see the difference
    printf("%d %d %d\n",--a,--a,--a);
    return 0;
}