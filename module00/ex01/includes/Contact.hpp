#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
//#include <iostream>
//#include <iomanip>
//#include <stdlib.h>
//#include <unistd.h>
//#include <sstream>

class Contact {
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _darkestSecret;
	public:
		void setContactInfo(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber,
							std::string darkestSecret);
		void displayContact();
		bool isContactEmpty();
};

#endif //CONTACT_HPP
