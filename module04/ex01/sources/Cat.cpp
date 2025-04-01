#include <Cat.hpp>

Cat::Cat() : Animal() {
  this->_brain = new Brain();
  std::cout << "Cat default constructor called" << std::endl;
  this->_type = "Cat";
}

Cat::Cat(const Cat &other) : Animal(other) {
  std::cout << "Cat copy constructor called" << std::endl;
  this->_brain = new Brain();
  this->_type = other.getType();
  *this = other;
}

Cat &Cat::operator=(const Cat &other) {
  std::cout << "Cat assignment operator called" << std::endl;
  if (this != &other) {
	this->getType() = other.getType();
	if (!this->_brain)
	  this->_brain = new Brain(*other._brain);
  }
  return *this;
}

Cat::~Cat() {
  std::cout << "Cat destructor called" << std::endl;
  delete this->_brain;
}

void Cat::makeSound() const {
  std::cout << "Meow!" << std::endl;
}

std::string Cat::getIdea() const {
  return this->_brain->getIdea();
}

void Cat::setIdea(const std::string &idea) {
  this->_brain->setIdea(idea);
}