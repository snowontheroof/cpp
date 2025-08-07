#include "Form.hpp"

Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade), _isSigned(false)
{
    std::cout << "Form " << _name << ": Constructor called" << std::endl;
}

Form::Form(const Form& obj) : _name(obj._name), _signGrade(obj._signGrade), _execGrade(obj._execGrade), _isSigned(obj._isSigned)
{
    std::cout << "Form " << _name << ": Copy constructor called" << std::endl;
}

Form::~Form()
{
    std::cout << "Form " << _name << ": Destructor called" << std::endl;
}