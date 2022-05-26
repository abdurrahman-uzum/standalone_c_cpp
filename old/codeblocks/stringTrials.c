#include<stdio.h>
#include<string.h>

int main() {
    char str1[20];
    char str2[20];
    
    strcpy(str1, "Mahmut");
    
    fgets(str2, 20, stdin);
    
    int a = strlen(str2);
    printf("%d\n", a);
    
    
    
    system("PAUSE");
    return 0;
}
