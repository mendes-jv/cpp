#include "../includes/Contact.hpp"
#include <iomanip>
#include <iostream>

void Contact::setContactInfo(const std::string &firstName, const std::string &lastName, const std::string &nickname,
                             const std::string &phoneNumber, const std::string &darkestSecret) {
    this->_firstName = firstName;
    this->_lastName = lastName;
    this->_nickname = nickname;
    this->_phoneNumber = phoneNumber;
    this->_darkestSecret = darkestSecret;
}

void Contact::displayContactAsList() const {
    std::cout << std::setw(10) << this->_firstName << "|";
    std::cout << std::setw(10) << this->_lastName << "|";
    std::cout << std::setw(10) << this->_nickname << "|"; //TODO: verify setw need and right-align elements
    std::cout << std::setw(10) << this->_phoneNumber << "|";
    std::cout << std::setw(10) << this->_darkestSecret << std::endl;
}

void Contact::displayContactAsLines() const {
    std::cout << "First name: " << this->_firstName << std::endl;
    std::cout << "Last name: " << this->_lastName << std::endl;
    std::cout << "Nickname: " << this->_nickname << std::endl;
    std::cout << "Phone number: " << this->_phoneNumber << std::endl;
    std::cout << "Darkest secret: " << this->_darkestSecret << std::endl;
}

bool Contact::isContactEmpty() const {
    return this->_firstName.empty();
}
