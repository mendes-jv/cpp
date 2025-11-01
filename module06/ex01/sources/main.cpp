#include <iostream>
#include "Serializer.hpp"

int main() {
    Data d;
    d.id = 42;
    d.name = "example";
    d.value = 3.14159;

    std::cout << "Original Data pointer: " << &d << "\n";
    uintptr_t raw = Serializer::serialize(&d);
    std::cout << "Serialized uintptr_t: " << raw << "\n";
    Data* back = Serializer::deserialize(raw);
    std::cout << "Deserialized Data pointer: " << back << "\n";

    if (back == &d)
        std::cout << "Success: pointers match" << std::endl;
    else
        std::cout << "Error: pointers do not match" << std::endl;

    std::cout << "Data{id=" << back->id << ", name=\"" << back->name << "\", value=" << back->value << "}" << std::endl;
    return 0;
}
