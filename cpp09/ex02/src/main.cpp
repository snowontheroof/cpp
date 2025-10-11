#include "../inc/PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "Expected usage: ./PmergeMe <sequence of positive integers>\n";
		return 0;
	}
	try
	{
		std::string	argQuotes = static_cast<std::string>(argv[1]);

		PmergeMe<std::vector<int>, std::vector<std::pair<int, int>>>	vecSorter;
		auto	vecStart = std::chrono::high_resolution_clock::now();
		std::vector<int>	vecCont = vecSorter.parse(argc, argv);
		std::cout << "Before:";
		vecSorter.print(vecCont);
		std::vector<int>	vecRes = vecSorter.sort(vecCont);
		if (!std::is_sorted(vecRes.begin(), vecRes.end()))
			throw std::runtime_error("Error: sorting failed");
		auto	vecEnd = std::chrono::high_resolution_clock::now();

		PmergeMe<std::deque<int>, std::deque<std::pair<int, int>>>	deqSorter;
		auto	deqStart = std::chrono::high_resolution_clock::now();
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
		// std::cout << "Comparisons: " << deqSorter.getComparisons() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	return 0;
}
