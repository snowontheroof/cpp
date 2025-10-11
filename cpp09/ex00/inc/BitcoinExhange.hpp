#pragma once
# include <iostream>
# include <map>
# include <fstream>
# include <exception>
# include <iomanip>
# include <chrono>
# include <sstream>
# include <algorithm>
# include <regex>

class BitcoinExhange
{
	private:
		static std::map<std::string, float>	dataBase;

		BitcoinExhange();
		BitcoinExhange(const BitcoinExhange& obj) = delete;
		BitcoinExhange&	operator=(const BitcoinExhange& other) = delete;

		static void		loadDataBase(std::ifstream& file);
		static void		handleInput(std::ifstream& file);
		static void		displayExhange(void);

	public:
		~BitcoinExhange();

		static void		btc(std::string& inputFile);
};
