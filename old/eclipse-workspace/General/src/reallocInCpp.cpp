#include <stdio.h>
#include <string>
int main()
{
	int size = 5;
	char* string = new char[size];

	string = "elma";

	printf("%s\n", string );

	char* buffer = new char[size];
	memcpy( buffer, string, size );

	delete[] string;
	string = nullptr;

//	string = new char[++size];
//
//	memcpy( string, buffer, size );
//
//	string = "elmaarmutportakal";
//
//	printf("%s\n", string);











	return 0;
}
