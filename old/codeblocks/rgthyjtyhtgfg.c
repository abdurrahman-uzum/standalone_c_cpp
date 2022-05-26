#include <stdio.h>
#include <stdlib.h>
#include <string.h>


FILE *fptr;

char c;
int nLine;

int numberOfLines() {
    fptr = fopen("file.txt", "r");
        while (1) {
                c = fgetc(fptr);

                if(c=='\n') { nLine++; continue; }
                if(isalpha(c)==0 && isdigit(c)==0) { break; }

        }
    fclose(fptr);

        return nLine+1;
    }

int main() {
/*
    fptr = fopen("file.txt", "r");
        for (int i=0; i<1000; i++)  {
                c = fgetc(fptr);
                printf("%c", c);
                if(c==' ') {
                        nLine++;
                }






        }*/



        fptr = fopen("file.txt", "r");
        while (1) {
                c = fgetc(fptr);

                if(c=='\n') { nLine++; continue; }
                if(isalpha(c)==0 && isdigit(c)==0) { break; }

        }

        fclose(fptr);

        printf("%d", nLine);














    return 0;

}

