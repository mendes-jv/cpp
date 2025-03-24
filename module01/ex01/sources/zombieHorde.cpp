#include <Zombie.hpp>

Zombie *zombieHorde (const int size, const std::string& name) {
    Zombie *horde = new Zombie[size];
    for (int i = 0; i < size; i++) {
        horde[i].setName(name);
        horde[i].announce();
    }
    return horde;
}
