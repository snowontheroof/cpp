#include "../inc/Form.hpp"

Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	std::cout << "Form " << _name << ": Constructor called" << std::endl;
	try
	{
		if (signGrade > 150 || execGrade > 150)
			throw GradeTooLowException();
		if (signGrade < 1 || execGrade < 1)
			throw GradeTooHighException();
	}
	catch(const std::exception& e)
	{
		std::cout << "Form: " << e.what() << std::endl;
	}

}

Form::Form(const Form& obj) : _name(obj._name), _isSigned(obj._isSigned), _signGrade(obj._signGrade), _execGrade(obj._execGrade)
{
	std::cout << "Form " << _name << ": Copy constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form " << _name << ": Destructor called" << std::endl;
}

const std::string&	Form::getName() const
{
	return _name;
}

bool	Form::getSignStatus() const
{
	return _isSigned;
}

int Form::getSignGrade() const
{
	return _signGrade;
}

int Form::getExecGrade() const
{
	return _execGrade;
}

const char*	Form::NotSignedException::what() const noexcept
{
	return "Form not signed!";
}

const char* Form::GradeTooHighException::what() const noexcept
{
	return "Grade too high!";
}

const char* Form::GradeTooLowException::what() const noexcept
{
	return "Grade too low!";
}

void	Form::beSigned(const Bureaucrat& who)
{
	try
	{
		if (who.getGrade() > getSignGrade())
			throw GradeTooLowException();
		_isSigned = true;
	}
	catch(const GradeTooLowException& e)
	{
		std::cout << getName() << ": " << e.what() << std::endl;
	}
}

void	Form::execute(const Bureaucrat& executor) const
{
	(void)executor;
	std::cout << "Error: no form to execute!" << std::endl;
}

std::ostream&	operator<<(std::ostream& os, const Form& obj)
{
	os << "Form " << obj.getName() << ", grade required to sign: "
		<< obj.getSignGrade() << ", grade required to execute: "
		<< obj.getExecGrade() << std::endl;
	return os;
}
