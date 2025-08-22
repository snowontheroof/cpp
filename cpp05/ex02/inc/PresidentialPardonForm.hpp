#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		const std::string	_target;

	public:
		PresidentialPardonForm() = delete;
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& obj);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& other) = delete;
		~PresidentialPardonForm();

		void	execute(const Bureaucrat& executor) const override;
};

#endif
