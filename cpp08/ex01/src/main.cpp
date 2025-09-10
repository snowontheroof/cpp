#include "../inc/Span.hpp"

void	test1(void)
{
	try
	{
		Span test(5);
		test.addNumber(1);
		test.addNumber(8);
		test.addNumber(-4);
		test.addNumber(0);
		test.addNumber(15);
		std::cout << test.longestSpan() << std::endl;
		std::cout << test.shortestSpan() << std::endl;

		Span test2(3);
		test2.addNumber(1);
		std::cout << test2.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}

void	test2(void)
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void	test3(void)
{
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

	return 0;
}