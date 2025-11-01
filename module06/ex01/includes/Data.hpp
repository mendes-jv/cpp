#ifndef DATA_HPP
#define DATA_HPP

#include <string>

struct Data {
    int         id;
    std::string name;
    double      value;

    Data() : id(0), name(""), value(0.0) {}
};

#endif
