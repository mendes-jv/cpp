#include <AAnimal.hpp>
#include <iostream>

AAnimal::AAnimal() : _type("AAnimal") {
  std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other) {
  std::cout << "AAnimal copy constructor called" << std::endl;
  *this = other;
}

AAnimal &AAnimal::operator=(const AAnimal &other) {
  std::cout << "AAnimal assignment operator called" << std::endl;
  if (this != &other) {
	this->getType() = other.getType();
  }
  return *this;
}

AAnimal::~AAnimal() {
  std::cout << "AAnimal destructor called" << std::endl;
}

std::string AAnimal::getType() const {
  return this->_type;
}
