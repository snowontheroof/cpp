#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : Form("Shrubbery Creation Form", 145, 137), _target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) : Form(obj), _target(obj._target)
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	try
	{
		if (!getSignStatus())
			throw NotSignedException();
		if (getExecGrade() < executor.getGrade())
			throw GradeTooLowException();
		std::string	newFileName = _target + "_shrubbery";
		std::ofstream	newFile(newFileName);
		newFile << "**/\\***" << std::endl
				<< "*/**\\**" << std::endl
				<< "/****\\*" << std::endl;
		newFile.close();
	}
	catch(const std::exception& e)
	{
		std::cout << "Shrubbery Creation Form: " << e.what() << std::endl;
	}
}
