#include "../inc/PmergeMe.hpp"

static int			comparisons = 0;
std::vector<int>	jacobsthalNbs = { 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461,
	10923, 21845, 43691, 87381, 174763, 349525 };

using Iter = std::vector<int>::iterator;
using pairIter = std::vector<std::pair<int, int>>::iterator;

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

static size_t	findPos(size_t pos, std::vector<int>& mainChain,
	int toInsert)
{
	size_t	start = 0;
	size_t	end = pos;
	while (start < end)
	{
		size_t	middle = start + (end - start) / 2;
		if (mainChain[middle] < toInsert)
			start = middle + 1;
		else
			end = middle;
		comparisons++;
	}
	return start;
}

static void	insertBValues(std::vector<int>& bChain, std::vector<int>& mainChain,
	std::vector<std::pair<int, int>>& pairs)
{
	if (bChain.empty())
		return ;
	pairIter	pos;
	std::cout << "now bChain size " << bChain.size() << std::endl;
	for (size_t i = 0; i < bChain.size(); i++)
	{
		for (pos = pairs.begin(); pos != pairs.end(); pos++)
		{
			if (bChain[i] == pos->first)
				break ;
		}
		size_t	match;
		if (pos != pairs.end())
		{
			std::cout << "so pair is " << pos->second << std::endl;
			Iter	tmp = std::find(mainChain.begin(), mainChain.end(), pos->second);
			match = static_cast<int>(std::distance(mainChain.begin(), tmp));
		}
		else
			match = mainChain.size();
		size_t index = findPos(match, mainChain, bChain[i]);
		std::cout << index << " is index for " << bChain[i] << " and i " << i << std::endl;
		mainChain.insert(mainChain.begin() + index, bChain[i]);
	}
}

static void	fillMainChain(std::vector<int>& mainChain,
	std::vector<std::pair<int, int>>& pairs, std::optional<int> odd)
{
	pairIter	it;
	for (it = pairs.begin(); it != pairs.end(); it++)
	{
		if (it->second == mainChain.front())
			break ;
	}

	mainChain.insert(mainChain.begin(), it->first);
	std::vector<int>	bChain;
	int	mainSize = static_cast<int>(mainChain.size());
	size_t	toInsertAmt = mainSize - 2;
	if (odd)
		toInsertAmt++;
	std::cout << "mainsize is " << mainChain.size() << "so toInsertAmt is " << toInsertAmt << std::endl;
	for (int i = 3; bChain.size() < toInsertAmt; i++)
	{
		std::cout << "now in iter loop with i = " << i << std::endl;
		Iter	curr = mainChain.begin() + jacobsthalNbs[i];
		Iter	prev = mainChain.begin() + jacobsthalNbs[i - 1];
		while (curr != prev)
		{
			auto dist = std::distance(mainChain.begin(), curr);
			if (dist == static_cast<int>(mainChain.size()) && odd)
				bChain.push_back(*odd);
			else if (dist < static_cast<int>(mainChain.size()))
			{
				for (pairIter match = pairs.begin(); match != pairs.end(); match++)
				{
					if (match->second == *curr)
					{
						bChain.push_back(match->first);
						break ;
					}
				}
			}
			curr--;
		}
	}
	for (Iter it = bChain.begin(); it != bChain.end(); it++)
			std::cout << " bChain " << *it << std::endl;
	insertBValues(bChain, mainChain, pairs);
	for (Iter it = mainChain.begin(); it != mainChain.end(); it++)
		std::cout << " mainChain " << *it << std::endl;
}

std::vector<int>	PmergeMe::sortVector(std::vector<int>& myVector)
{
	Iter	begin = myVector.begin();
	Iter	next = std::next(begin, 1);
	Iter	end = myVector.end();
	std::vector<int>	newVector;
	std::vector<int>	mainChain;
	std::vector<std::pair<int, int>>	pairs;

	if (myVector.size() < 2)
	{
		std::cout << "now pushing to main " << myVector.back() << std::endl;
		mainChain.push_back(myVector.back());
		for (pairIter it = pairs.begin(); it != pairs.end(); it++)
			std::cout << it->first << " " << it->second << std::endl;
		return mainChain;
	}
	std::optional<int>	odd = std::nullopt;
	if (myVector.size() % 2 != 0)
	{
		odd = myVector.back();
		myVector.pop_back();
		std::cout << "odd " << *odd << std::endl;
	}
	while (begin != end && next != end)
	{
		if (*begin > *next)
		{
			newVector.push_back(*begin);
			pairs.push_back({*next, *begin});
		}
		else
		{
			newVector.push_back(*next);
			pairs.push_back({*begin, *next});
		}
		comparisons++;
		begin += 2;
		next = std::next(begin, 1);
	}
	for (pairIter pit = pairs.begin(); pit != pairs.end(); pit++)
		std::cout << pit->first << " " << pit->second << std::endl;
	for (Iter it = newVector.begin(); it != newVector.end(); it++)
		std::cout << " newVector " << *it << std::endl;
	mainChain = sortVector(newVector);
	std::cout << "going here with " << mainChain.size() << std::endl;
	fillMainChain(mainChain, pairs, odd);
	std::cout << "Comparisons: " << comparisons << std::endl;
	return mainChain;
}

// void	PmergeMe::sortDeque(std::deque<int>& myDeque)
// {

// }
