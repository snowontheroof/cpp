#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

int	main(void)
{
	try
	{
		std::cout << "----Test 1----" << std::endl;
		Bureaucrat	Angela("Angela", 3);

		std::cout << std::endl << Angela << std::endl;

		ShrubberyCreationForm	form1("home");
		std::cout << form1 << std::endl;

		Angela.signForm(form1);
		std::cout << form1 << std::endl;
		Angela.executeForm(form1);
		std::cout << std::endl;

		PresidentialPardonForm	form2("Jan");
		std::cout << form2 << std::endl;

		Angela.signForm(form2);
		Angela.executeForm(form2);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << std::endl << "----Test 2----" << std::endl;
		Bureaucrat	Val("Val", 42);

		std::cout << std::endl << Val << std::endl;

		RobotomyRequestForm	form3("Oscar");
		std::cout << form3 << std::endl;

		Val.signForm(form3);
		Val.executeForm(form3);
		std::cout << std::endl;

		Bureaucrat	Phyllis("Phyllis", 58);

		std::cout << Phyllis << std::endl << std::endl;

		Phyllis.executeForm(form3);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << std::endl << "----Test 3----" << std::endl;
		Bureaucrat	Andy("Andy", 114);

		std::cout << std::endl << Andy << std::endl;

		RobotomyRequestForm	form4("Erin");
		std::cout << form4 << std::endl;

		Andy.executeForm(form4);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
