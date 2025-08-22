#ifndef INTERN_HPP
# define INTERN_HPP
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern& obj) = delete;
		Intern&	operator=(const Intern& other) = delete;
		~Intern();

		Form*	makeForm(const std::string name, const std::string target);
};

#endif
