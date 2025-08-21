#include "../inc/Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern: Constructor called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern: Destructor called" << std::endl;
}

Form*	Intern::makeForm(const std::string name, const std::string target)
{
	Form*				newForm = nullptr;
	const std::string	forms[3] = { "Shrubbery Creation", "Robotomy Request", "Presidential Pardon" };
	int					i;

	for (i = 0; i < 3; i++)
	{
		if (name == forms[i])
			break ;
	}
	switch (i)
	{
		case 0:
			newForm = new ShrubberyCreationForm(target);
			break ;
		case 1:
			newForm = new RobotomyRequestForm(target);
			break ;
		case 2:
			newForm = new PresidentialPardonForm(target);
			break ;
		default:
			std::cout << "Even an intern can't create form of a nonexisting type!" << std::endl;
			break ;
	}
	if (i < 3)
		std::cout << "Intern creates a " << newForm->getName() << std::endl;
	return newForm;
}
