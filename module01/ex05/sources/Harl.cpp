#include "Harl.hpp"
#include <iostream>

void Harl::debug() {
    std::cout <<  "Verde é a cor mais linda do mundo! Eu tenho 7 camisas do Palmeiras, "
                  "2 bonés e um cachecol gigante! E ainda acho pouco!" << std::endl;
}

void Harl::info() {
    std::cout << "Não acredito que o Endrick fez mais um gol! Ele é o maior! Se ele não tivesse feito, "
                 "a gente não teria ganhado! E o Rony Rústico é o melhor atacante!" << std::endl;
}

void Harl::warning() {
    std::cout <<  "Acho que merecemos um pênalti a favor. O juiz não viu o toque na bola, mas eu vi daqui!"
                  " Ele não sabe nada de futebol, só eu!" << std::endl;
}

void Harl::error() {
    std::cout << "Isso é um absurdo! Quero falar com o Abel Ferreira agora mesmo! "
                 "Ele tem que explicar porque o Palmeiras é o maior campeão do Brasil!" << std::endl;
}

void Harl::complain(const std::string& level) {
    void (Harl::*pointerToFunction[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    const std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++) {
        if (level == levels[i]) {
            (this->*pointerToFunction[i])();
            return;
        }
    }
}


