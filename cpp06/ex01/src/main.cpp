#include "Serializer.hpp"

int	main(void)
{
	Data	object;

	uintptr_t	raw = Serializer::serialize(&object);
	std::cout << &object << std::endl;
	std::cout << "0x" << std::hex << raw << std::endl;

	Data*	ptr = Serializer::deserialize(raw);
	std::cout << ptr << std::endl;

	return 0;
}
