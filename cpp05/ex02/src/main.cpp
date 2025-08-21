#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

int	main(void)
{
	try
	{
		std::cout << "----Test 1----" << std::endl;
		Bureaucrat	Angela("Angela", 3);

		std::cout << Angela << std::endl;

		ShrubberyCreationForm	form1("Angela");
		std::cout << form1 << std::endl;

		Angela.signForm(form1);
		form1.execute(Angela);
		std::cout << std::endl;

		PresidentialPardonForm	form2("Angela");
		std::cout << form2 << std::endl;

		Angela.signForm(form2);
		form2.execute(Angela);
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << std::endl << "----Test 2----" << std::endl;
		Bureaucrat	Val("Val", 42);

		std::cout << Val << std::endl;

		RobotomyRequestForm	form3("Val");
		std::cout << form3 << std::endl;

		Val.signForm(form3);
		form3.execute(Val);
		std::cout << std::endl;

		Bureaucrat	Phyllis("Phyllis", 58);

		std::cout << Phyllis << std::endl << std::endl;

		form3.execute(Phyllis);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
