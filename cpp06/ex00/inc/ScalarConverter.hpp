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
	public:
		static void	convert(std::string input);
};

void	tests();
