#include "../inc/Array.hpp"

void	test1(void)
{
	std::cout << std::string(10, '-') << "Test 1: int array" << std::string(10, '-')
		<< std::endl;
	Array<int>	test(5);

	try
	{
		std::cout << "Array size is " << test.size() << std::endl;
		test[0] = 42;
		std::cout << "Value at [0]: " << test[0] << std::endl;
		std::cout << "Value at [1]: " << test[1] << std::endl;
		std::cout << "Value at [9]: " << test[9] << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}

void	test2(void)
{
	std::cout <<  std::endl << std::string(10, '-')
		<< "Test 2: string array" << std::string(10, '-') << std::endl;
	Array<std::string>	test(8);

	try
	{
		std::cout << "Array size is " << test.size() << std::endl;
		test[1] = "hello there";
		std::cout << "Value at [1]: " << test[1] << std::endl;
		std::cout << "Value at [2]: " << test[2] << std::endl;
		test[-3] = "are we here?";
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}

void	test3(void)
{
	std::cout << std::endl << std::string(10, '-') << "Test 3: copy constructor"
		<< std::string(10, '-') << std::endl;

	try
	{
		Array<char>	x(3);
		x[0] = 'a';
		x[1] = 'b';
		Array<char>	y(x);

		std::cout << "x: size is " << x.size() << std::endl;
		std::cout << "y: size is " << y.size() << std::endl;
		for (unsigned int i = 0; i < 3; i++)
		{
			std::cout << "x: value at [" << i << "]: " << x[i] << std::endl;
			std::cout << "y: value at [" << i << "]: " << y[i] << std::endl;
		}
		x[2] = 'c';
		std::cout << "x: value at [2]: " << x[2] << std::endl;
		std::cout << "y: value at [2]: " << y[2] << std::endl;
		y[2] = 'd';
		std::cout << "x: value at [2]: " << x[2] << std::endl;
		std::cout << "y: value at [2]: " << y[2] << std::endl;
		y[5] = 'y';
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}

void	test4(void)
{
	std::cout << std::endl << std::string(10, '-')
		<< "Test 4: copy assignment operator" << std::string(10, '-') << std::endl;

	try
	{
		Array<double>	x(3);
		Array<double>	y;
		std::cout << "x: size is " << x.size() << std::endl;
		std::cout << "y: size is " << y.size() << std::endl;
		x[0] = 4.2;
		x[1] = 2.4;
		x[2] = 42.4;
		y = x;

		std::cout << "x: size is " << x.size() << std::endl;
		std::cout << "y: size is " << y.size() << std::endl;
		for (unsigned int i = 0; i < 3; i++)
		{
			std::cout << "x: value at [" << i << "]: " << x[i] << std::endl;
			std::cout << "y: value at [" << i << "]: " << y[i] << std::endl;
		}
		x[2] = -4.2;
		std::cout << "x: value at [2]: " << x[2] << std::endl;
		std::cout << "y: value at [2]: " << y[2] << std::endl;
		y[2] = -42.4;
		std::cout << "x: value at [2]: " << x[2] << std::endl;
		std::cout << "y: value at [2]: " << y[2] << std::endl;

		double	z = x[0];
		std::cout << z << '\n';
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}

void	test5(void)
{
	std::cout << std::endl << std::string(10, '-')
		<< "Test 5: const array" << std::string(10, '-') << std::endl;

	try
	{
		Array<char>	letters(3);
		letters[0] = 'y';
		letters[1] = 'e';
		letters[2] = 's';
		const Array<char>	phrase(letters);
		char	a = phrase[2];
		std::cout << a << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}

#define MAX_VAL 750
void	test6(void)
{
	std::cout << std::endl << std::string(10, '-')
		<< "Test 6: test provided on project page" << std::string(10, '-') << std::endl;

	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;
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
