#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	ScalarConverter	test;
	if (argc == 2)
		test.convert(argv[1]);

	return 0;
}