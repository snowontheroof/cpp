#include <iostream>
#include <iomanip>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"

void	add_contact(PhoneBook& MyAwesomePhoneBook, int& i)
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	if (i == 8)
		i = 0;
	std::cout << "Let's add a new contact! Please give me some info:" << std::endl;
	std::cout << "First name: ";
	std::cin >> first_name;
	std::cout << "Last name: ";
	std::cin >> last_name;
	std::cout << "Nickname: ";
	std::cin >> nickname;
	std::cout << "Phone number: ";
	std::cin >> phone_number;
	std::cin.ignore(1, '\n');
	std::cout << "Darkest secret: ";
	std::getline(std::cin, darkest_secret);
	MyAwesomePhoneBook.array[i] = Contact(first_name, last_name,
		nickname, phone_number, darkest_secret);
	i++;
	return ;
}

void	search_contact(PhoneBook& MyAwesomePhoneBook)
{
	std::string index;
	std::string spaces;
	unsigned int srch_i;

	std::cout << std::setw(10) << "Index";
	std::cout << "|" << std::setw(10) << "First name";
	std::cout << "|" << std::setw(10) << "Last name";
	std::cout << "|" << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << std::setw(10) << i << "|";
		if (MyAwesomePhoneBook.array[i].first_name.length() > 10)
			std::cout << MyAwesomePhoneBook.array[i].first_name.substr(0, 9) << "." << "|";
		else
			std::cout << std::setw(10) << MyAwesomePhoneBook.array[i].first_name << "|";
		if (MyAwesomePhoneBook.array[i].last_name.length() > 10)
			std::cout << MyAwesomePhoneBook.array[i].last_name.substr(0, 9) << "." << "|";
		else
			std::cout << std::setw(10) << MyAwesomePhoneBook.array[i].last_name << "|";
		if (MyAwesomePhoneBook.array[i].nickname.length() > 10)
			std::cout << MyAwesomePhoneBook.array[i].nickname.substr(0, 9) << "." << std::endl;
		else
			std::cout << std::setw(10) << MyAwesomePhoneBook.array[i].nickname << std::endl;
	}
	std::cout << "Please give me the index of the contact you're looking for: ";
	std::cin >> index;
	srch_i = std::stoul(index);
	std::cout << "First name: " << MyAwesomePhoneBook.array[srch_i].first_name << std::endl;
	std::cout << "Last name: " << MyAwesomePhoneBook.array[srch_i].last_name << std::endl;
	std::cout << "Nickname: " << MyAwesomePhoneBook.array[srch_i].nickname << std::endl;
	std::cout << "Phone number: " << MyAwesomePhoneBook.array[srch_i].phone_number << std::endl;
	std::cout << "Darkest secret: " << MyAwesomePhoneBook.array[srch_i].darkest_secret << std::endl;
	std::cin.ignore(1, '\n');
	return ;
}

int	main(int argc, char **argv)
{
	std::string buf;
	PhoneBook MyAwesomePhoneBook;
	int	i = 0;

	(void)argv;
	if (argc != 1)
		std::cout << "No arguments accepted at this point" << std::endl;
	else
	{
		while (1)
		{
			std::cout << "What should we do? ADD, SEARCH or EXIT?" << std::endl;
			std::getline(std::cin, buf);
			if (buf == "ADD")
				add_contact(MyAwesomePhoneBook, i);
			else if (buf == "SEARCH")
				search_contact(MyAwesomePhoneBook);
			else if (buf == "EXIT")
				break ;
			else
				std::cout << "Invalid prompt!" << std::endl;
		}
	}
	return 0;
}
