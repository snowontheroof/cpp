#include "../inc/Intern.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	Ryan("Ryan", 2);
		std::cout << Ryan << std::endl;

		Intern	Pete;

		std::cout << std::endl;
		Form*	document = Pete.makeForm("Robotomy Request", "Toby");
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

	return 0;
}
