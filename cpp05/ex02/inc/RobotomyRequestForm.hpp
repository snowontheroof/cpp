#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		const std::string	_target;

	public:
		RobotomyRequestForm() = delete;
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& obj);
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& other) = delete;
		~RobotomyRequestForm();

		void	execute(const Bureaucrat& executor) const override;
};

#endif
