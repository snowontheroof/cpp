#include <iostream>
#include "Contact.hpp"

Contact::Contact()
{
	_IsSet = false;
}

Contact::Contact(std::string first_name, std::string last_name, std::string nickname,
	std::string phone_number, std::string darkest_secret, bool is_set)
{
	_FirstName = first_name;
	_LastName = last_name;
	_Nickname = nickname;
	_PhoneNumber = phone_number;
	_DarkestSecret = darkest_secret;
	_IsSet = is_set;
}

Contact::~Contact()
{
}

std::string	Contact::getFirstName() const
{
	return (_FirstName);
}

std::string	Contact::getLastName() const
{
	return (_LastName);
}

std::string	Contact::getNickname() const
{
	return (_Nickname);
}

std::string	Contact::getPhoneNumber() const
{
	return (_PhoneNumber);
}

std::string	Contact::getDarkestSecret() const
{
	return (_DarkestSecret);
}

bool	Contact::getIsSet() const
{
	return (_IsSet);
}
