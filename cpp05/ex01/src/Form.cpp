#include "../inc/Form.hpp"

Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade), _isSigned(false)
{
	std::cout << "Form " << _name << ": Constructor called" << std::endl;
	try
	{
		if (signGrade > 150 || execGrade > 150)
			throw Form::GradeTooLowException();
		if (signGrade < 1 || execGrade < 1)
			throw Form::GradeTooHighException();
	}
	catch(const std::exception& e)
	{
		std::cout << "Form: " << e.what() << std::endl;
	}

}

Form::Form(const Form& obj) : _name(obj._name), _signGrade(obj._signGrade), _execGrade(obj._execGrade), _isSigned(obj._isSigned)
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

int Form::getSignGrade() const
{
	return _signGrade;
}
int Form::getExecGrade() const
{
	return _execGrade;
}

const char* Form::GradeTooHighException::what() const noexcept
{
	return "Grade too high! The limit is 1";
}

const char* Form::GradeTooLowException::what() const noexcept
{
	return "Grade too low! The limit is 150";
}

void	Form::beSigned(const Bureaucrat& who)
{
	if (who.getGrade() <= getSignGrade())
	{
		_isSigned = true;
	}
}

std::ostream&	operator<<(std::ostream& os, const Form& obj)
{
	os << "Form " << obj.getName() << ", grade required to sign: "
		<< obj.getSignGrade() << ", grade required to execute: "
		<< obj.getExecGrade() << std::endl;
	return os;
}
