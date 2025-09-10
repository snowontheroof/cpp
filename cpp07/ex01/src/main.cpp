#include "../inc/iter.hpp"
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

void	print_ptr(int* ptr)
{
	std::cout << "Pointer address: " << ptr << std::endl;
	std::cout << "Value of variable pointed by pointer: " << *ptr << std::endl;
}

void	test1(void)
{
	std::cout << "\n" << std::string(10, '-') << "Test 1: int array"
		<< std::string(10, '-') << std::endl;

	int	array[] = { 1, 2, 3, 4, 5 };
	iter(array, 5, print);
}

void	test2(void)
{
	std::cout << "\n" << std::string(10, '-') << "Test 2: char array"
		<< std::string(10, '-') << std::endl;

	char	other[] = { 'j', 'i', 'h', 'u', 'u' };
	iter(other, 5, upcase);

}

void	test3(void)
{
	std::cout << "\n" << std::string(10, '-') << "Test 3: int pointer array"
		<< std::string(10, '-') << std::endl;

	int	a = 4;
	int	b = 5;
	int c = 6;
	int*	nbs[] = { &a, &b, &c };
	iter(nbs, 3, print_ptr);
}

int	main(void)
{
	test1();
	test2();
	test3();

	return 0;
}
