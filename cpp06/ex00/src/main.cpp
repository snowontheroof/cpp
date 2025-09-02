#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc == 2)
		ScalarConverter::convert(argv[1]);
	else
	{
		std::cout << "Do you want to run some tests? y/n\n";
		std::string	input;
		std::getline(std::cin, input, '\n');
		if (input == "y")
			tests();
	}
	return 0;
}
