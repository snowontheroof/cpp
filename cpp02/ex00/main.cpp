#include "Fixed.hpp"

int	main(void)
{
	try
	{
		Fixed	a;
		Fixed	b(a);
		Fixed	c;

		c = b;
		std::cout << a.getRawBits() << std::endl;
		std::cout << b.getRawBits() << std::endl;
		std::cout << c.getRawBits() << std::endl;
		a.setRawBits(42);
		std::cout << a.getRawBits() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
