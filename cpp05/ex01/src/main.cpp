#include "../inc/Form.hpp"

void	test1(void)
{
	try
	{
		std::cout << "----Test 1----\n";
		Bureaucrat	Jim("Jim", 130);

		std::cout << "\n" << Jim.getName() << "\n";
		std::cout << Jim.getGrade() << std::endl;
		Jim.upGrade();
		std::cout << Jim << std::endl;

		Bureaucrat	Kevin("Kevin", 12);

		std::cout << "\n" << Kevin << "\n\n";

		Form	Document("Document", 142, 134);
		std::cout << Document << std::endl;

		Jim.signForm(Document);
		std::cout << Document << std::endl;
		Kevin.signForm(Document);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	test2(void)
{
	try
	{
		std::cout << "\n----Test 2----\n";
		Bureaucrat	Dwight("Dwight", 99);

		std::cout << "\n" << Dwight << "\n\n";

		Form	Paperwork("Paperwork", 33, 54);
		std::cout << Paperwork << std::endl;

		Dwight.signForm(Paperwork);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	test3(void)
{
	try
	{
		std::cout << "\n----Test 3----\n\n";
		Form	Pile("Pile", 119, 0);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	test4(void)
{
	try
	{
		std::cout << "\n----Test 4----\n\n";
		Form	Pile("Pile", 110, 180);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	test5(void)
{
	try
	{
		std::cout << "\n----Test 5----\n\n";
		Form	Pile("Pile", 1100, 3);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	test6(void)
{
	try
	{
		std::cout << "\n----Test 6----\n\n";
		Form	Pile("Pile", -42, 100);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	test7(void)
{
	try
	{
		std::cout << "\n----Test 7----\n\n";
		Form	WhatNow("WhatNow", 0, 0);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	test8(void)
{
	try
	{
		std::cout << "\n----Test 8----\n\n";
		Form	WhatNow("WhatNow", 160, 151);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	test9(void)
{
	try
	{
		std::cout << "\n----Test 9----\n\n";
		Form	WhatNow("WhatNow", 160, -151);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
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
