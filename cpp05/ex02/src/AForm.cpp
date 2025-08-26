#include "../inc/AForm.hpp"

AForm::AForm(const std::string name, int signGrade, int execGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade > 150 || execGrade > 150)
	{
		std::cout << _name << " couldn't be created - why? ";
		throw GradeTooLowException();
	}
	if (signGrade < 1 || execGrade < 1)
	{
		std::cout << _name << " couldn't be created - why? ";
		throw GradeTooHighException();
	}
}

AForm::AForm(const AForm& obj) : _name(obj._name), _isSigned(obj._isSigned), _signGrade(obj._signGrade), _execGrade(obj._execGrade)
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

int	AForm::getSignGrade() const
{
	return _signGrade;
}

int	AForm::getExecGrade() const
{
	return _execGrade;
}

void	AForm::beSigned(const Bureaucrat& signer)
{
	if (_isSigned)
		throw AlreadySignedException();
	if (getSignGrade() < signer.getGrade())
		throw GradeTooLowException();
	_isSigned = true;
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
