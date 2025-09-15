#include "Fixed.hpp"

int main(void)
{
	try
	{
		Fixed a;
		Fixed const b(10);
		std::cout << b.getRawBits() << std::endl;
		Fixed const c(42.42f);
		std::cout << b.getRawBits() << std::endl;
		Fixed const d(b);

		a = Fixed(1234.4321f);

		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "c is " << c << std::endl;
		std::cout << "d is " << d << std::endl;

		std::cout << "a is " << a.toInt() << " as integer" << std::endl;
		std::cout << "b is " << b.toInt() << " as integer" << std::endl;
		std::cout << "c is " << c.toInt() << " as integer" << std::endl;
		std::cout << "d is " << d.toInt() << " as integer" << std::endl;

		std::cout << "a is " << a.toFloat() << " as float" << std::endl;
		std::cout << "b is " << b.toFloat() << " as float" << std::endl;
		std::cout << "c is " << c.toFloat() << " as float" << std::endl;
		std::cout << "d is " << d.toFloat() << " as float" << std::endl;

		Fixed e(b);
		std::cout << "e is " << e.toInt() << " as integer and " << e.toFloat()
			<< " as float" << std::endl;
		e.setRawBits(256);
		std::cout << "now e is " << e.toInt() << " as integer and " << e.toFloat()
			<< " as float" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
