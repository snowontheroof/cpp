#include "../inc/easyfind.hpp"
#include <vector>
#include <deque>
#include <array>

int	main(void)
{
	std::vector<int>	test = { 1, 2, 3 };
	std::cout << easyfind(test, 12) << std::endl;

	std::deque<int>	test2 = { 9, 42, 13, -42 };
	std::cout << easyfind(test2, -49) << std::endl;

	std::array<int, 5>	test3 = { -99, 55, 13, 3, 01 };
	std::cout << easyfind(test3, -11) << std::endl;

	std::array<char, 2>	test4 = { 'a', 'f' };
	std::cout << easyfind(test4, -3) << std::endl;

	return 0;
}
