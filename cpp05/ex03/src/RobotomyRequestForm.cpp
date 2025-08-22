#include "../inc/RobotomyRequestForm.hpp"

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
	if (!getSignStatus())
		throw NotSignedException();
	if (executor.getGrade() > getExecGrade())
		throw GradeTooLowException();
	std::cout << "DrR dRr DrR!" << std::endl;
	std::srand(time(0));
	int	randomValue = std::rand() % 100;
	if (randomValue % 2)
		std::cout << _target << " has successfully been robotomized!" << std::endl;
	else
		std::cout << "Oh no, the robotomization of " << _target << " failed." << std::endl;
}
