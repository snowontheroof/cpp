#include "../inc/easyfind.hpp"
#include <vector>
#include <deque>
#include <array>
#include <map>

void	test1(void)
{
	std::cout << std::string(10, '-') << "Test 1: vector"
		<< std::string(10, '-') << std::endl;

	try
	{
		std::vector<int>	test = { 1, 2, 3 };
		std::cout << *easyfind(test, 2) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		std::vector<int>	test = { 42, 422, 442 };
		std::cout << *easyfind(test, -42) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}

void	test2(void)
{
	std::cout << std::endl << std::string(10, '-') << "Test 2: deque"
		<< std::string(10, '-') << std::endl;

	try
	{
		std::deque<int>	test2 = { 9, 42, 13, -42 };
		std::cout << *easyfind(test2, 42) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		std::deque<int>	test2 = { 0, 84, 1, 55, 19, 424242, -42 };
		std::cout << *easyfind(test2, -49) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

}

void	test3(void)
{
	std::cout << std::endl << std::string(10, '-') << "Test 3: array"
		<< std::string(10, '-') << std::endl;

	try
	{
		std::array<int, 5>	test3 = { -99, 55, 13, 3, 01 };
		std::cout << *easyfind(test3, 1) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::array<int, 6>	test3 = { 90, 89, 88, 91, 92, 99 };
		std::cout << *easyfind(test3, 1) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	test4(void)
{
	std::cout << std::endl << std::string(10, '-') << "Test 4: empty containers"
		<< std::string(10, '-') << std::endl;

	try
	{
		std::vector<int>	test = {};
		std::cout << *easyfind(test, 16) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		std::deque<int>	test = {};
		std::cout << *easyfind(test, 16) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		std::array<int, 0>	test = {};
		std::cout << *easyfind(test, 16) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}

int	main(void)
{
	test1();
	test2();
	test3();
	test4();

	return 0;
}
