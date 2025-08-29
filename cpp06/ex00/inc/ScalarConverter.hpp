#pragma once
# include <iostream>

enum t_type
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
	public:
		static void	convert(std::string input);
};