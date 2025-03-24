#include <Zombie.hpp>
#include <iostream>

#ifndef BANDO_DE_LOUCOS
# define BANDO_DE_LOUCOS 10
#endif

int main() {
    const Zombie *yuriAlberto = newZombie("Yuri Alberto");
    delete yuriAlberto;
    randomChump("Memphis Depay");
    const Zombie *gavioesDaFiel = zombieHorde(BANDO_DE_LOUCOS, "Gaviões da Fiel");
    std::cout << "Aqui tem um bando de loucos!\n";
    delete[] gavioesDaFiel;
}
