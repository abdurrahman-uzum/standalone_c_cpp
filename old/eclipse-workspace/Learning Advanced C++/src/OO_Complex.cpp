#include "OO_Complex.h"


std::ostream& operator<<( std::ostream& out, const Complex& c )
{
	out << "(" << c.getReal() << ","  << c.getImg() << "i)";

	return out;
}



Complex::Complex(): real(0), img(0)
{

}

Complex::Complex( double real, double img ) : real(real), img(img)
{

}


Complex::Complex( const Complex& other )
{
	real = other.real;
	img = other.img;
}

const Complex& Complex::operator=(const Complex& other )
{
	real = other.real;
	img = other.img;

	return *this;
}

