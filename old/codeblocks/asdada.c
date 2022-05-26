#include <stdio.h>

void main() {
     
     char str1[5];
     char str2[5];
     
     strcpy(str2, "Mahmut");
     fgets(str1, 20, stdin);
     
     printf("%d\n", strcmp(str2, str1));
     
     system("PAUSE");
     }
     
     
