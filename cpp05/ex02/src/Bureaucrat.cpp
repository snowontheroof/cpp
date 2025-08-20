#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	std::cout << "Bureaucrat " << _name << ": Constructor called" << std::endl;
	try
	{
		if (grade < 1)
			throw GradeTooHighException();
		if (grade > 150)
			throw GradeTooLowException();
		else
			_grade = grade;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
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

int Bureaucrat::getGrade() const
{
	return _grade;
}

void	Bureaucrat::upGrade()
{
	try
	{
		_grade--;
		if (_grade < 1)
			throw GradeTooHighException();
	}
	catch(const GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	Bureaucrat::downGrade()
{
	try
	{
		_grade++;
		if (_grade > 150)
			throw GradeTooLowException();
	}
	catch(const GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	Bureaucrat::signForm(AForm& which)
{
	try
	{
		if (_grade <= which.getSignGrade())
		{
			which.beSigned(*this);
			std::cout << _name << " signed " << which.getName() << std::endl;
		}
		else
			throw GradeTooLowException();
	}
	catch (const GradeTooLowException& e)
	{
		std::cout << _name << "couldn't sign " << which.getName() << " because " << e.what() << std::endl;
	}
}

const char*	Bureaucrat::GradeTooHighException::what() const noexcept
{
	return "Grade too high!";
}

const char*	Bureaucrat::GradeTooLowException::what() const noexcept
{
	return "Grade too low!";
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return os;
}
