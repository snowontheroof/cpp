#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		const Bureaucrat&	_target;

	public:
		PresidentialPardonForm() = delete;
		PresidentialPardonForm(const Bureaucrat& target);
		PresidentialPardonForm(const PresidentialPardonForm& obj);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& other) = delete;
		~PresidentialPardonForm();
};

#endif
