#include "../includes/Contact.hpp"

void Contact::setContactInfo(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber,
							 std::string darkestSecret) {
	this->_firstName = firstName;
	this->_lastName = lastName;
	this->_nickname = nickname;
	this->_phoneNumber = phoneNumber;
	this->_darkestSecret = darkestSecret;
}

void Contact::displayContact() {
	std::cout << std::setw(10) << this->_firstName << "|";
	std::cout << std::setw(10) << this->_lastName << "|";
	std::cout << std::setw(10) << this->_nickname << "|";
	std::cout << std::setw(10) << this->_phoneNumber << "|";
	std::cout << std::setw(10) << this->_darkestSecret << std::endl;
}

bool Contact::isContactEmpty() {
	return this->_firstName.empty();
}

