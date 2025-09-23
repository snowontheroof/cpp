#include "../inc/easyfind.hpp"
#include <vector>
#include <deque>
#include <array>
#include <list>
#include <forward_list>

void	test1(void)
{
	std::cout << std::string(10, '-') << "Test 1: vector"
		<< std::string(10, '-') << std::endl;

	try
	{
		std::vector<int>	test1 = { 1, 2, 3 };
		std::cout << *easyfind(test1, 2) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		std::vector<int>	test1 = { 42, 422, 442 };
		std::cout << *easyfind(test1, -42) << std::endl;
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
	std::cout << std::endl << std::string(10, '-') << "Test 4: list"
		<< std::string(10, '-') << std::endl;

	try
	{
		std::list<int>	test4 = { -9912, 55200, 4, -1442 };
		std::cout << *easyfind(test4, +55200) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		std::list<int>	test4 = { -1, 12, -123, 1234, -12345, 123456, -1234567 };
		std::cout << *easyfind(test4, 123) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}

void	test5(void)
{
	std::cout << std::endl << std::string(10, '-') << "Test 5: forward list"
		<< std::string(10, '-') << std::endl;

	try
	{
		std::forward_list<int>	test5 = { 44, 56, 126, 623, 7345 };
		std::cout << *easyfind(test5, 44) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		std::forward_list<int>	test5 = { 8 };
		std::cout << *easyfind(test5, 9) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}

void	test6(void)
{
	std::cout << std::endl << std::string(10, '-') << "Test 6: empty containers"
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
	try
	{
		std::list<int>	test = {};
		std::cout << *easyfind(test, 16);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		std::forward_list<int>	test = {};
		std::cout << *easyfind(test, 16);
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
	test5();
	test6();

	return 0;
}
