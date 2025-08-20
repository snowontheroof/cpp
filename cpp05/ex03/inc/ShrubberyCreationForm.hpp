#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "Form.hpp"
# include <fstream>

class ShrubberyCreationForm : public Form
{
	private:
		const std::string	_target;

	public:
		ShrubberyCreationForm() = delete;
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& obj);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other) = delete;
		~ShrubberyCreationForm();

		void	execute(const Bureaucrat& executor) const override;
};

#endif
