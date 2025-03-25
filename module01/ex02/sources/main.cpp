#include <iostream>

int main() {
    std::string brain = "HI THIS IS BRAIN";

    const std::string *stringPTR = &brain;
    const std::string &stringREF = brain;

    std::cout << "Addresses:" << std::endl;
    std::cout << &brain << std::endl;
    std::cout << stringPTR << std::endl;
    std::cout << &stringREF << std::endl;

    std::cout << "\nValues:" << std::endl;
    std::cout << brain << std::endl;
    std::cout << *stringPTR << std::endl;
    std::cout << stringREF << std::endl;
}
