#include "../inc/AForm.hpp"

AForm::AForm(const std::string name, int signGrade, int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
	if (_signGrade > 150 || _execGrade > 150)
		throw GradeTooLowException();
	if (_signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
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
