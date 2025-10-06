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
		PmergeMe	sorter;
		std::vector<int>	res;
		std::string	argQuotes = static_cast<std::string>(argv[1]);

		auto	vectorStart = std::chrono::high_resolution_clock::now();
		std::vector<int>	vectorCont;
		if (argc == 2)
			vectorCont = sorter.parseQuotes<std::vector<int>>(argQuotes);
		else
			vectorCont = sorter.parse<std::vector<int>>(argv);
		res = sorter.sortVector(vectorCont);
		for (std::vector<int>::iterator it = res.begin(); it != res.end(); it++)
			std::cout << *it << std::endl;
		auto	vectorEnd = std::chrono::high_resolution_clock::now();
		std::cout << vectorEnd - vectorStart << "\n\n";

		auto	dequeStart = std::chrono::high_resolution_clock::now();
		std::deque<int>	dequeCont;
		if (argc == 2)
			dequeCont = sorter.parseQuotes<std::deque<int>>(argQuotes);
		else
			dequeCont = sorter.parse<std::deque<int>>(argv);
		// sorter.sortDeque(dequeCont);
		auto	dequeEnd = std::chrono::high_resolution_clock::now();
		std::cout << dequeEnd - dequeStart << "\n\n";
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	return 0;
}
