#include "easyfind.hpp"
#include <vector>
#include <deque>

int	main(void)
{
	std::vector<int>	test = { 1, 2, 3 };
	std::cout << easyfind(test, 12) << std::endl;

	std::deque<int>		test2 = { 9, 42, 13, -42 };
	std::cout << easyfind(test2, -49) << std::endl;

	return 0;
}