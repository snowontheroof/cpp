#include "../inc/iter.hpp"

template <typename T>
void	print(T& toPrint)
{
	std::cout << toPrint;
}

template <typename T>
void	increment(T& toInc)
{
	toInc++;
}

void	test1(void)
{
	std::cout << std::string(10, '-') << "Test 1: int array"
		<< std::string(10, '-') << std::endl;

	int	array[] = { 1, 2, 3, 4, 5 };
	::iter(array, 5, print<int>);
	std::cout << '\n';
	::iter(array, 5, increment<int>);
	::iter(array, 5, print<int>);
	std::cout << '\n';
}

void	upCase(char c)
{
	char C = std::toupper(c);
	std::cout << C;
}

void	test2(void)
{
	std::cout << "\n" << std::string(10, '-') << "Test 2: char array"
		<< std::string(10, '-') << std::endl;

	char	other[] = { 'g', 'o', 'o', 'd', ' ', 'd', 'a', 'y', '!' };
	::iter(other, 9, print<char>);
	std::cout << '\n';
	::iter(other, 9, upCase);
	std::cout << '\n';
	::iter(other, 9, increment<char>);
	::iter(other, 9, print<char>);
	std::cout << '\n';
}

void	printPtr(int* ptr)
{
	std::cout << "Pointer address: " << ptr << std::endl;
	std::cout << "Value: " << *ptr << std::endl;
}

void	test3(void)
{
	std::cout << "\n" << std::string(10, '-') << "Test 3: int pointer array"
		<< std::string(10, '-') << std::endl;

	int		a = 4;
	int		b = 5;
	int 	c = 6;
	int*	nbs[] = { &a, &b, &c };
	::iter(nbs, 3, printPtr);
}

void	test4(void)
{
	std::cout << "\n" << std::string(10, '-')
		<< "Test 4: nullptr and unmatching array length"
		<< std::string(10, '-') << std::endl;

	std::string*	array = nullptr;
	::iter(array, 9, print<std::string>);

	std::string	sentence[3] = { "let's", "test", "this!" };
	::iter(sentence, 0, print<std::string>);

	char	test[5] = { 'h', 'e', 'l', 'l', 'o' };
	::iter(test, 1, print<char>);
	std::cout << '\n';
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

void	test5(void)
{
	std::cout << "\n" << std::string(10, '-') << "Test 5: class object array"
		<< std::string(10, '-') << std::endl;

	Example	array[3] = {};
	array[0].name = "First";
	array[0].value = 42;
	array[1].name = "Second";
	array[1].value = 24;
	array[2].name = "Third";
	array[2].value = -42;
	::iter(array, 3, addValue);
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
