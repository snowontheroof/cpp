#pragma once
# include <exception>
# include <iostream>

class Test
{
	public:
		int	value;
};

template <typename T> void swap(T& x, T& y)
{
	try
	{
		(void)(x < y);
		(void)(x > y);
		(void)(x <= y);
		(void)(x >= y);
		(void)(x == y);
		(void)(x != y);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << "\n";
		return ;
	}

	T	tmp;

	tmp = x;
	x = y;
	y = tmp;
}

template <typename T> T min(T x, T y)
{
	return (x < y) ? x : y;
}

template <typename T> T max(T x, T y)
{
	return (x > y) ? x : y;
}
