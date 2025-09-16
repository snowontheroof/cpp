#pragma once
# include <iostream>
# include <exception>

template <typename T>
class Array
{
	public:
		T*				_array;
		unsigned int	_size;

		Array();
		Array(unsigned int n);
		Array(const Array& obj);
		Array<T>&	operator=(const Array& other);
		~Array();

		unsigned int	size() const;
		T&				operator[](unsigned int i);
};

template <typename T>
Array<T>::Array()
{
	_array = nullptr;
	_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	_array = new T[n]{};
	_size = n;
}

template <typename T>
Array<T>::Array(const Array& obj) : _size(obj._size)
{
	_array = new T[_size]{};
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = obj._array[i];
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		if (_array)
			delete[] _array;
		_size = other._size;
		_array = new T[_size]{};
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = other._array[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete[] _array;
}

template <typename T>
unsigned int	Array<T>::size() const
{
	return _size;
}

template <typename T>
T&	Array<T>::operator[](unsigned int i)
{
	if (i >= _size)
		throw std::out_of_range("Index out of bounds!");
	return _array[i];
}
