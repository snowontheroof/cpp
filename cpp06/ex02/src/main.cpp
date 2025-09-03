#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

Base*	generate(void)
{
	Base*	ptr = nullptr;

	std::srand(time(0));
	int	randomValue = (std::rand() % 100) % 3;
	switch (randomValue)
	{
		case 0:
			ptr = new A();
			break;
		case 1:
			ptr = new B();
			break;
		case 2:
			ptr = new C();
		default:
			break;
	}
	return ptr;
}

void	identify(Base* ptr)
{
	if (dynamic_cast<A*>(ptr))
		std::cout << "A\n";
	else if (dynamic_cast<B*>(ptr))
		std::cout << "B\n";
	else if (dynamic_cast<C*>(ptr))
		std::cout << "C\n";
	else
		std::cout << "Unknown\n";
}

void	identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A\n";
		return ;
	}
	catch(const std::bad_cast& e)
	{
	}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B\n";
		return ;
	}
	catch(const std::bad_cast& e)
	{
	}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C\n";
		return ;
	}
	catch(const std::bad_cast& e)
	{
	}

	std::cout << "Unknown\n";
}

int	main(void)
{
	Base*	ptr = generate();
	std::cout << "Type identified by identify(Base* ptr): ";
	identify(ptr);
	std::cout << "Type identified by identify(Base& p): ";
	identify(*ptr);

	delete ptr;

	return 0;
}
