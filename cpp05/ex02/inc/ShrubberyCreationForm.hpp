#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		const Bureaucrat&	_target;

	public:
		ShrubberyCreationForm() = delete;
		ShrubberyCreationForm(const Bureaucrat& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& obj);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other) = delete;
		~ShrubberyCreationForm();
};

#endif
