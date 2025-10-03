#include "../inc/PmergeMe.hpp"

template <typename T>
T	PmergeMe::parseQuotes(std::string& input)
{
	T	myCont;
	std::istringstream	ss(input);
	std::string			token;
	while (ss >> token)
	{
		if (!isValidNb(token))
			throw std::runtime_error("Error");
		int	nb = std::stoi(token);
		myCont.push_back(nb);
	}
	typename T::const_iterator	it = myCont.begin();
	std::cout << "Before: ";
	while (it != myCont.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
	return myCont;
}

template <typename T>
T	PmergeMe::parse(char **argv)
{
	T	myCont;
	size_t	i = 1;
	while (argv[i])
	{
		std::string	arg = static_cast<std::string>(argv[i]);
		if (!isValidNb(arg))
			throw std::runtime_error("Error");
		int	nb = std::stoi(arg);
		myCont.push_back(nb);
		i++;
	}
	typename T::const_iterator	it = myCont.begin();
	std::cout << "Before: ";
	while (it != myCont.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
	return myCont;
}
