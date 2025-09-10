#include "../inc/Array.hpp"
#include <iostream>

int	main(void)
{
	try
	{
		Array<int>	test(5);
		std::cout << "size is " << test.size() << std::endl;
		test[1] = 42;
		std::cout << test[2] << std::endl;
		std::cout << test[1] << std::endl;
		std::cout << test[9] << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
