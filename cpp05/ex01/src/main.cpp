#include "../inc/Form.hpp"

int	main(void)
{
	try
	{
		std::cout << "----Test 1----" << std::endl;
		Bureaucrat	Jim("Jim", 130);

		std::cout << std::endl << Jim.getName() << std::endl;
		std::cout << Jim.getGrade() << std::endl;
		Jim.upGrade();
		std::cout << Jim << std::endl;

		Bureaucrat	Kevin("Kevin", 12);

		std::cout << std::endl << Kevin << std::endl << std::endl;

		Form	Document("Document", 142, 134);
		std::cout << Document << std::endl;

		Jim.signForm(Document);
		std::cout << std::endl;
		Kevin.signForm(Document);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << std::endl << "----Test 2----" << std::endl;
		Bureaucrat	Dwight("Dwight", 99);

		std::cout << std::endl << Dwight << std::endl << std::endl;

		Form	Paperwork("Paperwork", 33, 54);
		std::cout << Paperwork << std::endl;

		Dwight.signForm(Paperwork);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << std::endl << "----Test 3----" << std::endl << std::endl;
		Form	Pile("Pile", 119, 0);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
