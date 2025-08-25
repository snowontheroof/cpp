#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	else
		_grade = grade;
}
Bureaucrat::Bureaucrat(const Bureaucrat& obj) : _name(obj._name), _grade(obj._grade)
{
}

Bureaucrat::~Bureaucrat()
{
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

void	Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << _name << " couldn't sign " << form.getName()
			<< " - why? " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(const Form& form)
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << _name << " couldn't execute " << form.getName()
		<< " - why? " << e.what() << std::endl;
	}
}

const char*	Bureaucrat::GradeTooHighException::what() const noexcept
{
	return "Bureaucrat grade too high!";
}

const char*	Bureaucrat::GradeTooLowException::what() const noexcept
{
	return "Bureaucrat grade too low!";
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return os;
}
