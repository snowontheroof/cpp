#include "whatever.hpp"
#include <iostream>

void	test1()
{
	std::cout << std::string(10, '-') << "Test 1: void *"
		<< std::string(10, '-') << std::endl;

	void*	x;
	void*	y;

	std::cout << "before: x is " << x << " and y is " << y << std::endl;
	::swap(x, y);
	std::cout << "after swap: x is " << x << " and y is " << y << std::endl;
	std::cout << "min is " << ::min(x, y) << std::endl;
	std::cout << "max is " << ::max(x, y) << std::endl;
}

void	test2()
{
	std::cout << "\n" << std::string(10, '-') << "Test 2: int"
		<< std::string(10, '-') << std::endl;
	int	x = 0;
	int	y = 5;

	std::cout << "before: x is " << x << " and y is " << y << std::endl;
	::swap(x, y);
	std::cout << "after swap: x is " << x << " and y is " << y << std::endl;
	std::cout << "min is " << ::min(x, y) << std::endl;
	std::cout << "max is " << ::max(x, y) << std::endl;
}

void	test3()
{
	std::cout << "\n" << std::string(10, '-') << "Test 3: char"
		<< std::string(10, '-') << std::endl;
	char	a = 'a';
	char	b = 'A';

	std::cout << "before: a is " << a << " and b is " << b << std::endl;
	::swap(a, b);
	std::cout << "after swap: a is " << a << " and b is " << b << std::endl;
	std::cout << "min is " << ::min(a, b) << std::endl;
	std::cout << "max is " << ::max(a, b) << std::endl;
}

void	test4()
{
	std::cout << "\n" << std::string(10, '-') << "Test 4: double"
		<< std::string(10, '-') << std::endl;
	double	a = -88.453;
	double	b = 190.444;

	std::cout << "before: a is " << a << " and b is " << b << std::endl;
	::swap(a, b);
	std::cout << "after swap: a is " << a << " and b is " << b << std::endl;
	std::cout << "min is " << ::min(a, b) << std::endl;
	std::cout << "max is " << ::max(a, b) << std::endl;
}

void	test5()
{
	std::cout << "\n" << std::string(10, '-') << "Test 5: std::string"
		<< std::string(10, '-') << std::endl;
	std::string	a = "hello";
	std::string	b = "hell";

	std::cout << "before: a is " << a << " and b is " << b << std::endl;
	::swap(a, b);
	std::cout << "after swap: a is " << a << " and b is " << b << std::endl;
	std::cout << "min is " << ::min(a, b) << std::endl;
	std::cout << "max is " << ::max(a, b) << std::endl;
}

int	main(void)
{
	test1();
	test2();
	test3();
	test4();
	test5();

	return 0;
}
