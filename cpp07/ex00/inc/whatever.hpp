#pragma once
# include <exception>
# include <iostream>
# include <concepts>

class Example
{
	public:
		int	value;
};

std::ostream&	operator<<(std::ostream& os, const Example& obj)
{
	os << obj.value;
	return os;
}

template <typename T>
concept Convertible = requires(T a, T b)
{
	{ a < b } -> std::convertible_to<bool>;
	{ a > b } -> std::convertible_to<bool>;
	{ a <= b } -> std::convertible_to<bool>;
	{ a >= b }  -> std::convertible_to<bool>;
	{ a == b }  -> std::convertible_to<bool>;
	{ a != b }  -> std::convertible_to<bool>;
};

template <Convertible T>
void swap(T& a, T& b)
{
	T	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template <Convertible T>
T min(T a, T b)
{
	if (a < b)
		return a;
	return b;
}

template <Convertible T>
T max(T a, T b)
{
	if (a > b)
		return a;
	return b;
}
