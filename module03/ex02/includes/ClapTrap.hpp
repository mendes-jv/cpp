#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {
 protected:
  unsigned int _hitPoints;
  unsigned int _energyPoints;
  unsigned int _attackDamage;
  std::string _name;
 public:
  ClapTrap();

  explicit ClapTrap(const std::string &name);

  ClapTrap(const ClapTrap &other);

  ClapTrap &operator=(const ClapTrap &other);

  virtual ~ClapTrap();

  std::string getName() const;

  unsigned int getHitPoints() const;

  unsigned int getEnergyPoints() const;

  unsigned int getAttackDamage() const;

  virtual void attack(const std::string &target);

  void takeDamage(unsigned int amount);

  void beRepaired(unsigned int amount);
};

#endif //CLAPTRAP_HPP
