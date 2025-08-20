#include "../inc/AForm.hpp"

AForm::AForm(const std::string name, int signGrade, int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
	try
	{
		if (_signGrade > 150 || _execGrade > 150)
			throw GradeTooLowException();
		if (_signGrade < 1 || execGrade < 1)
			throw GradeTooHighException();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

AForm::AForm(const AForm& obj) : _name(obj._name), _signGrade(obj._signGrade), _execGrade(obj._execGrade)
{
}

AForm::~AForm()
{
}

const std::string&	AForm::getName() const
{
	return _name;
}

bool	AForm::getSignStatus() const
{
	return _isSigned;
}

int AForm::getSignGrade() const
{
	return _signGrade;
}

int AForm::getExecGrade() const
{
	return _execGrade;
}

void	AForm::beSigned(const Bureaucrat& who)
{
	try
	{
		if (who.getGrade() > getSignGrade())
			throw GradeTooLowException();
		_isSigned = true;
	}
	catch(const GradeTooLowException& e)
	{
		std::cout << _name << ": " << e.what() << std::endl;
	}
}

const char*	AForm::NotSignedException::what() const noexcept
{
	return "Form not signed!";
}

const char* AForm::GradeTooHighException::what() const noexcept
{
	return "Grade too high!";
}

const char* AForm::GradeTooLowException::what() const noexcept
{
	return "Grade too low!";
}
