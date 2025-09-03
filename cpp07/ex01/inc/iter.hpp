#pragma once
# include <cstdint>

template <typename T> void iter(T* array, int length, void (*f)(T element))
{
	for (int i = 0; i < length; i++)
	{
		f(array[i]);
	}
}
