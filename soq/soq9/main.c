char * select_max(char str[]);

int main(void) {
    printf("%c\n",select_max("Hello"));

    printf("All tests passed successfully.\n");
}

char *select_max(char str[]){
    int length = strlen(str);
    if(length<1){//returns 0 if string length is less than one
        printf("Invalid string.\n");
        return 0;
    }
    char *max = str;

    for(int i=0;i<length;i++){
        if(str[i] > max){
            max = str[i];
        }
    }
    return *max;
}