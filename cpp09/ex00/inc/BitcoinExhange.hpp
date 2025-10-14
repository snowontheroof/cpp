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

		BitcoinExhange() = delete;
		BitcoinExhange(const BitcoinExhange& obj) = delete;
		BitcoinExhange&	operator=(const BitcoinExhange& other) = delete;
		~BitcoinExhange() = delete;

		static void		loadDataBase(std::ifstream& file);
		static void		handleInput(std::ifstream& file);

	public:
		static void		btc(std::string& inputFile);
};
