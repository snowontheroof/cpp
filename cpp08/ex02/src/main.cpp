#include "../inc/MutantStack.hpp"

int	main(void)
{
	MutantStack<int>	test;

	test.push(5);
	test.push(10);

	MutantStack<int>::iterator	it = test.begin();

	return 0;
}