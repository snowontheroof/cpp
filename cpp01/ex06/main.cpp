#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl	letsHarl;

	if (argc != 2)
		std::cout << "Expected usage: ./harlFilter DEBUG/INFO/WARNING/ERROR" << std::endl;
	else
		letsHarl.complain(argv[1]);
	return 0;
}
