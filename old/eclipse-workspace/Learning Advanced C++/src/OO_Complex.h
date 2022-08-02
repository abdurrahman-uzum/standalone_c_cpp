#ifndef OO_COMPLEX_H_
#define OO_COMPLEX_H_

#include <iostream>




class Complex
{

	private:
		double real;
		double img;

	public:
		Complex();
		Complex( double real, double img );
		Complex( const Complex& other );
		const Complex& operator=(const Complex& other );

		double getReal() const { return real; };
		double getImg() const { return img; };
};


std::ostream& operator<<( std::ostream& out, const Complex& c );





#endif /* OO_COMPLEX_H_ */
