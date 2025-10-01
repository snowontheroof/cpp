#include "../inc/PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Expected usage: ./PmergeMe \"<sequence of positive integers>\"\n";
		return 0;
	}
	try
	{
		PmergeMe(static_cast<std::string>(argv[1]));
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	return 0;
}
