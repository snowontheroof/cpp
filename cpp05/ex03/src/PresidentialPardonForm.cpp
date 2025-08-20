#include "../inc/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : Form("Presidential Pardon Form", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj) : Form(obj), _target(obj._target)
{

}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	try
	{
		if (!getSignStatus())
			throw NotSignedException();
		if (getExecGrade() > executor.getGrade())
			throw GradeTooLowException();
		std::cout << "Bureaucrat " << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Presidential Pardon Form: " << e.what() << std::endl;
	}
}
