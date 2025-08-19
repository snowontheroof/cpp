#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		const Bureaucrat&	_target;

	public:
		RobotomyRequestForm() = delete;
		RobotomyRequestForm(const Bureaucrat& target);
		RobotomyRequestForm(const RobotomyRequestForm& obj);
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& other) = delete;
		~RobotomyRequestForm();
};

#endif
