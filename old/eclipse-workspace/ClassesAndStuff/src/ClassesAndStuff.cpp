#include <iostream>
using namespace std;

void change ( int &value )
{
	value = 1;
}

int main()
{
	int value = 8;

	change ( value );

	cout << value << endl;











	return 0;
}
