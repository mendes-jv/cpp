#include <HumanB.hpp>
#include <iostream>

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
}

void HumanB::armUp(Weapon &weapon)
{
	_weapon = &weapon;
}

void HumanB::attack()
{
	if (_weapon) {
		std::cout << _name << " attacks with his " << _weapon->getType() << std::endl;
		return;
	}
	std::cout << _name << " is unarmed" << std::endl;
}
