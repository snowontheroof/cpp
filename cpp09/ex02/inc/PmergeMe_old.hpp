#pragma once
# include <iostream>
# include <sstream>
# include <vector>
# include <deque>
# include <chrono>
# include <cmath>
# include <optional>
# include <algorithm>

template <typename T, typename P>
class PmergeMe
{
	private:
		int	comparisons;
		T	jacobsthalNbs;

		size_t	findPos(size_t pos, T& mainChain, int toInsert);
		void	binarySearchInsert(T& bChain, T& mainChain, P& pairs);
		void	fillBChain(T& bChain, T& mainChain, P& pairs, std::optional<int> odd);
		void	fillMainChain(T& mainChain, P& pairs, std::optional<int> odd);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& obj) = delete;
		PmergeMe&	operator=(const PmergeMe& other) = delete;
		~PmergeMe() = default;

		int		getComparisons() const;

		T		parse(int argc, char** argv);
		T		sort(T& inputSeq);
		void	print(T& seq) const;
};

template <typename T, typename P>
PmergeMe<T, P>::PmergeMe()
{
	comparisons = 0;
	jacobsthalNbs = { 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461,
		10923, 21845, 43691, 87381, 174763, 349525 };
}

template <typename T, typename P>
int	PmergeMe<T, P>::getComparisons() const
{
	return comparisons;
}

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

template <typename T>
static T	parseQuotes(std::string& input)
{
	T					myCont;
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
static T	parseArgs(char **argv)
{
	T		myCont;
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
void	PmergeMe<T, P>::binarySearchInsert(T& bChain, T& mainChain, P& pairs)
{
	using Iter = typename T::iterator;
	using PairIter = typename P::iterator;

	if (bChain.empty())
		return ;
	PairIter	pos;
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
			Iter	tmp = std::find(mainChain.begin(), mainChain.end(),
				pos->second);
			match = static_cast<int>(std::distance(mainChain.begin(), tmp));
		}
		else
			match = mainChain.size();
		size_t	index = findPos(match, mainChain, bChain[i]);
		mainChain.insert(mainChain.begin() + index, bChain[i]);
	}
}

template <typename T, typename P>
void	PmergeMe<T, P>::fillBChain(T& bChain, T& mainChain, P& pairs,
	std::optional<int> odd)
{
	using PairIter = typename P::iterator;

	size_t	toInsert = mainChain.size() - 2;
	if (odd.has_value())
		toInsert++;
	for (int i = 3; bChain.size() < toInsert; i++)
	{
		size_t	curr = jacobsthalNbs[i];
		size_t	prev = jacobsthalNbs[i - 1];
		while (curr > prev)
		{
			if (curr == mainChain.size() && odd.has_value())
				bChain.push_back(*odd);
			else if (curr < mainChain.size())
			{
				for (PairIter it = pairs.begin(); it != pairs.end(); it++)
				{
					if (it->second == mainChain[curr])
					{
						bChain.push_back(it->first);
						break ;
					}
				}
			}
			curr--;
		}
	}
}

template <typename T, typename P>
void	PmergeMe<T, P>::fillMainChain(T& mainChain, P& pairs, std::optional<int> odd)
{
	using PairIter = typename P::iterator;

	PairIter	it;
	T			bChain;

	for (it = pairs.begin(); it != pairs.end(); it++)
	{
		if (it->second == mainChain.front())
			break ;
	}
	mainChain.insert(mainChain.begin(), it->first);
	fillBChain(bChain, mainChain, pairs, odd);
	binarySearchInsert(bChain, mainChain, pairs);
}

template <typename T, typename P>
T	PmergeMe<T, P>::sort(T& inputSeq)
{
	using Iter = typename T::iterator;

	Iter	begin = inputSeq.begin();
	Iter	next = std::next(begin, 1);
	Iter	end = inputSeq.end();
	T		newSeq;
	T		mainChain;
	P		pairs;

	if (inputSeq.size() < 2)
	{
		mainChain.push_back(inputSeq.back());
		return mainChain;
	}
	std::optional<int>	odd = std::nullopt;
	if (inputSeq.size() % 2 != 0)
	{
		odd = inputSeq.back();
		inputSeq.pop_back();
	}
	while (begin != end && next != end)
	{
		if (*begin > *next)
		{
			newSeq.push_back(*begin);
			pairs.push_back({*next, *begin});
		}
		else
		{
			newSeq.push_back(*next);
			pairs.push_back({*begin, *next});
		}
		comparisons++;
		begin += 2;
		next = std::next(begin, 1);
	}
	mainChain = sort(newSeq);
	fillMainChain(mainChain, pairs, odd);
	return mainChain;
}

template <typename T, typename P>
void	PmergeMe<T, P>::print(T& seq) const
{
	using Iter = typename T::iterator;

	for (Iter it = seq.begin(); it != seq.end(); it++)
		std::cout << " " << *it;
	std::cout << '\n';
}
