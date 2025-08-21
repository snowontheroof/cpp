#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("Shrubbery Creation Form", 145, 137), _target(target)
{
	std::cout << "Shrubbery Creation Form: Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) : AForm(obj), _target(obj._target)
{
	std::cout << "Shrubbery Creation Form: Copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrubbery Creation Form: Destructor called" << std::endl;
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (!getSignStatus())
		throw NotSignedException();
	if (executor.getGrade() > getExecGrade())
		throw GradeTooLowException();
	std::string	newFileName = _target + "_shrubbery";
	std::ofstream	newFile(newFileName);
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
	std::cout << executor.getName() << " created shrubbery at " << newFileName << std::endl;
}
