#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include <Weapon.hpp>

class HumanB {
	std::string _name;
	Weapon *_weapon;

public:
	explicit HumanB(std::string name);

	void armUp(Weapon &weapon);

	void attack();
};

#endif //HUMANB_HPP
