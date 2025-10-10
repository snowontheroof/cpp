#include "../inc/PmergeMe.hpp"

template <typename T, typename P>
PmergeMe<T, P>::PmergeMe()
{
	comparisons = 0;
	jacobsthalNbs = { 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461,
		10923, 21845, 43691, 87381, 174763, 349525 };
}

static bool	isValidNb(std::string& nb)
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

template <typename T, typename P>
int	PmergeMe<T, P>::getComparisons(void)
{
	return comparisons;
}

template <typename T>
T	parseQuotes(std::string& input)
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
	return myCont;
}

template <typename T>
T	parseArgs(char **argv)
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
	return myCont;
}

template <typename T, typename P>
T	PmergeMe<T, P>::parse(int argc, char **argv)
{
	if (argc == 2)
	{
		std::string	input = static_cast<std::string>(argv[1]);
		return parseQuotes<T>(input);
	}
	return parseArgs<T>(argv);
}

template <typename T, typename P>
size_t	PmergeMe<T, P>::findPos(size_t pos, T& mainChain, int toInsert)
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

template <typename T, typename P>
void	PmergeMe<T, P>::insertBValues(T& bChain, T& mainChain, P& pairs)
{
	using Iter = typename T::iterator;
	using pairIter = typename P::iterator;
	if (bChain.empty())
		return ;
	pairIter	pos;
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
			Iter	tmp = std::find(mainChain.begin(), mainChain.end(), pos->second);
			match = static_cast<int>(std::distance(mainChain.begin(), tmp));
		}
		else
			match = mainChain.size();
		size_t index = findPos(match, mainChain, bChain[i]);
		mainChain.insert(mainChain.begin() + index, bChain[i]);
	}
}

template <typename T, typename P>
void	PmergeMe<T, P>::fillMainChain(T& mainChain, P& pairs, std::optional<int> odd)
{
	using Iter = typename T::iterator;
	using pairIter = typename P::iterator;
	pairIter	it;
	for (it = pairs.begin(); it != pairs.end(); it++)
	{
		if (it->second == mainChain.front())
			break ;
	}

	mainChain.insert(mainChain.begin(), it->first);
	T	bChain;
	int	mainSize = static_cast<int>(mainChain.size());
	size_t	toInsertAmt = mainSize - 2;
	if (odd)
		toInsertAmt++;
	for (int i = 3; bChain.size() < toInsertAmt; i++)
	{
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
	insertBValues(bChain, mainChain, pairs);
}

template <typename T, typename P>
T	PmergeMe<T, P>::sort(T& inputCont)
{
	using Iter = typename T::iterator;
	Iter	begin = inputCont.begin();
	Iter	next = std::next(begin, 1);
	Iter	end = inputCont.end();
	T	newVector;
	T	mainChain;
	P	pairs;

	if (inputCont.size() < 2)
	{
		mainChain.push_back(inputCont.back());
		return mainChain;
	}
	std::optional<int>	odd = std::nullopt;
	if (inputCont.size() % 2 != 0)
	{
		odd = inputCont.back();
		inputCont.pop_back();
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
	mainChain = sort(newVector);
	fillMainChain(mainChain, pairs, odd);
	return mainChain;
}
