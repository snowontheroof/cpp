#pragma once
# include <exception>
# include <iostream>
# include <concepts>

class Test
{
	public:
		int	value;
};

std::ostream&	operator<<(std::ostream& os, const Test& obj)
{
	os << obj.value << " is value";
	return os;
}

template <typename T>
concept Convertible = requires(T x, T y)
{
	{ x < y } -> std::convertible_to<bool>;
	{ x > y } -> std::convertible_to<bool>;
	{ x <= y } -> std::convertible_to<bool>;
	{ x >= y }  -> std::convertible_to<bool>;
	{ x == y }  -> std::convertible_to<bool>;
	{ x != y }  -> std::convertible_to<bool>;
};

template <Convertible T>
void swap(T& x, T& y)
{
	T	tmp;

	tmp = x;
	x = y;
	y = tmp;
}

template <Convertible T>
T min(T x, T y)
{
	return (x < y) ? x : y;
}

template <Convertible T>
T max(T x, T y)
{
	return (x > y) ? x : y;
}
