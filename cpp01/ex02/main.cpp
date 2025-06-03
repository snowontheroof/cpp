#include <iostream>

void	brainReference(std::string stringSTR)
{
	std::string*	stringPTR = &stringSTR;
	std::string&	stringREF = stringSTR;

	std::cout << "Memory address of stringSTR: " << &stringSTR << std::endl;
	std::cout << "Memory address of stringPTR: " << &stringPTR << std::endl;
	std::cout << "Memory address of stringREF: " << &stringREF << std::endl;

	std::cout << "Value of stringSTR: " << stringSTR << std::endl;
	std::cout << "Value of stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value of stringREF: " << stringREF << std::endl;
}

int	main()
{
	brainReference("I am testing this!");
	return 0;
}
