#include <iostream>
#include "Contact.hpp"

Contact::Contact()
{
	std::cout << "Contact constructor called" << std::endl;
	return ;
}

Contact::Contact(std::string first_name, std::string last_name, std::string nickname,
	std::string phone_number, std::string darkest_secret)
{
	std::cout << "Contact constructor called" << std::endl;

	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
	return ;
}

Contact::~Contact()
{
	std::cout << "Contact destructor called" << std::endl;
	return ;
}
