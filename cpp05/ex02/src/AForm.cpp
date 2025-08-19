#include "../inc/AForm.hpp"

void	AForm::execute(const Bureaucrat& executor) const
{
	try
	{
		if (_isSigned)
		{
			if (executor.getGrade() <= _execGrade)
			{

			}
		}
		else
			throw GradeTooLowException();
	}
	catch(const GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
}
