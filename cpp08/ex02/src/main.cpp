#include "../inc/MutantStack.hpp"
#include <list>

void	test1(void)
{
	std::cout << std::string(10, '-')
		<< "Test 1: int stack (test provided in the subject)"
		<< std::string(10, '-') << std::endl;

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	std::cout << mstack.top() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

void	test2(void)
{
	std::cout << std::endl << std::string(10, '-')
		<< "Test 2: int list (test provided in the subject)"
		<< std::string(10, '-') << std::endl;

	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << mstack.size() << std::endl;
	std::cout << mstack.back() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	mstack.push_back(0);
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::list<int> s(mstack);
}

void	test3(void)
{
	std::cout << std::endl << std::string(10, '-')
		<< "Test 3: char stack"
		<< std::string(10, '-') << std::endl;

	MutantStack<char>	cstack;
	cstack.push('a');
	cstack.push('b');
	cstack.push('c');
	std::cout << cstack.top() << std::endl;
	cstack.pop();
	std::cout << cstack.top() << std::endl;
	cstack.pop();
	cstack.push('n');
	cstack.push('o');
	cstack.push('t');
	cstack.push('h');
	cstack.push('e');
	cstack.push('r');
	MutantStack<char>::iterator it = cstack.begin();
	MutantStack<char>::iterator ite = cstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it;
		*it = std::toupper(*it);
		std::cout << " -> " << *it << std::endl;
		++it;
	}
}

void	test4(void)
{
	std::cout << std::endl << std::string(10, '-')
		<< "Test 4: std::string stack"
		<< std::string(10, '-') << std::endl;

	MutantStack<std::string>	sstack;
	sstack.push("let's try this out");
	sstack.push(", shall we?");
	std::cout << sstack.top() << std::endl;
	sstack.pop();
	sstack.push("to see how it works");
	sstack.push("when we make a stack of strings");
	MutantStack<std::string>::iterator it = sstack.begin();
	MutantStack<std::string>::iterator ite = sstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << "string: " << *it << ", length: " << (*it).length() << std::endl;
		++it;
	}
}

void	test5(void)
{
	std::cout << std::endl << std::string(10, '-')
		<< "Test 5: copy constructor and copy assignment operator"
		<< std::string(10, '-') << std::endl;

	{
		MutantStack<double>	dstack;
		if (dstack.empty())
			std::cout << "dstack is empty\n";
		dstack.push(42.0);
		dstack.push(-42.42);
		dstack.push(111.111);
		MutantStack<double>	dstackCopy(dstack);
		std::cout << "dstack size: " << dstack.size() << std::endl;
		std::cout << "dstackCopy size: " << dstackCopy.size() << std::endl;
		dstack.push(15);
		dstackCopy.pop();
		std::cout << "dstack size: " << dstack.size() << std::endl;
		std::cout << "dstackCopy size: " << dstackCopy.size() << std::endl;
		MutantStack<double>::iterator it = dstack.begin();
		MutantStack<double>::iterator ite = dstack.end();
		MutantStack<double>::iterator itC = dstackCopy.begin();
		MutantStack<double>::iterator iteC = dstackCopy.end();
		std::cout << "\ndstack values:\n";
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << "\ndstackCopy values:\n";
		while (itC != iteC)
		{
			std::cout << *itC << std::endl;
			++itC;
		}
	}

	{
		MutantStack<float>	fstack1;
		MutantStack<float>	fstack2;

		fstack1.push(42.42f);
		fstack1.push(4.2f);
		fstack1.push(-42.42f);
		fstack2 = fstack1;
		std::cout << "fstack1 size: " << fstack1.size() << std::endl;
		std::cout << "fstack2 size: " << fstack2.size() << std::endl;
		fstack2.push(0.42f);
		fstack1.pop();
		MutantStack<float>::iterator it = fstack1.begin();
		MutantStack<float>::iterator ite = fstack1.end();
		MutantStack<float>::iterator itC = fstack2.begin();
		MutantStack<float>::iterator iteC = fstack2.end();
		std::cout << "\nfstack1 values:\n";
		while (ite != it)
		{
			std::cout << *ite << "f\n";
			--ite;
		}
		std::cout << "\nfstack2 values:\n";
		--iteC;
		while (iteC != itC)
		{
			std::cout << *iteC << "f\n";
			--iteC;
		}
	}
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
