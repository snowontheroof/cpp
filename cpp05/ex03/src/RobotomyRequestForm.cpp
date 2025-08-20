#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : Form("Robotomy Request Form", 72, 45), _target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) : Form(obj), _target(obj._target)
{

}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	try
	{
		if (!getSignStatus())
			throw NotSignedException();
		if (getExecGrade() > executor.getGrade())
			throw GradeTooLowException();
		std::cout << "DrR dRr DrR!" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Robotomy Request Form: " << e.what() << std::endl;
	}
}
