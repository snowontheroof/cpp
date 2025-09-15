#include "../inc/iter.hpp"
#include <iostream>

void	print(int nb)
{
	std::cout << nb << std::endl;
}

void	upCase(char c)
{
	if (c <= 'z' && c >= 'a')
		c -= 32;
	std::cout << c << std::endl;
}

void	printPtr(int* ptr)
{
	std::cout << "Pointer address: " << ptr << std::endl;
	std::cout << "Value of variable pointed by pointer: " << *ptr << std::endl;
}

class Example
{
	public:
		std::string	name;
		int			value;
};

void	addValue(Example& obj)
{
	std::cout << "Object " << obj.name << ": Original value: " << obj.value << std::endl;
	obj.value++;
	std::cout << "Incremented value: " << obj.value << std::endl;
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

	char	other[] = { 'g', 'o', 'o', 'd', ' ', 'd', 'a', 'y', '!' };
	iter(other, 9, upCase);
}

void	test3(void)
{
	std::cout << "\n" << std::string(10, '-') << "Test 3: int pointer array"
		<< std::string(10, '-') << std::endl;

	int	a = 4;
	int	b = 5;
	int c = 6;
	int*	nbs[] = { &a, &b, &c };
	iter(nbs, 3, printPtr);
}

void	test4(void)
{
	std::cout << "\n" << std::string(10, '-') << "Test 4: class object array"
		<< std::string(10, '-') << std::endl;

	Example	array[3] = {};
	array[0].name = "first";
	array[0].value = 42;
	array[1].name = "second";
	array[1].value = 24;
	array[2].name = "third";
	array[2].value = -42;
	iter(array, 3, addValue);
}

int	main(void)
{
	test1();
	test2();
	test3();
	test4();

	return 0;
}
