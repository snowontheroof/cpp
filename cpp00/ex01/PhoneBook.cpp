#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::add_contact_to_phonebook(PhoneBook& MyPhoneBook, int i,
			std::string first_name,	std::string last_name, std::string nickname,
			std::string phone_number, std::string darkest_secret)
{
	MyPhoneBook.array[i] = Contact(first_name, last_name,
		nickname, phone_number, darkest_secret, true);
}

void	PhoneBook::display_contacts(PhoneBook& MyPhoneBook)
{
	std::cout << std::setw(10) << "Index";
	std::cout << "|" << std::setw(10) << "First name";
	std::cout << "|" << std::setw(10) << "Last name";
	std::cout << "|" << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (!MyPhoneBook.array[i].getIsSet())
			continue ;
		std::cout << std::setw(10) << i + 1 << "|";
		if ((MyPhoneBook.array[i].getFirstName()).length() > 10)
			std::cout << (MyPhoneBook.array[i].getFirstName()).substr(0, 9) << "." << "|";
		else
			std::cout << std::setw(10) << MyPhoneBook.array[i].getFirstName() << "|";
		if ((MyPhoneBook.array[i].getLastName()).length() > 10)
			std::cout << (MyPhoneBook.array[i].getLastName()).substr(0, 9) << "." << "|";
		else
			std::cout << std::setw(10) << MyPhoneBook.array[i].getLastName() << "|";
		if ((MyPhoneBook.array[i].getNickname()).length() > 10)
			std::cout << (MyPhoneBook.array[i].getNickname()).substr(0, 9) << "." << std::endl;
		else
			std::cout << std::setw(10) << MyPhoneBook.array[i].getNickname() << std::endl;
	}
	return ;
}

void	PhoneBook::search_contact(PhoneBook& MyPhoneBook)
{
	std::string index;
	int i;

	if (!MyPhoneBook.array[0].getIsSet())
	{
		std::cout << "There are no contacts in the phonebook! Please add some!" << std::endl;
		return ;
	}
	MyPhoneBook.display_contacts(MyPhoneBook);
	std::cout << "Please give me the index of the contact you're looking for: ";
	if (!std::getline(std::cin, index))
	{
		std::cout << "\nExiting phonebook" << std::endl;
		exit(0);
	}
	if (index.length() != 1 || index[0] < '0' || index[0] > '9')
	{
		std::cerr << "That is not a valid index number!" << std::endl;
		return ;
	}
	i = std::stoi(index);
	if (!MyPhoneBook.array[i].getIsSet())
	{
		std::cerr << "Unfortunately there is no contact saved at that index!" << std::endl;
		return ;
	}
	std::cout << "First name: " << MyPhoneBook.array[i].getFirstName() << std::endl;
	std::cout << "Last name: " << MyPhoneBook.array[i].getLastName() << std::endl;
	std::cout << "Nickname: " << MyPhoneBook.array[i].getNickname() << std::endl;
	std::cout << "Phone number: " << MyPhoneBook.array[i].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << MyPhoneBook.array[i].getDarkestSecret() << std::endl;
	return ;
}
