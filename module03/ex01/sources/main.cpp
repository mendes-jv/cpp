#include <iostream>
#include <cstdlib>
#include <ClapTrap.hpp>
#include <ScavTrap.hpp>

int main() {
  std::string green = "\033[1;32m";
  std::string red = "\033[1;31m";
  std::string blue = "\033[1;34m";
  std::string reset = "\033[0m";

  std::cout << green << "\t//MY MAIN TESTS//\n\n"
			<< red << "\tConstructors\n" << reset << std::endl;
  const ScavTrap a;
  ScavTrap player("Bino");
  ScavTrap enemyScav("Scav-Cino");
  ClapTrap enemyClap("Clap-Cino");
  ScavTrap playerBefore(player);
  ScavTrap enemyBefore = enemyScav;

  std::cout << red << "\n\tSlicing\n" << reset << std::endl;
  ScavTrap *slicingScav = new ScavTrap("Dino");
  ClapTrap *slicingClap = slicingScav;
  std::cout << blue << "\nSLICED (slicingClap)\n" << reset
			<< "Name: " << slicingClap->getName()
			<< " | Hit Points: " << slicingClap->getHitPoints()
			<< " | Energy Points: " << slicingClap->getEnergyPoints()
			<< " | Attack Power: " << slicingClap->getAttackDamage()
			<< std::endl;
  slicingClap->attack("Slicing-clap");
  slicingScav->attack("Slicing-scav");
  slicingScav->guardGate();
  std::cout << std::endl;
  delete slicingClap;


  std::cout << red << "\n\tINFO (before battle)\n" << reset
	  << blue << "\nBY INSTANCE (const and default)\n" << reset
	  << "Name: " << a.getName()
	  << " | Hit Points: " << a.getHitPoints()
	  << " | Energy Points: " << a.getEnergyPoints()
	  << " | Attack Power: " << a.getAttackDamage()
	  << blue << "\nBY NAME (player)\n" << reset
	  << "Name: " << player.getName()
	  << " | Hit Points: " << player.getHitPoints()
	  << " | Energy Points: " << player.getEnergyPoints()
	  << " | Attack Power: " << player.getAttackDamage()
	  << blue << "\nBY COPY (player before battle)\n" << reset
	  << "Name: " << playerBefore.getName()
	  << " | Hit Points: " << playerBefore.getHitPoints()
	  << " | Energy Points: " << playerBefore.getEnergyPoints()
	  << " | Attack Power: " << playerBefore.getAttackDamage()
	  << blue << "\nBY ASSIGNMENT (enemy scavTrap before battle)\n" << reset
	  << "Name: " << enemyBefore.getName()
	  << " | Hit Points: " << enemyBefore.getHitPoints()
	  << " | Energy Points: " << enemyBefore.getEnergyPoints()
	  << " | Attack Power: " << enemyBefore.getAttackDamage()
	  << std::endl;

  std::cout << red << "\n\tBATTLE SIMULATION\n" << reset
  << blue << "\nVS. SCAVTRAP" << reset << std::endl;
  player.attack(enemyScav.getName());
  enemyScav.takeDamage(player.getAttackDamage());
  enemyScav.attack(player.getName());
  player.takeDamage(enemyScav.getAttackDamage());
  player.beRepaired(5);
  player.attack(enemyScav.getName());
  enemyScav.takeDamage(player.getAttackDamage());
  enemyScav.beRepaired(5);
  enemyScav.attack(player.getName());
  player.takeDamage(enemyScav.getAttackDamage());
  std::cout << blue << "\nVS. CLAPTRAP" << reset << std::endl;
  player.attack(enemyClap.getName());
  enemyClap.takeDamage(player.getAttackDamage());
  enemyClap.attack(player.getName());
  player.takeDamage(enemyClap.getAttackDamage());
  player.beRepaired(5);
  player.attack(enemyClap.getName());
  enemyClap.takeDamage(player.getAttackDamage());
  enemyClap.beRepaired(5);
  enemyClap.attack(player.getName());
  player.takeDamage(enemyClap.getAttackDamage());
  player.guardGate();
  ClapTrap *playerAfter = new ClapTrap(player);

  std::cout << red << "\n\tINFO (after battle)\n" << reset
	  << blue << "\nHEAP ALLOCATION (player after battle)\n" << reset
	  << "Name: " << playerAfter->getName()
	  << " | Hit Points: " << playerAfter->getHitPoints()
	  << " | Energy Points: " << playerAfter->getEnergyPoints()
	  << " | Attack Power: " << playerAfter->getAttackDamage()
	  << blue << "\nBY INSTANCE (const and default)\n" << reset
	  << "Name: " << a.getName()
	  << " | Hit Points: " << a.getHitPoints()
	  << " | Energy Points: " << a.getEnergyPoints()
	  << " | Attack Power: " << a.getAttackDamage()
	  << blue << "\nBY NAME (player)\n" << reset
	  << "Name: " << player.getName()
	  << " | Hit Points: " << player.getHitPoints()
	  << " | Energy Points: " << player.getEnergyPoints()
	  << " | Attack Power: " << player.getAttackDamage()
	  << blue << "\nBY NAME (enemyScav after battle)\n" << reset
	  << "Name: " << enemyScav.getName()
	  << " | Hit Points: " << enemyScav.getHitPoints()
	  << " | Energy Points: " << enemyScav.getEnergyPoints()
	  << " | Attack Power: " << enemyScav.getAttackDamage()
	  << blue << "\nBY NAME (enemyClap after battle)\n" << reset
	  << "Name: " << enemyClap.getName()
	  << " | Hit Points: " << enemyClap.getHitPoints()
	  << " | Energy Points: " << enemyClap.getEnergyPoints()
	  << " | Attack Power: " << enemyClap.getAttackDamage()
	  << blue << "\nBY COPY (player before battle)\n" << reset
	  << "Name: " << playerBefore.getName()
	  << " | Hit Points: " << playerBefore.getHitPoints()
	  << " | Energy Points: " << playerBefore.getEnergyPoints()
	  << " | Attack Power: " << playerBefore.getAttackDamage()
	  << blue << "\nBY ASSIGNMENT (enemyScav before battle)\n" << reset
	  << "Name: " << enemyBefore.getName()
	  << " | Hit Points: " << enemyBefore.getHitPoints()
	  << " | Energy Points: " << enemyBefore.getEnergyPoints()
	  << " | Attack Power: " << enemyBefore.getAttackDamage()
	  << std::endl;
  std::cout << red << "\n\tDestructors\n" << reset << std::endl;
  delete playerAfter;
  return EXIT_SUCCESS;
}
