#include <iostream>

void	BrainReference(std::string brain)
{
	std::string*	stringPTR = &brain;
	std::string&	stringREF = brain;

	std::cout << "Memory address of brain: " << &brain << std::endl;
	std::cout << "Memory address of stringPTR: " << &stringPTR << std::endl;
	std::cout << "Memory address of stringREF: " << &stringREF << std::endl;

	std::cout << "Value of brain: " << brain << std::endl;
	std::cout << "Value of stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value of stringREF: " << stringREF << std::endl;
}

int	main()
{
	BrainReference("I am testing this!");
	return 0;
}
