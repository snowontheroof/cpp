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

void	PmergeMe::sortQuotes(std::string input)
{
	std::istringstream	ss(input);
	std::string			token;
	while (ss >> token)
	{
		if (!isValidNb(token))
			throw std::runtime_error("Error");
		int	nb = std::stoi(token);
		vectorSort.push_back(nb);
		dequeSort.push_back(nb);
	}
	std::vector<int>::const_iterator	it = vectorSort.begin();
	std::cout << "Before: ";
	while (it != vectorSort.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

void	PmergeMe::sort(char **argv)
{
	size_t	i = 1;
	while (argv[i])
	{
		std::string	arg = static_cast<std::string>(argv[i]);
		if (!isValidNb(arg))
			throw std::runtime_error("Error");
		int	nb = std::stoi(arg);
		vectorSort.push_back(nb);
		dequeSort.push_back(nb);
		i++;
	}
	std::vector<int>::const_iterator	it = vectorSort.begin();
	std::cout << "Before: ";
	while (it != vectorSort.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}
