#include <stdio.h>
#include <string.h>
void framed(const char *text, int width) 
{
    int i, j = 0,k, count = 0;

    // Drawing upper bound
    for (i = 0; i < width; i++)
    {
        printf("*");
    }
    printf("\n");


    while (text[j] != '\0') 
    {
        count++;

        // Left bound
        if (count == 1)
        {
            printf("* ");
        }

        printf("%c", text[j]);
        j++;
        
        if (count + 5 > width) 
        {
            printf(" *");
            printf("\n");
            count = 0;
        }

        if (j == strlen(text))
        {
            for (i = 0; i < width-count-3; i++)
            {
                printf(" ");
            }
        }
        
    }
    printf("*\n");

    for (i = 0; i < width; i++)
    {
        printf("*");
    }
}

int main() 
{
    const char text[] = "This is word with four characters";
    int width = 20;
    framed(text, width);
    return 0;
}