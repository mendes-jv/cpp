#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include "macros.hpp"

class PhoneBook {
    Contact contacts[MAX_CONTACTS];

    static bool checkElements(const std::string &string, const std::string &last_name, const std::string &nickname,
                               const std::string &phone_number, const std::string &basic_string);

    static std::string truncateField(const std::string &field);

    int searchEmptyContact() const;

public:
    void add();

    void displayAllContacts() const;

    void displayContactByIndex(int index) const;
};

#endif //PHONEBOOK_HPP
