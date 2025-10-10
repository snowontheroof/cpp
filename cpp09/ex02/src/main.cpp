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
		auto	vectorStart = std::chrono::high_resolution_clock::now();
		std::vector<int>	res;
		std::vector<int>	vectorCont = vecSorter.parse(argc, argv);
		std::cout << "Before:";
		for (std::vector<int>::iterator it = vectorCont.begin(); it != vectorCont.end(); it++)
			std::cout << " " << *it;
		std::cout << '\n';
		res = vecSorter.sort(vectorCont);
		if (!std::is_sorted(res.begin(), res.end()))
			throw std::runtime_error("Error: sorting failed");
		auto	vectorEnd = std::chrono::high_resolution_clock::now();

		PmergeMe<std::deque<int>, std::deque<std::pair<int, int>>>	deqSorter;
		auto	dequeStart = std::chrono::high_resolution_clock::now();
		std::deque<int>	deqRes;
		std::deque<int>	dequeCont = deqSorter.parse(argc, argv);
		deqRes = deqSorter.sort(dequeCont);
		if (!std::is_sorted(deqRes.begin(), deqRes.end()))
			throw std::runtime_error("Error: sorting failed");
		std::cout << "After:";
		for (std::deque<int>::iterator it = deqRes.begin(); it != deqRes.end(); it++)
			std::cout << " " << *it;
		std::cout << '\n';
		auto	dequeEnd = std::chrono::high_resolution_clock::now();
		std::cout << "Time to process a range of " << deqRes.size()
			<< " elements with std::vector<int>: " << vectorEnd - vectorStart << '\n';
		std::cout << "Comparisons: " << vecSorter.getComparisons() << std::endl;
		std::cout << "Time to process a range of " << deqRes.size()
			<< " elements with std::deque<int>: " << dequeEnd - dequeStart << '\n';
		std::cout << "Comparisons: " << deqSorter.getComparisons() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	return 0;
}
