#include <Fixed.hpp>
#include <iostream>
#include <cmath>

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _numberValue(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
  std::cout << "Copy constructor called" << std::endl;
  *this = other;
}

Fixed::Fixed(const int number) {
  std::cout << "Int constructor called" << std::endl;
  this->_numberValue = number << this->_fractionalBits;
}

Fixed::Fixed(const float number) {
  std::cout << "Float constructor called" << std::endl;
  this->_numberValue = static_cast<int>(roundf(number * (1 << this->_fractionalBits)));
}

Fixed &Fixed::operator=(const Fixed &other) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other) {
	this->_numberValue = other.getRawBits();
  }
  return *this;
}

Fixed::~Fixed() {
  std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
  std::cout << "getRawBits member function called" << std::endl;
  return this->_numberValue;
}

void Fixed::setRawBits(const int raw) {
  std::cout << "setRawBits member function called" << std::endl;
  this->_numberValue = raw;
}

int Fixed::toInt() const {
  return this->_numberValue >> this->_fractionalBits;
}

float Fixed::toFloat() const {
  return static_cast<float>(this->_numberValue) / (1 << this->_fractionalBits);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
  os << fixed.toFloat();
  return os;
}