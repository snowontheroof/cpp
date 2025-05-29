#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"

class PhoneBook
{
	public:
		Contact array[8];

		PhoneBook();
		~PhoneBook();
};

#endif
