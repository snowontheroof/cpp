#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact array[8];

	public:
		PhoneBook();
		~PhoneBook();

	void	add_contact_to_phonebook(PhoneBook& MyPhoneBook, int i,
			std::string first_name, std::string last_name, std::string nickname,
			std::string phone_number, std::string darkest_secret);
	void	display_contacts(PhoneBook& MyPhoneBook);
	void	search_contact(PhoneBook& MyPhoneBook);
};

#endif
