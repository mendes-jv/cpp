#include <Dog.hpp>

Dog::Dog() : Animal() {
  this->_brain = new Brain();
  std::cout << "Dog default constructor called" << std::endl;
  this->_type = "Dog";
}

Dog::Dog(const Dog &other) : Animal(other) {
  std::cout << "Dog copy constructor called" << std::endl;
  this->_brain = new Brain();
  this->_type = other.getType();
  *this = other;
}

Dog &Dog::operator=(const Dog &other) {
  std::cout << "Dog assignment operator called" << std::endl;
  if (this != &other) {
	this->getType() = other.getType();
	if (!this->_brain)
	  this->_brain = new Brain();
  }
  return *this;
}

Dog::~Dog() {
  std::cout << "Dog destructor called" << std::endl;
  delete this->_brain;
}

void Dog::makeSound() const {
  std::cout << "Woof!" << std::endl;
}

std::string Dog::getIdea() const {
  return this->_brain->getIdea();
}

void Dog::setIdea(const std::string &idea) {
  this->_brain->setIdea(idea);
}