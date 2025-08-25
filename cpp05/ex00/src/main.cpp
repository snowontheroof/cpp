#include "../inc/Bureaucrat.hpp"

void	test1(void)
{
	try
	{
		std::cout << "----Test 1----\n";
		Bureaucrat	Jim("Jim", 149);

		std::cout << std::endl << Jim.getName() << std::endl;
		std::cout << Jim.getGrade() << std::endl;
		Jim.downGrade();
		std::cout << Jim << std::endl;
		Jim.downGrade();
		std::cout << Jim << std::endl << std::endl;

		Bureaucrat	Creed(Jim);
		std::cout << Creed << std::endl << std::endl;
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
		Bureaucrat	Pam("Pam", 3);

		std::cout << std::endl << Pam.getName() << std::endl;
		std::cout << Pam.getGrade() << std::endl;
		Pam.upGrade();
		std::cout << Pam << std::endl;
		Pam.upGrade();
		std::cout << Pam << std::endl;
		Pam.upGrade();
		std::cout << Pam << std::endl;
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
		std::cout << "\n----Test 3----\n";
		Bureaucrat	Stanley("Stanley", 114);
		Bureaucrat	Michael(Stanley);

		std::cout << std::endl << Stanley << std::endl;
		std::cout << Michael << std::endl << std::endl;
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
		std::cout << "----Test 4----\n\n";
		Bureaucrat	Gabe("Gabe", -4);
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
		Bureaucrat	Gabe("Gabe", 154);
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

	return 0;
}
