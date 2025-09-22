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
	std::cout << std::endl << std::string(10, '-') << "Test 3: basic test"
		<< std::string(10, '-') << std::endl;

	try
	{
		Span test = Span(5);
		test.addNumber(6);
		test.addNumber(3);
		test.addNumber(17);
		test.addNumber(9);
		test.addNumber(11);
		std::cout << "Shortest span: " << test.shortestSpan() << std::endl;
		std::cout << "Longest span: " << test.longestSpan() << std::endl;
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
		Span	test(13);
		test.addNumber(-42);
		test.addNumber(42);

		std::vector<int>	toadd = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
		test.addRange(toadd.begin(), toadd.end());
		std::cout << "Shortest span: " << test.shortestSpan() << std::endl;
		std::cout << "Longest span: " << test.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}

void	test5(void)
{
	std::cout << std::endl << std::string(10, '-')
		<< "Test 5: adding a sequence of elements to a full storage"
		<< std::string(10, '-') << std::endl;

	try
	{
		Span	test(2);
		test.addNumber(-42);
		test.addNumber(42);

		std::vector<int>	toadd = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
		test.addRange(toadd.begin(), toadd.end());
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}

void	test6(void)
{
	std::cout << std::endl << std::string(10, '-')
		<< "Test 6: adding an empty sequence"
		<< std::string(10, '-') << std::endl;

	try
	{
		Span	test(4);
		test.addNumber(99);
		test.addNumber(999);

		std::vector<int>	toadd = {};
		test.addRange(toadd.begin(), toadd.end());
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
	test5();
	test6();

	return 0;
}
