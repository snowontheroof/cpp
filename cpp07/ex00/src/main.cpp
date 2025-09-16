#include "../inc/whatever.hpp"
#include <iostream>

void	test1(void)
{
	std::cout << std::string(10, '-') << "Test 1: char"
		<< std::string(10, '-') << std::endl;
	char	a = 'a';
	char	b = 'B';

	std::cout << "before: a is " << a << " and b is " << b << std::endl;
	::swap(a, b);
	std::cout << "after swap: a is " << a << " and b is " << b << std::endl;
	std::cout << "min is " << ::min(a, b) << std::endl;
	std::cout << "max is " << ::max(a, b) << std::endl;
}

void	test2(void)
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

void	test3(void)
{
	std::cout << "\n" << std::string(10, '-') << "Test 3: float"
		<< std::string(10, '-') << std::endl;
	float	a = 42.424f;
	float	b = -42424.2f;

	std::cout << "before: a is " << a << "f and b is " << b << "f\n";
	::swap(a, b);
	std::cout << "after swap: a is " << a << "f and b is " << b << "f\n";
	std::cout << "min is " << ::min(a, b) << "f\n";
	std::cout << "max is " << ::max(a, b) << "f\n";
}

void	test4(void)
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

void	test5(void)
{
	std::cout << "\n" << std::string(10, '-') << "Test 5: void *"
		<< std::string(10, '-') << std::endl;

	void*	x;
	void*	y;
	int		a;
	int		b;
	x = &a;
	y = &b;

	std::cout << "before: x is " << x << " and y is " << y << std::endl;
	::swap(x, y);
	std::cout << "after swap: x is " << x << " and y is " << y << std::endl;
	std::cout << "min is " << ::min(x, y) << std::endl;
	std::cout << "max is " << ::max(x, y) << std::endl;
}

void	test6(void)
{
	std::cout << "\n" << std::string(10, '-') << "Test 6: std::string"
		<< std::string(10, '-') << std::endl;
	std::string	a = "hello";
	std::string	b = "hell";

	std::cout << "before: a is " << a << " and b is " << b << std::endl;
	::swap(a, b);
	std::cout << "after swap: a is " << a << " and b is " << b << std::endl;
	std::cout << "min is " << ::min(a, b) << std::endl;
	std::cout << "max is " << ::max(a, b) << std::endl;
}

void	test7(void)
{
	std::cout << "\n" << std::string(10, '-') << "Test 7: bool"
		<< std::string(10, '-') << std::endl;
	bool	a = true;
	bool	b = false;

	std::cout << "before: a is " << a << " and b is " << b << std::endl;
	::swap(a, b);
	std::cout << "after swap: a is " << a << " and b is " << b << std::endl;
	std::cout << "min is " << ::min(a, b) << std::endl;
	std::cout << "max is " << ::max(a, b) << std::endl;
}

void	test8(void)
{
	std::cout << "\n" << std::string(10, '-') << "Test 8: int with equal value"
		<< std::string(10, '-') << std::endl;
	int	a = 42;
	int	b = 42;

	std::cout << "before: a is " << a << " and b is " << b << std::endl;
	::swap(a, b);
	std::cout << "after swap: a is " << a << " and b is " << b << std::endl;
	std::cout << "min is " << ::min(a, b) << std::endl;
	std::cout << "max is " << ::max(a, b) << std::endl;
}

void	test9(void)
{
	std::cout << "\n" << std::string(10, '-') << "Test 9: test provided in the subject"
		<< std::string(10, '-') << std::endl;
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min( a, b ) << std::endl;
	std::cout << "max(a, b) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min( c, d ) << std::endl;
	std::cout << "max(c, d) = " << ::max( c, d ) << std::endl;
}

// class Example
// {
// 	public:
// 		int	value;
// };

// std::ostream&	operator<<(std::ostream& os, const Example& obj)
// {
// 	os << obj.value;
// 	return os;
// }

// void	test10(void)
// {
// 	std::cout << "\n" << std::string(10, '-') << "Test 10: class"
// 		<< std::string(10, '-') << std::endl;
// 	Example	a;
// 	a.value = 10;
// 	Example	b;
// 	b.value = 20;

// 	std::cout << "before: a is " << a << " and b is " << b << std::endl;
// 	::swap(a, b);
// 	std::cout << "after swap: a is " << a << " and b is " << b << std::endl;
// 	std::cout << "min is " << ::min(a, b) << std::endl;
// 	std::cout << "max is " << ::max(a, b) << std::endl;
// }

int	main(void)
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();
	// test10();

	return 0;
}
