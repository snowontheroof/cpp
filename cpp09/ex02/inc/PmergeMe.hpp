#pragma once
# include <iostream>
# include <sstream>
# include <vector>
# include <deque>
# include <chrono>
# include <cmath>
# include <optional>
# include <algorithm>

class PmergeMe
{
	private:
		static int				comparisons;
		static std::vector<int>	jacobsthalNbs;

		public:
		PmergeMe() = default;
		PmergeMe(const PmergeMe& obj) = delete;
		PmergeMe&	operator=(const PmergeMe& other) = delete;
		~PmergeMe() = default;


		template <typename T>
		static T	parseQuotes(std::string& input);

		template <typename T>
		static T	parse(char** argv);

		std::vector<int>	sortVector(std::vector<int>& myVector);
		// void		sortDeque(std::deque<int>& myDeque);
		static bool		isValidNb(std::string& nb);
};

#include "../src/PmergeMe.tpp"
