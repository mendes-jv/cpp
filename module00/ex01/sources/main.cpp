#include "PhoneBook.hpp"
#include <iostream>

int main(void) {
	std::cout << "Loading...\n";
	sleep(2);
	std::system("clear");
	std::cout << "Welcome to your awesome phonebook!\n";
	sleep(2);
	std::system("clear");
	PhoneBook phoneBook;
	while (1) {
		std::cout << "What would you like to do? ADD, SEARCH or EXIT?\n";
		std::cin.get();
	}
	return 0;
}
