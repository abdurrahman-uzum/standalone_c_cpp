#include <stdio.h>


char* function()
{
	char string[10] = "elma";
	return string;
}

int main()
{
	char* string = function();



	printf("%s", string);
	return 0;
}
