#include "../inc/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("Presidential Pardon Form", 25, 5), _target(target)
{
	std::cout << "Presidential Pardon Form: Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj) : AForm(obj), _target(obj._target)
{
	std::cout << "Presidential Pardon Form: Copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Presidential Pardon Form: Destructor called" << std::endl;
}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (!getSignStatus())
		throw NotSignedException();
	if (executor.getGrade() > getExecGrade())
		throw GradeTooLowException();
	std::cout << "Bureaucrat " << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
