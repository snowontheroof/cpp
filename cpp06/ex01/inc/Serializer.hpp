#pragma once
# include <iostream>
# include <cstdint>
# include "Data.hpp"

class Serializer
{
	public:
		uintptr_t	serialize(Data* ptr);
		Data*		deserialize(uintptr_t raw);
};