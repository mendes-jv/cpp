#include <iostream>
#include <Zombie.hpp>

Zombie::Zombie(const std::string &name) : _name(name) {
    announce();
}

Zombie::~Zombie() {
    denounce();
}

void Zombie::announce() const {
    std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::denounce() const {
    std::cout << "Zombie named " << _name << " is dead.\n";
}
