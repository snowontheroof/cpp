#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
# include <iostream>
# include <iomanip>

class PhoneBook
{
	private:
		Contact array[8];

		void	displayContacts(PhoneBook MyPhoneBook) const;

	public:
		PhoneBook();
		~PhoneBook();

		void	setContact(PhoneBook& MyPhoneBook, int i,
				std::string first_name, std::string last_name, std::string nickname,
				std::string phone_number, std::string darkest_secret);
		void	searchContact(PhoneBook MyPhoneBook) const;
};

#endif
