#include <iostream>

void	megaphone(std::string msg)
{
	for (int i = 0; msg[i]; i++)
		std::cout << (char)toupper(msg[i]);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < argc; i++)
			megaphone(argv[i]);
	}
	std::cout << std::endl;
	return 0;
}
