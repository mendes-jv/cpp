#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact {
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _darkestSecret;

public:
    void setContactInfo(const std::string &firstName, const std::string &lastName, const std::string &nickname,
                        const std::string &phoneNumber, const std::string &darkestSecret);

    void displayContactAsLines() const;

    void displayContactAsList(const int &index) const;

    bool isContactEmpty() const;

    static std::string truncateField(const std::string &field);
};

#endif //CONTACT_HPP
