#include "../inc/AForm.hpp"

AForm::AForm(const std::string name, int signGrade, int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
	std::cout << "AForm " << _name << ": Constructor called" << std::endl;
	if (_signGrade > 150 || _execGrade > 150)
		throw GradeTooLowException();
	if (_signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
}

AForm::AForm(const AForm& obj) : _name(obj._name), _signGrade(obj._signGrade), _execGrade(obj._execGrade)
{
	std::cout << "AForm " << _name << ": Copy constructor called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "AForm " << _name << ": Destructor called" << std::endl;
}

const std::string&	AForm::getName() const
{
	return _name;
}

bool	AForm::getSignStatus() const
{
	return _isSigned;
}

int	AForm::getSignGrade() const
{
	return _signGrade;
}

int	AForm::getExecGrade() const
{
	return _execGrade;
}

void	AForm::beSigned(const Bureaucrat& who)
{
	if (who.getGrade() > getSignGrade())
		throw GradeTooLowException();
	if (getSignStatus())
		throw AlreadySignedException();
	_isSigned = true;
	std::cout << who.getName() << " successfully signed " << _name << std::endl;
}

const char*	AForm::NotSignedException::what() const noexcept
{
	return "Form not signed!";
}

const char*	AForm::AlreadySignedException::what() const noexcept
{
	return "Form is already signed!";
}

const char*	AForm::GradeTooHighException::what() const noexcept
{
	return "Grade too high!";
}

const char*	AForm::GradeTooLowException::what() const noexcept
{
	return "Grade too low!";
}

std::ostream&	operator<<(std::ostream& os, const AForm& obj)
{
	os << obj.getName() << ", signed: ";
	if (obj.getSignStatus())
		os << "yes";
	else
		os << "no";
	os << ", grade required to sign: "
		<< obj.getSignGrade() << ", grade required to execute: "
		<< obj.getExecGrade() << std::endl;
	return os;
}
