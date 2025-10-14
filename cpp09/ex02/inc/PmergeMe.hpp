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
		int	comparisons;
		T	jacobsthalNbs;

		size_t	binarySearch(size_t pos, T& mainChain, int toInsert);
		void	fillMainWithB(T& bChain, T& mainChain, std::unordered_map<int, int>& pairs);
		void	fillBChain(T& bChain, T& mainChain, std::unordered_map<int, int>& pairs, std::optional<int> odd);
		void	fillMainChain(T& mainChain, std::unordered_map<int, int>& pairs, std::optional<int> odd);

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
size_t	PmergeMe<T>::binarySearch(size_t pos, T& mainChain, int toInsert)
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

template <typename T>
void	PmergeMe<T>::fillMainWithB(T& bChain, T& mainChain,
	std::unordered_map<int, int>& pairs)
{
	using Iter = typename T::iterator;

	if (bChain.empty())
		return ;
	for (size_t i = 0; i < bChain.size(); i++)
	{
		size_t	match;
		Iter	it;
		for (it = mainChain.begin(); it != mainChain.end(); it++)
		{
			if (pairs[*it] == bChain[i])
				break ;
		}
		if (it != mainChain.end())
			match = std::distance(mainChain.begin(), it);
		else
			match = mainChain.size();
		size_t	index = binarySearch(match, mainChain, bChain[i]);
		mainChain.insert(mainChain.begin() + index, bChain[i]);
	}
}

template <typename T>
void	PmergeMe<T>::fillBChain(T& bChain, T& mainChain, std::unordered_map<int, int>& pairs,
	std::optional<int> odd)
{
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
				bChain.push_back(pairs[mainChain[curr]]);
			curr--;
		}
	}
}

template <typename T>
void	PmergeMe<T>::fillMainChain(T& mainChain, std::unordered_map<int, int>& pairs,
		std::optional<int> odd)
{
	T	bChain;

	mainChain.insert(mainChain.begin(), pairs[mainChain.front()]);
	fillBChain(bChain, mainChain, pairs, odd);
	fillMainWithB(bChain, mainChain, pairs);
}

template <typename T>
T	PmergeMe<T>::sort(T& inputSeq)
{
	using Iter = typename T::iterator;

	Iter	begin = inputSeq.begin();
	Iter	next = std::next(begin, 1);
	Iter	end = inputSeq.end();
	T		newSeq;
	T		mainChain;
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
void	PmergeMe<T>::print(T& seq) const
{
	using Iter = typename T::iterator;

	for (Iter it = seq.begin(); it != seq.end(); it++)
		std::cout << " " << *it;
	std::cout << '\n';
}
