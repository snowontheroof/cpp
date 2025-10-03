#include "../inc/PmergeMe.hpp"

// static int	comparisons = 0;

bool	PmergeMe::isValidNb(std::string& nb)
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

void	PmergeMe::sortVector(std::vector<int>& myVector)
{
	using Iterator = std::vector<std::vector<int>>::iterator;
	using VectIterator = std::vector<int>::iterator;

	std::vector<std::vector<int>>	comb;
	VectIterator	start = myVector.begin();
	VectIterator	finish = myVector.end();
	while (start != finish)
	{
		std::vector<int>	tmp;
		tmp.push_back(*start);
		comb.push_back(tmp);
		start++;
	}

	Iterator	begin = comb.begin();
	Iterator	next;
	Iterator	end = comb.end();

	size_t		range = 1;

	while ((range * 2) <= comb.size())
	{
		if (range > 1)
			begin = std::next(comb.begin()->back(), range - 1);
		next = std::next(begin, range);
		while (begin != end)
		{
			std::cout << "begin is " << *begin << " and next " << *next << std::endl;
			if (*begin > *next)
				std::iter_swap(begin, next);
			std::cout << std::distance(begin , end) << " dist\n";
			if (std::distance(begin, end) >= static_cast<int>(range * 3))
				begin += (range * 2);
			else
				break ;
			next = std::next(begin, range);
		}
		range *= 2;

	}
	begin = comb.begin();
	while (begin != end)
	{
		std::cout << *begin << std::endl;
		begin++;
	}
}

// void	PmergeMe::sortDeque(std::deque<int>& myDeque)
// {

// }
