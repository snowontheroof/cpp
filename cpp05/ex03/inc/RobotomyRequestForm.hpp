#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "Form.hpp"

class RobotomyRequestForm : public Form
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
