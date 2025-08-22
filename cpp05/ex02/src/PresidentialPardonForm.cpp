#include "../inc/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("Presidential Pardon Form", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj) : AForm(obj), _target(obj._target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (!getSignStatus())
		throw NotSignedException();
	if (executor.getGrade() > getExecGrade())
		throw GradeTooLowException();
	std::cout << "Bureaucrat " << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
