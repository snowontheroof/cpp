#include "iter.hpp"
#include <iostream>

void	print(int nb)
{
	std::cout << nb << std::endl;
}

void	upcase(char c)
{
	c -= 32;
	std::cout << c << std::endl;
}

int	main(void)
{
	int	array[] = { 1, 2, 3, 4, 5 };
	iter(array, 5, print);

	std::cout << "\n-----\n";

	char	other[] = { 'j', 'i', 'h', 'u', 'u' };
	iter(other, 5, upcase);

	return 0;
}
