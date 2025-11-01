#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>
#include "Base.hpp"

static Base* generate() {
    int r = std::rand() % 3;
    if (r == 0) return new A();
    if (r == 1) return new B();
    return new C();
}

static void identify(Base* p) {
    if (dynamic_cast<A*>(p)) std::cout << "A";
    else if (dynamic_cast<B*>(p)) std::cout << "B";
    else if (dynamic_cast<C*>(p)) std::cout << "C";
    else std::cout << "Unknown";
}

static void identify(Base& p) {
    try { (void)dynamic_cast<A&>(p); std::cout << "A"; return; } catch (...) {}
    try { (void)dynamic_cast<B&>(p); std::cout << "B"; return; } catch (...) {}
    try { (void)dynamic_cast<C&>(p); std::cout << "C"; return; } catch (...) {}
    std::cout << "Unknown";
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    for (int i = 0; i < 10; ++i) {
        Base* p = generate();
        std::cout << "Pointer: ";
        identify(p);
        std::cout << " | Reference: ";
        identify(*p);
        std::cout << std::endl;
        delete p;
    }
    return 0;
}
