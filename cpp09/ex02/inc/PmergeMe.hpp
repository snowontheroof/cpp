#pragma once
# include <iostream>
# include <sstream>
# include <vector>
# include <deque>

class PmergeMe
{
	private:
		std::vector<int>	vectorSort;
		std::deque<int>		dequeSort;

	public:
		PmergeMe() = default;
		PmergeMe(const PmergeMe& obj) = delete;
		PmergeMe&			operator=(const PmergeMe& other) = delete;
		~PmergeMe() = default;

		void	sortQuotes(std::string input);
		void	sort(char** argv);
};
