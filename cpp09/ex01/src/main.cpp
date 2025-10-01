#include "../inc/RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Expected usage: ./RPN \"<integers and operators>\"\n";
		return 0;
	}
	try
	{
		RPN(static_cast<std::string>(argv[1]));
	}
	catch(const std::exception& e)
	{
		std::cout << "Error" << e.what() << '\n';
	}

	return 0;
}
