#include <ClapTrap.hpp>
#include <iostream>

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::cout << "Name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
  std::cout << "Copy constructor called" << std::endl;
  *this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other) {
	_name = other.getName();
	_hitPoints = other.getHitPoints();
	_energyPoints = other.getEnergyPoints();
	_attackDamage = other.getAttackDamage();
  }
  return *this;
}

ClapTrap::~ClapTrap() {
  std::cout << "Destructor called" << std::endl;
}

std::string ClapTrap::getName() const {
  return _name;
}

unsigned int ClapTrap::getHitPoints() const {
  return _hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const {
  return _energyPoints;
}

unsigned int ClapTrap::getAttackDamage() const {
  return _attackDamage;
}

void ClapTrap::attack(const std::string &target) {
  if (!this->getHitPoints() || !this->getEnergyPoints()) {
	std::cout << "ClapTrap " << _name
	<< " can't attack because it has no hit points or energy points left." <<
	std::endl;
	return;
  }
  std::cout << "ClapTrap " << _name
  << " attacks " << target << ", causing " << _attackDamage << " points of damage!"
  << std::endl;
  _energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (!this->getHitPoints() || !this->getEnergyPoints()) {
	std::cout << "ClapTrap " << _name
	<< " can't take damage because it has no hit points left." << std::endl;
	return;
  }
  amount > _hitPoints ? _hitPoints = 0 : _hitPoints -= amount;
  std::cout << "ClapTrap " << _name
  << " takes " << amount << " points of damage! Hit points left: " << _hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (!this->getEnergyPoints()) {
	std::cout << "ClapTrap " << _name
	<< " can't be repaired because it has no hit points or energy points left." << std::endl;
	return;
  }
  _hitPoints += amount;
  _energyPoints--;
  std::cout << "ClapTrap " << _name
  << " is repaired by " << amount << " points! Hit points: " << _hitPoints <<
  std::endl;
}