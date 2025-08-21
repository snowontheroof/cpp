#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	std::cout << "Bureaucrat " << _name << ": Constructor called" << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	else
		_grade = grade;
}
Bureaucrat::Bureaucrat(const Bureaucrat& obj) : _name(obj._name), _grade(obj._grade)
{
	std::cout << "Bureaucrat " << _name << ": Copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << _name << ": Destructor called" << std::endl;
}

const std::string&	Bureaucrat::getName() const
{
	return _name;
}

int	Bureaucrat::getGrade() const
{
	return _grade;
}

void	Bureaucrat::upGrade()
{
	if ((_grade - 1) < 1)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::downGrade()
{
	if ((_grade + 1) > 150)
		throw GradeTooLowException();
	_grade++;
}

const char*	Bureaucrat::GradeTooHighException::what() const noexcept
{
	return  "Bureaucrat grade too high! The limit is 1.";
}

const char*	Bureaucrat::GradeTooLowException::what() const noexcept
{
	return "Bureaucrat grade too low! The limit is 150.";
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return os;
}
