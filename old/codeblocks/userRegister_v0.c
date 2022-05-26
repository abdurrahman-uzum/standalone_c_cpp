#include<stdio.h>
#include<stdbool.h>
#include<string.h>

int choice;
char blankName[20];
char blankPassword[20];
char passwordConfirm[20];
bool match;
int countUsers = 1;

struct User {
       char name[20];
       char password[20];
       char superSecretInformation[50];
};







void main() {
     
         int nN, nP, nI;
         struct User user1;
         
         struct User bot1;
         strcpy(bot1.name, "Mahmut");
         strcpy(bot1.password, "Mahmut\0");
         strcpy(bot1.superSecretInformation, "Mahmut");   
         
         beginning:
                       
         printf("Please enter your name: ");
         fgets(blankName, 20, stdin);
         
         nN = strlen(blankName)-1;
         
         if(strncmp(blankName, bot1.name, nN) == 0) {
            printf("Please enter your password: ");
            fgets(blankPassword, 20, stdin);
            
            nP = strlen(blankPassword) - 1;
            
            if( strncmp(blankPassword, bot1.password, nP) == 0 ) { printf("Hello, %s, your super secret information is: %s\n", bot1.name, bot1.superSecretInformation); }
            else { printf("Wrong password!\n"); }
            }
         
      //new user////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            
         if(strncmp(blankName, bot1.name,nN) != 0) {
                               
           /*char str[20];
           sprintf(str, "%d", countUsers);
           
           printf("%s\n", str);
           system("PAUSE");*/
           
           
           
           strcpy(user1.name, blankName);
        
         setPassword:
                     printf("Hello, %splease set a password: ", user1.name);
                     fgets(user1.password, 20, stdin);
                     printf("Please confirm your password: ");
                     fgets(passwordConfirm, 20, stdin);
         
         if(strcmp(user1.password, passwordConfirm) == 0) { match = true; }
         else { match = false; }
         
         if(match) {
                   printf("You have succesfuly registered!\nPlease enter your super secret information: ");
                   fgets(user1.superSecretInformation, 50, stdin);
                   printf("Your super secret information is: %s", user1.superSecretInformation);
                   countUsers++;
                   }
         else { 
              printf("Passwords don't match.\n");
              goto setPassword;
              }      
       }
     system("PAUSE");
     
     goto beginning;
     
     
     
}
