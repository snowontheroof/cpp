#include "../inc/Span.hpp"

void	test1(void)
{
	std::cout << std::endl << std::string(10, '-') << "Test 1: 10 000+ numbers"
		<< std::string(10, '-') << std::endl;

	try
	{
		Span test(13005);
		std::srand(time(0));
		for (unsigned int i = 0; i < test.getSize(); i++)
			test.addNumber(std::rand() % 100000);
		std::cout << "Shortest span: " << test.shortestSpan() << std::endl;
		std::cout << "Longest span: " << test.longestSpan() << std::endl;
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
		std::cout << "Shortest span: " << test.shortestSpan() << std::endl;
		std::cout << "Longest span: " << test.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}

void	test3(void)
{
	std::cout << std::endl << std::string(10, '-')
		<< "Test 3: basic test provided in the subject"
		<< std::string(10, '-') << std::endl;

	try
	{
		Span test(5);
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
		std::cout << "Shortest span: " << test.shortestSpan() << std::endl;
		std::cout << "Longest span: " << test.longestSpan() << std::endl;
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
		std::cout << "Shortest span: " << test.shortestSpan() << std::endl;
		std::cout << "Longest span: " << test.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}

void	test7(void)
{
	std::cout << std::endl << std::string(10, '-')
		<< "Test 7: adding a number to a full storage"
		<< std::string(10, '-') << std::endl;

	try
	{
		Span	test(42);

		std::vector<int>	toAdd = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
			16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34,
			35, 36, 37, 38, 39, 40, 41, 42 };
		test.addRange(toAdd.begin(), toAdd.end());
		test.addNumber(43);
		std::cout << "Shortest span: " << test.shortestSpan() << std::endl;
		std::cout << "Longest span: " << test.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}

void	test8(void)
{
	std::cout << std::endl << std::string(10, '-')
		<< "Test 8: adding a number to a storage of size 0"
		<< std::string(10, '-') << std::endl;

	try
	{
		Span	test(0);

		test.addNumber(-42);
		std::cout << "Shortest span: " << test.shortestSpan() << std::endl;
		std::cout << "Longest span: " << test.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}

void	test9(void)
{
	std::cout << std::endl << std::string(10, '-')
		<< "Test 9: copy constructor and copy assignment operator"
		<< std::string(10, '-') << std::endl;

	try
	{
		Span	test(15);

		test.addNumber(99);

		std::vector<int>	toAdd = { 89, 14, -55, 12, 0, 722 };
		test.addRange(toAdd.begin(), toAdd.end());

		Span	testCopy(test);
		std::cout << "test shortest span: " << test.shortestSpan() << std::endl;
		std::cout << "testCopy shortest span: " << testCopy.shortestSpan() << std::endl;
		std::cout << "test longest span: " << test.longestSpan() << std::endl;
		std::cout << "testCopy longest span: " << testCopy.longestSpan() << std::endl;
		test.addNumber(0);
		std::cout << "test shortest span: " << test.shortestSpan() << std::endl;
		std::cout << "testCopy shortest span: " << testCopy.shortestSpan() << std::endl;
		testCopy.addNumber(-722);
		std::cout << "test longest span: " << test.longestSpan() << std::endl;
		std::cout << "testCopy longest span: " << testCopy.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << '\n';
	try
	{
		Span	test1(3);
		Span	test2(0);

		test1.addNumber(-42);
		test1.addNumber(4422);
		test2 = test1;
		std::cout << "test1 shortest span: " << test1.shortestSpan() << std::endl;
		std::cout << "test2 shortest span: " << test2.shortestSpan() << std::endl;
		std::cout << "test1 longest span: " << test1.longestSpan() << std::endl;
		std::cout << "test2 longest span: " << test2.longestSpan() << std::endl;
		test2.addNumber(-42);
		std::cout << "test1 shortest span: " << test1.shortestSpan() << std::endl;
		std::cout << "test2 shortest span: " << test2.shortestSpan() << std::endl;
		test1.addNumber(-4422);
		std::cout << "test1 longest span: " << test1.longestSpan() << std::endl;
		std::cout << "test2 longest span: " << test2.longestSpan() << std::endl;
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
	test7();
	test8();
	test9();

	return 0;
}
