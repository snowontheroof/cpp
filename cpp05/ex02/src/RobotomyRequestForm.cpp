#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const Bureaucrat& target) : AForm("Robotomy Request Form", 72, 45), _target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) : AForm(obj), _target(obj._target)
{

}

RobotomyRequestForm::~RobotomyRequestForm()
{

}
