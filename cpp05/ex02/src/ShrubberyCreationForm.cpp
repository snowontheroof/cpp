#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("Shrubbery creation form", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) : AForm(obj), _target(obj._target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

const char*	ShrubberyCreationForm::FileCreationFailException::what() const noexcept
{
	return "System error: Could not open the created file for writing";
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (!getSignStatus())
		throw NotSignedException();
	if (executor.getGrade() > getExecGrade())
		throw GradeTooLowException();
	try
	{
		std::string	newFileName = _target + "_shrubbery";
		std::ofstream	newFile(newFileName);
		if (!newFile.is_open())
			throw FileCreationFailException();
		newFile << "              * *                            * *" << std::endl
				<< "           *    *  *                      *    *  *" << std::endl
				<< "      *  *    *     *  *            *  *    *     *  *" << std::endl
				<< "     *     *    *  *    *          *     *    *  *    *" << std::endl
				<< " * *   *    *    *    *   *   * *   *    *    *    *   *" << std::endl
				<< " *     *  *    * * .#  *   *   *     *  *    * * .#  *   *" << std::endl
				<< " *   *     * #.  .# *   *     *     *     * #.  .# *   *" << std::endl
				<< "  *      #.  #: #  * *    *      *      #.  #: #  * *    *" << std::endl
				<< " *   * *  #. ##        *        *   * *  #. ##        *" << std::endl
				<< "   *        ###        *         *        ###        *" << std::endl
				<< "              ##                            ##" << std::endl
				<< "              ##.                            ##." << std::endl
				<< "              .##:                           .##:" << std::endl
				<< "              :###                           :###" << std::endl
				<< "              ;###                           ;###" << std::endl
				<< "            ,####.                         ,####." << std::endl
				<< "           ######.                       .######." << std::endl;
		newFile.close();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
