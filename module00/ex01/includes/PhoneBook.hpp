#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include "macros.hpp"

class PhoneBook {
    Contact contacts[MAX_CONTACTS];
    int _oldestIndex;

    static bool checkElements(const std::string &string, const std::string &last_name, const std::string &nickname,
                              const std::string &phone_number, const std::string &basic_string);

    int searchEmptyContact();

public:
    PhoneBook() : _oldestIndex(0) {
    }

    void add();

    bool displayAllContacts() const;

    void displayContactByIndex(const int &index) const;
};

#endif //PHONEBOOK_HPP
