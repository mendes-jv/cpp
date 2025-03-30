#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {
  std::string _name;
  unsigned int _hitPoints;
  unsigned int _energyPoints;
  unsigned int _attackDamage;
 public:
  ClapTrap();

  explicit ClapTrap(const std::string &name);

  ClapTrap(const ClapTrap &other);

  ClapTrap &operator=(const ClapTrap &other);

  ~ClapTrap();

  std::string getName() const;

  unsigned int getHitPoints() const;

  unsigned int getEnergyPoints() const;

  unsigned int getAttackDamage() const;

  void attack(const std::string &target);

  void takeDamage(unsigned int amount);

  void beRepaired(unsigned int amount);
};

#endif //CLAPTRAP_HPP
