#ifndef CAT_H_
#define CAT_H_
#include <iostream>
using namespace std;

class Cat
{
private:
	bool happy;
	string name;

public:
	Cat();
	~Cat();

	string getName();
	void setName( string );

	void speak();
	void jump();
};





#endif /* CAT_H_ */
