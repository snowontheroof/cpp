#include "Fixed.hpp"

int main(void)
{
	try
	{
		Fixed a(10);
		std::cout << "a is " << a << std::endl;
		Fixed const b(2);
		std::cout << "b is " << b << std::endl;
		Fixed const c(a * b);
		std::cout << "c is " << c << std::endl << std::endl;

		std::cout << "--------------Incrementing a--------------" << std::endl;
		std::cout << "a is " << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << "a is " << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << "a is " << a << std::endl << std::endl;

		std::cout << "--------------Decrementing d--------------" << std::endl;
		std::cout << "b is " << b << std::endl;
		Fixed d(c / b);
		std::cout << "d is " << d << std::endl;
		std::cout << d-- << std::endl;
		std::cout << "d is " << d << std::endl;
		std::cout << --d << std::endl;
		std::cout << "d is " << d << std::endl << std::endl;

		std::cout << "--------------Comparing--------------" << std::endl;
		Fixed e(a + d);
		std::cout << "e is " << e << std::endl;
		std::cout << Fixed::max(a, e) << std::endl;
		std::cout << Fixed::min(b, c) << std::endl;
		std::cout << (a < b) << std::endl;
		std::cout << (d != c) << std::endl;

		/*
		Fixed	a;
		Fixed	const b( Fixed( 5.05f ) * Fixed( 2 ) );

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;

		std::cout << b << std::endl;

		std::cout << Fixed::max( a, b ) << std::endl;
		*/
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
