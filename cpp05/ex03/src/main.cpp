#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/Intern.hpp"

int	main(void)
{
	try
	{
		std::cout << "----Test 1----" << std::endl;
		Bureaucrat	Ryan("Ryan", 2);
		std::cout << Ryan << std::endl;

		std::cout << std::endl;
		Intern	Pete;

		std::cout << std::endl;
		Form*	document = Pete.makeForm("Presidential Pardon", "Ryan");
		std::cout << *document << std::endl;

		Ryan.signForm(*document);
		document->execute(Ryan);
		std::cout << std::endl;

		Form*	another = Pete.makeForm("Just make any form, can you?!", "Ryan");
		std::cout << std::endl;

		delete document;
		delete another;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
