#include <Brain.hpp>
#include <iostream>
#include <string>

Brain::Brain(void) {
  std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &src) {
  std::cout << "Brain copy constructor called" << std::endl;
  *this = src;
}

Brain::~Brain(void) {
  std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &src) {
  if (this != &src) {
	std::cout << "Brain assignment operator called" << std::endl;
	*this->ideas = *src.ideas;
  }
  return *this;
}

std::string Brain::getIdea() const {
  return this->ideas[42];
}

void Brain::setIdea(const std::string &new_idea) {
  this->ideas[42] = new_idea;
}
