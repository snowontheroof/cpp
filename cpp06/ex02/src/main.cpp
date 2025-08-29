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
		std::cout << "A made\n";
		break;
	case 1:
		ptr = new B();
		std::cout << "B made\n";
		break;
	case 2:
		ptr = new C();
		std::cout << "C made\n";
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
}

void	identify(Base& p)
{
	try
	{
		A& ref = dynamic_cast<A&>(p);
		std::cout << "A\n";
		(void)ref;
	}
	catch(const std::bad_cast& e)
	{
		;
	}
	try
	{
		B& ref = dynamic_cast<B&>(p);
		std::cout << "B\n";
		(void)ref;
	}
	catch(const std::bad_cast& e)
	{
		;
	}
	try
	{
		C& ref = dynamic_cast<C&>(p);
		std::cout << "C\n";
		(void)ref;
	}
	catch(const std::bad_cast& e)
	{
		;
	}
}

int	main(void)
{
	Base*	ptr = generate();
	identify(ptr);
	identify(*ptr);

	return 0;
}