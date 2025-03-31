#include <FragTrap.hpp>

FragTrap::FragTrap() : ClapTrap() {
  _hitPoints = 100;
  _energyPoints = 100;
  _attackDamage = 30;
  std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
  _hitPoints = 100;
  _energyPoints = 100;
  _attackDamage = 30;
  std::cout << "FragTrap name constructor called for " << _name << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
  *this = other;
  std::cout << "FragTrap copy constructor called for " << other.getName() << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
  if (this != &other) {
	_name = other.getName();
	_hitPoints = other.getHitPoints();
	_energyPoints = other.getEnergyPoints();
	_attackDamage = other.getAttackDamage();
  }
  std::cout << "FragTrap assignment operator called for " << other.getName() << std::endl;
  return *this;
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap destructor called for " << _name << std::endl;
}

void FragTrap::highFivesGuys() {
  std::cout << "FragTrap " << _name << " high fives with the enemy!\nThey become friends!" << std::endl;
}