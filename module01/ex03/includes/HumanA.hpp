#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include <Weapon.hpp>

class HumanA {
	std::string _name;
	Weapon &_weapon;

public:
	HumanA(std::string name, Weapon &weapon);

	void attack();
};

#endif //HUMANA_HPP
