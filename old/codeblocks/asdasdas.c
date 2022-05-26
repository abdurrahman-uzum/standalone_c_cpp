#include<stdio.h>

void main() {
     char name[20];
     int password;
     
     asdf:
     printf("Please enter your password: ");
     scanf("%d", &password);
     
     if(password == 123) {
                 printf("You have successfuly logged in\n");
                 }
                 else {
                      goto asdf;
                      }
                      
                    
                    
    
    
    
    
     system("PAUSE");
}
     
