#include <iostream>
#include <cstdlib>
#include <ClapTrap.hpp>

int main() {
  const ClapTrap a;
  ClapTrap player("Bino");
  ClapTrap enemy("Cino");
  ClapTrap playerBefore(player);
  ClapTrap enemyBefore = enemy;

  std::cout
	  << "\nBY INSTANCE (const and default)\n"
	  << "Name: " << a.getName()
	  << " | Hit Points: " << a.getHitPoints()
	  << " | Energy Points: " << a.getEnergyPoints()
	  << " | Attack Power: " << a.getAttackDamage()
	  << "\nBY NAME \n"
	  << "Name: " << player.getName()
	  << " | Hit Points: " << player.getHitPoints()
	  << " | Energy Points: " << player.getEnergyPoints()
	  << " | Attack Power: " << player.getAttackDamage()
	  << "\nBY COPY \n"
	  << "Name: " << playerBefore.getName()
	  << " | Hit Points: " << playerBefore.getHitPoints()
	  << " | Energy Points: " << playerBefore.getEnergyPoints()
	  << " | Attack Power: " << playerBefore.getAttackDamage()
	  << "\nBY ASSIGNMENT \n"
	  << "Name: " << enemyBefore.getName()
	  << " | Hit Points: " << enemyBefore.getHitPoints()
	  << " | Energy Points: " << enemyBefore.getEnergyPoints()
	  << " | Attack Power: " << enemyBefore.getAttackDamage()
	  << std::endl;

  std::cout << "\nBATTLE: " << std::endl;
  player.attack(enemy.getName());
  enemy.takeDamage(player.getAttackDamage());
  enemy.attack(player.getName());
  player.takeDamage(enemy.getAttackDamage());
  player.beRepaired(5);
  player.attack(enemy.getName());
  enemy.takeDamage(player.getAttackDamage());
  enemy.beRepaired(5);
  enemy.attack(player.getName());
  player.takeDamage(enemy.getAttackDamage());
  std::cout << "END OF BATTLE: " << std::endl << std::endl;

  ClapTrap *playerAfter = new ClapTrap(player);

  std::cout
	  << "\nplayer after battle (heap) \n"
	  << "Name: " << playerAfter->getName()
	  << " | Hit Points: " << playerAfter->getHitPoints()
	  << " | Energy Points: " << playerAfter->getEnergyPoints()
	  << " | Attack Power: " << playerAfter->getAttackDamage()
	  << "\nBY INSTANCE (const and default)\n"
	  << "Name: " << a.getName()
	  << " | Hit Points: " << a.getHitPoints()
	  << " | Energy Points: " << a.getEnergyPoints()
	  << " | Attack Power: " << a.getAttackDamage()
	  << "\nBY NAME (player) \n"
	  << "Name: " << player.getName()
	  << " | Hit Points: " << player.getHitPoints()
	  << " | Energy Points: " << player.getEnergyPoints()
	  << " | Attack Power: " << player.getAttackDamage()
	  << "\nBY NAME (enemy) \n"
	  << "Name: " << enemy.getName()
	  << " | Hit Points: " << enemy.getHitPoints()
	  << " | Energy Points: " << enemy.getEnergyPoints()
	  << " | Attack Power: " << enemy.getAttackDamage()
	  << "\nBY COPY (player before battle) \n"
	  << "Name: " << playerBefore.getName()
	  << " | Hit Points: " << playerBefore.getHitPoints()
	  << " | Energy Points: " << playerBefore.getEnergyPoints()
	  << " | Attack Power: " << playerBefore.getAttackDamage()
	  << "\nBY ASSIGNMENT (enemy before battle) \n"
	  << "Name: " << enemyBefore.getName()
	  << " | Hit Points: " << enemyBefore.getHitPoints()
	  << " | Energy Points: " << enemyBefore.getEnergyPoints()
	  << " | Attack Power: " << enemyBefore.getAttackDamage()
	  << std::endl << std::endl;

  delete playerAfter;
  return EXIT_SUCCESS;
}
