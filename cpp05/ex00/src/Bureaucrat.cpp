#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
    std::cout << "Bureaucrat: Default constructor called" << std::endl;
}
Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
    std::cout << "Bureaucrat " << _name << ": Constructor called" << std::endl;
    try
    {
        if (grade < 1)
            throw "toohigh";
        if (grade > 150)
            throw 151;
        else
            _grade = grade;
    }
    catch(const std::string e)
    {
        GradeTooHighException();
    }
    catch(int e)
    {
        GradeTooLowException();
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

const std::string&  Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void    Bureaucrat::upGrade()
{
    try
    {
        _grade++;
        if (_grade > 150)
            throw 151;
    }
    catch(int e)
    {
       GradeTooLowException();
    }
}

void   Bureaucrat::downGrade()
{
    try
    {
        _grade--;
        if (_grade < 1)
            throw 0;
    }
    catch(int e)
    {
        GradeTooHighException();
    }
}

void    Bureaucrat::GradeTooHighException() const
{
    std::cout << "Grade too high! The limit is 1" << std::endl;
}

void    Bureaucrat::GradeTooLowException() const
{
    std::cout << "Grade too low! The limit is 150" << std::endl;
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj)
{
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
    return os;
}