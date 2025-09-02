#pragma once
# include <iostream>
# include <limits>

enum e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO,
	INVALID
};

class	ScalarConverter
{
	private:
		ScalarConverter() = delete;
		ScalarConverter(const ScalarConverter& obj) = delete;
		ScalarConverter&	operator=(const ScalarConverter& other) = delete;
		~ScalarConverter() = delete;

	public:
		static void	convert(std::string input);
};

void	tests(void);
