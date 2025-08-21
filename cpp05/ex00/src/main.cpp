#include "../inc/Bureaucrat.hpp"

int	main(void)
{
	try
	{
		std::cout << "----Test 1----" << std::endl;
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

	try
	{
		std::cout << std::endl << "----Test 2----" << std::endl;
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

	try
	{
		std::cout << std::endl << "----Test 3----" << std::endl;
		Bureaucrat	Stanley("Stanley", 114);
		Bureaucrat	Michael(Stanley);

		std::cout << std::endl << Stanley << std::endl;
		std::cout << Michael << std::endl << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
