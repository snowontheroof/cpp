#include "Array.hpp"
#include <iostream>

int	main(void)
{
	Array<int>	test(5);
	std::cout << "size is " << test.size() << std::endl;

	return 0;
}
