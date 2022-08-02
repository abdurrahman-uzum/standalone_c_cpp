#include <stdio.h>
#include <string.h>

int num;
int rangeBottom, rangeTop;
int guess;
char command[10];
int cont;
int tries;

int main() {

    printf("Pick a number for computer to guess and type a range in which this number exists: ");
    scanf("%d%d", &rangeBottom, &rangeTop);


    do {
            guess = (rangeBottom + rangeTop)/2;

            printf("My guess is: %d\n", guess);

            requestCommand:

            printf("Please enter one of these commands: correct, goBigger, goSmaller : ");
            scanf("%s", command);

            if ( !strcmp(command, "goBigger") ) {

                    rangeBottom = guess;
                    cont = 0;
                    tries++;

            }
            else if ( !strcmp(command, "goSmaller") ) {

                     rangeTop = guess;
                     cont = 0;
                     tries++;

            }
            else if ( !strcmp(command, "correct") ) {

                    printf("Yeeey!\n");
                    cont = 1;

            }
            else {
                    printf("Invalid code, please try again.\n");
                    goto requestCommand;
            }

    }while(!cont);

    printf("Computer guessed the correct number with %d tries.", tries);




    return 0;
}
