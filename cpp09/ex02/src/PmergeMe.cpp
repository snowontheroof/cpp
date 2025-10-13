#include "../inc/PmergeMe.hpp"

bool	isValidNb(std::string& nb)
{
	size_t	i = 0;

	if (nb[i] == '+')
		i++;
	while (nb[i])
	{
		if (!std::isdigit(nb[i]))
			return false;
		i++;
	}
	return true;
}
