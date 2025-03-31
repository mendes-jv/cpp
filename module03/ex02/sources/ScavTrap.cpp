#include <ScavTrap.hpp>

ScavTrap::ScavTrap() : ClapTrap() {
  _hitPoints = 100;
  _energyPoints = 50;
  _attackDamage = 20;
  std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
  _hitPoints = 100;
  _energyPoints = 50;
  _attackDamage = 20;
  std::cout << "ScavTrap name constructor called for " << _name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
  *this = other;
  std::cout << "ScavTrap copy constructor called for " << other.getName() << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
  if (this != &other) {
	_name = other.getName();
	_hitPoints = other.getHitPoints();
	_energyPoints = other.getEnergyPoints();
	_attackDamage = other.getAttackDamage();
  }
  std::cout << "ScavTrap assignment operator called for " << other.getName() << std::endl;
  return *this;
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap destructor called for " << _name << std::endl;
}

void ScavTrap::attack(const std::string &target) {
  if (!this->getHitPoints() || !this->getEnergyPoints()) {
	std::cout << "ScavTrap " << _name
			  << " can't attack because it has no hit points or energy points left."
			  << std::endl;
	return;
  }
  std::cout << "ScavTrap " << _name
			<< " attacks " << target << ", causing " << _attackDamage << " points of damage!"
			<< std::endl;
  _energyPoints--;
}

void ScavTrap::guardGate() {
  std::cout << "ScavTrap " << _name << " is now in Gate Keeper mode." << std::endl;
}
