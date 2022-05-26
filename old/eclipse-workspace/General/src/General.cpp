#include <iostream>
using namespace std;


class Animal
{
private:
	string name;

public:
	Animal()
	{
		cout << "Animal Created." << endl;
	}

	~Animal()
	{
		cout << "Animal destroyed." << endl;
	}

	void setName ( string name )
	{
		this->name = name;
	}

	void speak()
	{
		cout << "My name is: " << name << endl;
	}
};





int main()
{
	Animal *pAnimal = new Animal[26];

	string NAME = "animal";
	char ID = 'A';

	for ( int i=0; i < 26; i++, ID++ )
	{
		pAnimal[i].setName(NAME + ID);
		pAnimal[i].speak();
	}

	delete[] pAnimal;




















	return 0;
}







