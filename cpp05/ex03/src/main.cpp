#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/Intern.hpp"

int	main(void)
{
	Bureaucrat	Markku("Markku", 100);
	ShrubberyCreationForm	lappu("Markku");
	RobotomyRequestForm		robotsi("Markku");
	PresidentialPardonForm	armahdus("Markku");

	lappu.beSigned(Markku);
	lappu.execute(Markku);
	robotsi.beSigned(Markku);
	robotsi.execute(Markku);
	armahdus.execute(Markku);

	Intern	teaBoy;
	Form *lippu = teaBoy.makeForm("Shrubbery Creation", "Markku");
	delete lippu;

	return 0;
}
