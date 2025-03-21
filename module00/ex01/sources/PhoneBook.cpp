#include "../includes/PhoneBook.hpp"

#include <iomanip>
#include <iostream>
#include <unistd.h>

int PhoneBook::searchEmptyContact() {
    for (int i = 0; i < MAX_CONTACTS; i++)
        if (this->contacts[i].isContactEmpty())
            return i;
    return _oldestIndex++ % MAX_CONTACTS;
}

void PhoneBook::add() {
    std::cout << "Enter contact's first name:";
    std::string firstName;
    std::getline(std::cin, firstName);
    std::cout << "Enter contact's last name:";
    std::string lastName;
    std::getline(std::cin, lastName);
    std::cout << "Enter contact's nickname:";
    std::string nickname;
    std::getline(std::cin, nickname);
    std::cout << "Enter contact's phone number:";
    std::string phoneNumber;
    std::getline(std::cin, phoneNumber);
    std::cout << "Enter contact's darkest secret:";
    std::string darkestSecret;
    std::getline(std::cin, darkestSecret);
    if (firstName.empty() || lastName.empty() || nickname.empty() || phoneNumber.empty() || darkestSecret.empty()) {
        std::cout << "One or more fields are empty! Please provide all the required information.\n";
        return;
    }
    const int index = this->searchEmptyContact();
    this->contacts[index].setContactInfo(firstName, lastName, nickname, phoneNumber, darkestSecret);
    std::cout << "Contact added successfully in index " << index << "!\n";
}

bool PhoneBook::displayAllContacts() const {
    if (this->contacts[0].isContactEmpty()) {
        std::cout << "No contacts to display! Please add a contact first.\n";
        return false;
    }
    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First name" << "|";
    std::cout << std::setw(10) << "Last name" << "|";
    std::cout << std::setw(10) << "Nickname" << "\n";
    for (int i = 0; i < MAX_CONTACTS; i++) {
        if (this->contacts[i].isContactEmpty())
            return true;
        this->contacts[i].displayContactAsList(i);
    }
    return true;
}

void PhoneBook::displayContactByIndex(const int &index) const {
    if (this->contacts[index].isContactEmpty()) {
        std::cout << "This Contact is empty!\n";
        return;
    }
    this->contacts[index].displayContactAsLines();
}
