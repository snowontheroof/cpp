#pragma once
# include <iostream>
# include <sstream>
# include <vector>
# include <deque>
# include <chrono>
# include <cmath>
# include <optional>
# include <algorithm>
# include <unordered_map>

template <typename T>
class PmergeMe
{
	private:
		int			comparisons;
		T			jacobsthalNbs;

		size_t		binarySearch(size_t pos, T& mainChain, int toInsert);
		void		jacobsthalInsert(T& pendChain, T& mainChain,
						std::unordered_map<int, int>& pairs);
		void		fillMainChain(T& mainChain, std::unordered_map<int, int>& pairs,
						std::optional<int> odd);
		T			splitPairs(T& inputSeq);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& obj) = delete;
		PmergeMe&	operator=(const PmergeMe& other) = delete;
		~PmergeMe() = default;

		int			getComparisons() const;

		T			parse(int argc, char** argv);
		T			sort(T& inputSeq);
		void		print(T& seq) const;
};

bool	isValidNb(std::string& nb);

template <typename T>
PmergeMe<T>::PmergeMe()
{
	comparisons = 0;
	jacobsthalNbs = { 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461,
		10923, 21845, 43691, 87381, 174763, 349525 };
}

template <typename T>
int	PmergeMe<T>::getComparisons() const
{
	return comparisons;
}

template <typename T>
static T	parseQuotes(std::string& input)
{
	T					parsedCont;
	std::istringstream	ss(input);
	std::string			token;
	int					nb;

	while (ss >> token)
	{
		if (!isValidNb(token))
			throw std::runtime_error("Error");
		try
		{
			nb = std::stoi(token);
		}
		catch (const std::exception& e)
		{
			throw std::runtime_error("Error");
		}
		parsedCont.push_back(nb);
	}
	return parsedCont;
}

template <typename T>
static T	parseArgs(char **argv)
{
	T		parsedCont;
	size_t	i = 1;
	int		nb;

	while (argv[i])
	{
		std::string	arg = static_cast<std::string>(argv[i]);
		if (!isValidNb(arg))
			throw std::runtime_error("Error");
		try
		{
			nb = std::stoi(arg);
		}
		catch (const std::exception& e)
		{
			throw std::runtime_error("Error");
		}
		parsedCont.push_back(nb);
		i++;
	}
	return parsedCont;
}

template <typename T>
T	PmergeMe<T>::parse(int argc, char **argv)
{
	if (argc == 2)
	{
		std::string	input = static_cast<std::string>(argv[1]);
		return parseQuotes<T>(input);
	}
	return parseArgs<T>(argv);
}

template <typename T>
size_t	PmergeMe<T>::binarySearch(size_t end, T& mainChain, int toInsert)
{
	size_t	start = 0;

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

template <typename T>
void	PmergeMe<T>::jacobsthalInsert(T& pendChain, T& mainChain,
	std::unordered_map<int, int>& pairs)
{
	using Iter = typename T::iterator;
	size_t	j = 1;

	for (int i = 3; j < pendChain.size(); i++)
	{
		size_t	curr = jacobsthalNbs[i] - 1;
		size_t	prev = jacobsthalNbs[i - 1] - 1;
		while (curr > prev)
		{
			if (curr < pendChain.size())
			{
				size_t	rangeEnd;
				Iter	it;
				for (it = mainChain.begin(); it != mainChain.end(); it++)
				{
					if (pairs[*it] == pendChain[curr])
						break ;
				}
				if (it != mainChain.end())
					rangeEnd = std::distance(mainChain.begin(), it);
				else
					rangeEnd = mainChain.size();
				size_t	index = binarySearch(rangeEnd, mainChain, pendChain[curr]);
				mainChain.insert(mainChain.begin() + index, pendChain[curr]);
				j++;
			}
			curr--;
		}
	}
}

template <typename T>
void	PmergeMe<T>::fillMainChain(T& mainChain, std::unordered_map<int, int>& pairs,
	std::optional<int> odd)
{
	T	pendChain;

	mainChain.insert(mainChain.begin(), pairs[mainChain.front()]);
	for (size_t i = 1; mainChain[i]; i++)
		pendChain.push_back(pairs[mainChain[i]]);
	if (odd.has_value())
		pendChain.push_back(odd.value());
	jacobsthalInsert(pendChain, mainChain, pairs);
}

template <typename T>
T	PmergeMe<T>::splitPairs(T& inputSeq)
{
	using Iter = typename T::iterator;

	Iter							begin = inputSeq.begin();
	Iter							next = std::next(begin, 1);
	Iter							end = inputSeq.end();
	T								newSeq;
	T								mainChain;
	std::unordered_map<int, int>	pairs;

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
			pairs[*begin] = *next;
		}
		else
		{
			newSeq.push_back(*next);
			pairs[*next] = *begin;
		}
		comparisons++;
		begin += 2;
		next = std::next(begin, 1);
	}
	mainChain = sort(newSeq);
	fillMainChain(mainChain, pairs, odd);
	return mainChain;
}

template <typename T>
T	PmergeMe<T>::sort(T& inputSeq)
{
	return splitPairs(inputSeq);
}

template <typename T>
void	PmergeMe<T>::print(T& seq) const
{
	using Iter = typename T::iterator;

	for (Iter it = seq.begin(); it != seq.end(); it++)
		std::cout << " " << *it;
	std::cout << '\n';
}
