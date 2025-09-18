#include "../inc/Span.hpp"

void	test1(void)
{
	std::cout << std::endl << std::string(10, '-') << "Test 1: 10 000+ numbers"
		<< std::string(10, '-') << std::endl;

	try
	{
		Span test(10005);
		std::srand(time(0));
		for (unsigned int i = 0; i < test.getSize(); i++)
			test.addNumber(std::rand() % 100000);
		std::cout << "Longest span: " << test.longestSpan() << std::endl;
		std::cout << "Shortest span: " << test.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}

void	test2(void)
{
	std::cout << std::endl << std::string(10, '-') << "Test 2: only one number"
		<< std::string(10, '-') << std::endl;

	try
	{
		Span test(3);
		test.addNumber(1);
		std::cout << "Longest span: " << test.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}

void	test3(void)
{
	std::cout << std::endl << std::string(10, '-') << "Test 3"
		<< std::string(10, '-') << std::endl;

	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}

void	test4(void)
{
	std::cout << std::endl << std::string(10, '-')
		<< "Test 4: adding a sequence of elements"
		<< std::string(10, '-') << std::endl;

	try
	{
		Span	jihuu(13);
		jihuu.addNumber(-42);
		jihuu.addNumber(42);

		std::vector<int>	toadd = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
		jihuu.addNumbers(toadd);
		for (auto i : jihuu.getStorage())
			std::cout << i << std::endl;
	}
	catch (const std::exception& e)
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
