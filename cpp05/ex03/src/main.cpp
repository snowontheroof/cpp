#include "../inc/Intern.hpp"

void	test1(void)
{
	try
	{
		std::cout << "----Test 1----\n\n";
		Bureaucrat	Ryan("Ryan", 2);
		std::cout << Ryan << std::endl;

		Intern	Pete;

		std::cout << std::endl;
		Form*	document = Pete.makeForm("Robotomy request", "Toby");
		std::cout << *document << std::endl;

		Ryan.signForm(*document);
		Ryan.executeForm(*document);
		std::cout << std::endl;

		Form*	another = Pete.makeForm("Just make any form, can you?!", "Kelly");

		delete document;
		delete another;
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
		Bureaucrat	Kelly("Kelly", 135);
		std::cout << std::endl << Kelly << std::endl;

		Intern	Clark;

		std::cout << std::endl;
		Form*	document = Clark.makeForm("Shrubbery creation", "Darryl");
		std::cout << *document << std::endl;

		Kelly.signForm(*document);
		Kelly.executeForm(*document);
		std::cout << std::endl;

		Form*	another = Clark.makeForm("Presidential pardon", "Nellie");
		std::cout << *another << std::endl;

		Kelly.signForm(*another);
		Kelly.executeForm(*another);
		std::cout << "\n";

		Bureaucrat	David("David", 4);
		std::cout << David << "\n\n";

		David.signForm(*another);
		David.executeForm(*another);

		delete document;
		delete another;
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

	return 0;
}
