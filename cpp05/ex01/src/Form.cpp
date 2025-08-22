#include "../inc/Form.hpp"

Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
}

Form::Form(const Form& obj) : _name(obj._name), _isSigned(obj._isSigned), _signGrade(obj._signGrade), _execGrade(obj._execGrade)
{
}

Form::~Form()
{
}

const std::string&	Form::getName() const
{
	return _name;
}

bool	Form::getSignStatus() const
{
	return _isSigned;
}

int	Form::getSignGrade() const
{
	return _signGrade;
}

int	Form::getExecGrade() const
{
	return _execGrade;
}

const char*	Form::AlreadySignedException::what() const noexcept
{
	return "Form is already signed!";
}

const char*	Form::GradeTooHighException::what() const noexcept
{
	return "Grade too high!";
}

const char*	Form::GradeTooLowException::what() const noexcept
{
	return "Grade too low!";
}

void	Form::beSigned(const Bureaucrat& signer)
{
	if (_isSigned)
		throw AlreadySignedException();
	if (getSignGrade() < signer.getGrade())
		throw GradeTooLowException();
	_isSigned = true;
}

std::ostream&	operator<<(std::ostream& os, const Form& obj)
{
	os << obj.getName() << ", signed: ";
	if (obj.getSignStatus())
		os << "yes";
	else
		os << "no";
	std::cout << ", grade required to sign: "
		<< obj.getSignGrade() << ", grade required to execute: "
		<< obj.getExecGrade() << std::endl;
	return os;
}
