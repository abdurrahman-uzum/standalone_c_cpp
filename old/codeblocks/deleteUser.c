


/// file.txt content:
/*
username
password
secret
abdurrahman
1234
elma is a nice fruit
bot1
bot1pass
info
bot2
bot2pass
info2
bot3
bot3pass
info3
mahmut
12345678
ehuehuehue
botbot
botbot
botbot
thisisatest
test
testInfo
letstryagain
testagain
thisissecondtest
somethingelse
1234
shitgonnahappen
somethingelse2
4321
shitalwayshappens
somethingelse3
9876
shitmayhappen
abdurrahman2
4321
I hate apples.
abdurrahman3
12344321
fuck you all.
hello
1234
no i won't.
testingRegister
1234
i am testing

*/




#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<windows.h>

#define SIZE 1000

FILE *fptr;

char receiveString[SIZE];

char blankName[SIZE];
char blankPassword[SIZE];

int i,j;

int nou;

int howManyLines;

char c;


char putString[SIZE];





char *access(const int userNumber, const int getWhat) {

    fptr = fopen("file3.txt", "r");

    if ( fptr == NULL ) {
            printf("Failed to open file.");
            exit(-1);
    }
    else {

        int count = 3*(userNumber - 1) + getWhat;

        int i;
        for (i=1; ; i++) {

                fgets (receiveString, SIZE, fptr);
                if ( i == count ) { break; }

                strcpy(receiveString, "");
        }

        fclose(fptr);
        return receiveString;
    }

}




int numberOfLines() {

    fptr = fopen("file3.txt", "r");
    if( fptr == NULL ) {
            printf("Failed to open file.");
            exit(-1);
    }
    else {

        while (1) {
                c = fgetc(fptr);

                if(c=='\n') { howManyLines++; continue; }
                if( c == EOF ) { break; }
        }

        fclose(fptr);
        return howManyLines;
    }
}





int ExistingUser( const char name[], const int numberOfUsers ) {

    for( j = 1; j<nou; j++ ) {

        if ( !strncmp(name, access(j, 1), strlen(name)-1 ) && strlen(name) == strlen(access(j,1)) ) {
                return j;
        }
    }

    return 0;
}











int deleteUser(const int userNumber) {

    int length = strlen(access(userNumber,1)) + strlen(access(userNumber,2)) + strlen(access(userNumber,3))+1;

    fptr = fopen("file3.txt", "r+");

    if ( fptr == NULL ) {
            printf("Failed to open file.");
            exit(-1);
    }
    else {

        int i;
        for (i=1; i!=(3*(userNumber - 1)+1); i++) {

                fgets (receiveString, SIZE, fptr);
        }

        int pos = ftell(fptr);

        fseek( fptr, pos, SEEK_SET);

        for (i=0; i<length; i++) {
                fprintf(fptr, "%c", NULL);
        }

        fseek( fptr, pos, SEEK_SET);

        fprintf(fptr, "%c\n%c\n%c", '*', '*', '*');



        fclose(fptr);


    }



    return 1;
}





int main() {

    deleteUser(2);






























    return 0;
}

















