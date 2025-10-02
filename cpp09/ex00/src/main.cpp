#include "../inc/BitcoinExhange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./btc <file>\n";
		return 0;
	}
	try
	{
		std::string	input = argv[1];
		BitcoinExhange::btc(input);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	return 0;
}
