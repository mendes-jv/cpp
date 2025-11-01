#include <iostream>
#include <string>
#include "iter.hpp"

static void printInt(int const &x) { std::cout << x << ' '; }
static void printStr(std::string const &s) { std::cout << s << ' '; }
static void incInt(int &x) { x++; }

int main() {
    int ai[5] = {1,2,3,4,5};
    std::string as[3] = {"hello", "42", "cpp"};

    std::cout << "ints: ";
    iter(ai, 5, printInt); std::cout << "\n";

    iter(ai, 5, incInt);
    std::cout << "ints+1: ";
    iter(ai, 5, printInt); std::cout << "\n";

    std::cout << "strings: ";
    iter(as, 3, printStr); std::cout << "\n";
    return 0;
}
