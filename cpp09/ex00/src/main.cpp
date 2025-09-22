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
		BitcoinExhange	test;
		test.btc(static_cast<std::string>(argv[1]));
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	return 0;
}
