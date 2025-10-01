#pragma once
# include <iostream>
# include <vector>
# include <deque>

class PmergeMe
{
	private:
		std::vector<int>	vectorSort;
		std::deque<int>		dequeSort;

	public:
		PmergeMe() = delete;
		PmergeMe(std::string input);
		PmergeMe(const PmergeMe& obj) = delete;
		PmergeMe&			operator=(const PmergeMe& other) = delete;
		~PmergeMe() = default;
};
