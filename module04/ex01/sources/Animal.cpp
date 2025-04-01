#include <Animal.hpp>
#include <iostream>

Animal::Animal() : _type("Animal") {
  std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &other) {
  std::cout << "Animal copy constructor called" << std::endl;
  *this = other;
}

Animal &Animal::operator=(const Animal &other) {
  std::cout << "Animal assignment operator called" << std::endl;
  if (this != &other) {
	this->getType() = other.getType();
  }
  return *this;
}

Animal::~Animal() {
  std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const {
  return this->_type;
}

void Animal::makeSound() const {
  std::cout << "Animal makeSound called" << std::endl;
}
