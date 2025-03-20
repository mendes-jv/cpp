#include "../includes/PhoneBook.hpp"

#include <iostream>

std::string PhoneBook::truncateField(const std::string &field) {
    if (field.length() > 10)
        return field.substr(0, 9) + ".";
    return field;
}

int PhoneBook::searchEmptyContact() const {
    for (int i = 0; i < MAX_CONTACTS; i++)
        if (this->contacts[i].isContactEmpty())
            return i;
    return 0;
}

void PhoneBook::add() {
    std::cout << "Enter contact's first name:";
    std::string firstName;
    std::getline(std::cin, firstName);
    firstName = truncateField(firstName);
    std::cout << "Enter contact's last name:";
    std::string lastName;
    std::getline(std::cin, lastName);
    lastName = truncateField(lastName);
    std::cout << "Enter contact's nickname:";
    std::string nickname;
    std::getline(std::cin, nickname);
    nickname = truncateField(nickname);
    std::cout << "Enter contact's phone number:";
    std::string phoneNumber;
    std::getline(std::cin, phoneNumber);
    phoneNumber = truncateField(phoneNumber);
    std::cout << "Enter contact's darkest secret:";
    std::string darkestSecret;
    std::getline(std::cin, darkestSecret);
    darkestSecret = truncateField(darkestSecret);
    if (firstName.empty() || lastName.empty() || nickname.empty() || phoneNumber.empty() || darkestSecret.empty()) {
        std::cout << "One or more fields are empty! Please provide all the required information.\n";
        return;
    }
    const int index = this->searchEmptyContact();
    this->contacts[index].setContactInfo(firstName, lastName, nickname, phoneNumber, darkestSecret);
    std::cout << "Contact added successfully in index " << index << "!\n";
}

void PhoneBook::displayAllContacts() const {
    for (int i = 0; i < MAX_CONTACTS; i++) {
        if (this->contacts[i].isContactEmpty())
            return;
        this->contacts[i].displayContactAsList();
    }
}

void PhoneBook::displayContactByIndex(const int index) const {
    if (this->contacts[index].isContactEmpty()) {
        std::cout << "This Contact is empty!\n";
        return;
    }
    this->contacts[index].displayContactAsLines();
}
