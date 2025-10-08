#include "../inc/PmergeMe.hpp"

// static int	comparisons = 0;
std::vector<int>	jacobsthalNbs = { 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461,
	10923, 21845, 43691, 87381, 174763, 349525 };

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

static void	insertBValues(std::vector<int>& bChain, std::vector<int>& mainChain,
	std::vector<std::pair<int, int>>& pairs)
{
	if (bChain.empty())
		return ;
	using Iter = std::vector<int>::iterator;
	using pairIter = std::vector<std::pair<int, int>>::iterator;
	pairIter	pos;
	for (int i = 0; bChain[i]; i++)
	{
		for (pos = pairs.begin(); pos != pairs.end(); pos++)
		{
			if (bChain[i] == pos->first)
				break ;
		}
		std::cout << "so pair is " << pos->second << std::endl;
		Iter	match = std::find(mainChain.begin(), mainChain.end(), pos->second);
		int	looker = std::distance(mainChain.begin(), match) / 2;
		// THIS NEEDS TO BE FIXED: HOW TO LOOK FOR THE MIDDLE - is it from the beginning
		// to the pair element or the one before that, how to handle odd and even amounts
		std::cout << "looker is " << looker << " and mainchain[looker] " << mainChain[looker] << std::endl;
		while (looker > 0 && bChain[i] < mainChain[looker])
		{
			Iter	other = mainChain.begin() + looker;
			looker = std::distance(mainChain.begin(), other) / 2;
			std::cout << "now looker is " << looker << " and mainchain[looker] " << mainChain[looker] << std::endl;
		}
		mainChain.insert(mainChain.begin() + looker, bChain[i]);
	}
}

static void	fillMainChain(std::vector<int>& mainChain,
	std::vector<std::pair<int, int>>& pairs, std::optional<int> odd)
{
	using pairIter = std::vector<std::pair<int, int>>::iterator;
	using Iter = std::vector<int>::iterator;
	pairIter	it;
	for (it = pairs.begin(); it != pairs.end(); it++)
	{
		if (it->second == mainChain.front())
			break ;
	}

	mainChain.insert(mainChain.begin(), it->first);
	std::vector<int>	bChain;
	int	mainSize = static_cast<int>(mainChain.size());
	for (int i = 3; jacobsthalNbs[i] <= mainSize; i++)
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
				std::cout << *curr << " is curr\n";
				for (pairIter match = pairs.begin(); match != pairs.end(); match++)
				{
					if (match->second == *curr)
					{
						bChain.push_back(match->first);
						std::cout << match->first << " is now in bchain\n";
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
	using Iterator = std::vector<int>::iterator;
	using pairIter = std::vector<std::pair<int, int>>::iterator;
	Iterator	begin = myVector.begin();
	Iterator	next = std::next(begin, 1);
	Iterator	end = myVector.end();
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
		begin += 2;
		next = std::next(begin, 1);
	}
	for (pairIter pit = pairs.begin(); pit != pairs.end(); pit++)
		std::cout << pit->first << " " << pit->second << std::endl;
	for (Iterator it = newVector.begin(); it != newVector.end(); it++)
		std::cout << " newVector " << *it << std::endl;
	mainChain = sortVector(newVector);
	std::cout << "going here with " << mainChain.size() << std::endl;
	fillMainChain(mainChain, pairs, odd);
	return mainChain;
}

/*void	PmergeMe::sortVector(std::vector<int>& myVector)
{
	using Iterator = std::vector<std::vector<int>>::iterator;
	using VectIterator = std::vector<int>::iterator;

	std::vector<std::vector<int>>	comb;
	VectIterator		start = myVector.begin();
	VectIterator		finish = myVector.end();
	std::optional<int>	odd = std::nullopt;
	if (myVector.size() % 2 != 0)
	{
		odd = myVector.back();
		myVector.pop_back();
		finish = myVector.end() - 1;
	}
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

	while (comb.begin()->size() <= comb.size())
	{
		begin = comb.begin();
		next = std::next(begin, 1);
		while (begin != end && next != end)
		{
			std::cout << "begin is " << begin->back() << " and next " << next->back() << std::endl;
			if (begin->back() > next->back())
				std::iter_swap(begin, next);
			if (next + 1 != comb.end() && begin + 1 != comb.end() && begin + 2 != comb.end())
			{
				std::cout << "can add\n";
				begin += 2;
			}
			else
			{
				std::cout << "cant add\n";
				break ;
			}
			next = std::next(begin, 1);
		}
		Iterator	looper = comb.begin();
		int		loops = 0;
		while (looper != comb.end() && looper + 1 != comb.end())
		{
			Iterator	follower = std::next(looper, 1);
			std::cout << "looper back is " << looper->back() << " and follower back is " << follower->back() << std::endl;
			for (VectIterator it = follower->begin(); it != follower->end(); it++)
				looper->push_back(*it);
			std::cout << "loop " << loops << ":\n";
			for (VectIterator it = looper->begin(); it != looper->end(); it++)
				std::cout << "element is " << *it << std::endl;
			loops++;
			looper++;
			comb.erase(follower);
		}
	}
	begin = comb.begin();
	while (begin != end)
	{
		std::cout << begin->back() << std::endl;
		begin++;
	}
}*/

// void	PmergeMe::sortDeque(std::deque<int>& myDeque)
// {

// }
