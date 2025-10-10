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
		int					comparisons;
		std::vector<int>	jacobsthalNbs;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& obj) = delete;
		PmergeMe&	operator=(const PmergeMe& other) = delete;
		~PmergeMe() = default;

		T		parse(int argc, char** argv);
		T		sort(T& inputCont);
		size_t	findPos(size_t pos, T& mainChain, int toInsert);
		void	insertBValues(T& bChain, T& mainChain, P& pairs);
		void	fillMainChain(T& mainChain, P& pairs, std::optional<int> odd);
		int		getComparisons();
};

#include "../src/PmergeMe.tpp"
