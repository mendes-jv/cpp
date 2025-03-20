#include "PhoneBook.hpp"
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <sstream>

void chooseContact();

int main() { //TODO: change prompt to get info
    std::cout << "Loading...\n";
    sleep(2);
    std::system("clear");
    std::cout << "Welcome to your awesome phonebook!\n";
    sleep(2);
    std::system("clear");
    PhoneBook phoneBook;
    std::string command;
    while (command != "EXIT") {
        std::cout << "What would you like to do? ADD, SEARCH or EXIT?\n";
        std::getline(std::cin, command);
        if (command == "ADD") {
            std::cout << "Adding...\n";
            sleep(2); //TODO: change place
            phoneBook.add();
            continue;
        }
        if (command == "SEARCH") { //TODO: if list empty do ... ? Figure out in subject
            std::cout << "Searching...\n";
            sleep(2); //TODO: change place
            phoneBook.displayAllContacts();
            std::cout << "Please provide the index of the contact you want to display.\n";
            std::string commandIndex;
            std::getline(std::cin, commandIndex);
            std::istringstream indexStream(commandIndex);
            int index;
            if (!(indexStream >> index) || !indexStream.eof()) {
                std::cout << "Text provided is not a number!\n";
                continue;
            }
            if (index < 0 || index >= MAX_CONTACTS) {
                std::cout << "Index out of bounds!\n";
                continue;
            }
            phoneBook.displayContactByIndex(index);
            continue;
        }
        if (command == "EXIT") {
            std::system("clear");
            std::cout << "Exiting...\n";
            sleep(2);
            std::system("clear");
            continue;
        }
        std::cout << "Invalid command. Please provide a valid command.\n";
    }
    return 0;
}
