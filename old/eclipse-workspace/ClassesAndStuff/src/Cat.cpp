#include <iostream>
#include "Cat.h"

using namespace std;

Cat::Cat()
{
	cout << "Cat created" << endl;
	happy = true;
	name = "someCatName";
}

Cat::~Cat()
{
	cout << "Cat destroyed" << endl;
}

void Cat::speak()
{
	if ( happy )
	{
		cout << "meow :)" << endl;
	}
	else
	{
		cout << "meow :(" << endl;
	}
}

void Cat::jump()
{
	cout << "*jumps*" << endl;
}

string Cat::getName()
{
	return "Cat's name is: " + name;
}

void Cat::setName( string givenName )
{
	name = givenName;
}























