#include "Data.hpp"

Data::Data() : value(0)
{
}

Data::Data(const Data& obj) : value(obj.value)
{
}

Data&	Data::operator=(const Data& other)
{
	if (this != &other)
		value = other.value;
	return *this;
}

Data::~Data()
{
}