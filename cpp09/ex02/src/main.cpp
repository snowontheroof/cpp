#include "../inc/PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "Usage: ./PmergeMe <sequence of positive integers>\n";
		return 0;
	}
	try
	{
		auto	vecStart = std::chrono::high_resolution_clock::now();
		PmergeMe<std::vector<int>>	vecSorter;
		std::vector<int>	vecCont = vecSorter.parse(argc, argv);
		if (vecCont.size() == 0)
		{
			std::cout << "Usage: ./PmergeMe <sequence of positive integers>\n";
			return 0;
		}
		std::cout << "Before:";
		vecSorter.print(vecCont);
		std::vector<int>	vecRes = vecSorter.sort(vecCont);
		if (!std::is_sorted(vecRes.begin(), vecRes.end()))
			throw std::runtime_error("Error: sorting failed");
		auto	vecEnd = std::chrono::high_resolution_clock::now();

		auto	deqStart = std::chrono::high_resolution_clock::now();
		PmergeMe<std::deque<int>>	deqSorter;
		std::deque<int>	deqCont = deqSorter.parse(argc, argv);
		std::deque<int>	deqRes = deqSorter.sort(deqCont);
		if (!std::is_sorted(deqRes.begin(), deqRes.end()))
			throw std::runtime_error("Error: sorting failed");
		std::cout << "After:";
		deqSorter.print(deqRes);
		auto	deqEnd = std::chrono::high_resolution_clock::now();

		std::cout << "Time to process a range of " << vecRes.size()
			<< " elements with std::vector<int>: " << vecEnd - vecStart << '\n';
		std::cout << "Time to process a range of " << deqRes.size()
			<< " elements with std::deque<int>: " << deqEnd - deqStart << '\n';
		// std::cout << "Comparisons: std::vector<int> " << vecSorter.getComparisons()
		// 	<< ", std::deque<int> " << deqSorter.getComparisons() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
