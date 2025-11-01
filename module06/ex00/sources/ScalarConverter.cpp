#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cerrno>
#include "ScalarConverter.hpp"

// Disallow instantiation
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }
ScalarConverter::~ScalarConverter() {}

static bool isPseudo(const std::string &s) {
    return s == "nan" || s == "+inf" || s == "-inf" || s == "inf"
        || s == "nanf" || s == "+inff" || s == "-inff" || s == "inff";
}

static bool isInt(const std::string &s) {
    if (s.empty()) return false;
    size_t i = 0;
    if (s[0] == '+' || s[0] == '-') i = 1;
    if (i == s.size()) return false;
    for (; i < s.size(); ++i) if (!std::isdigit(static_cast<unsigned char>(s[i]))) return false;
    return true;
}

static bool isFloat(const std::string &s) {
    if (s.size() < 2 || s[s.size()-1] != 'f') return false;
    std::string core = s.substr(0, s.size()-1);
    bool dot = false;
    size_t i = 0;
    if (core[0] == '+' || core[0] == '-') i = 1;
    if (i == core.size()) return false;
    for (; i < core.size(); ++i) {
        if (core[i] == '.') { if (dot) return false; dot = true; }
        else if (!std::isdigit(static_cast<unsigned char>(core[i]))) return false;
    }
    return dot; // must contain a dot for this checker (to separate from int+'f')
}

static bool isDouble(const std::string &s) {
    bool dot = false;
    size_t i = 0;
    if (s.empty()) return false;
    if (s[0] == '+' || s[0] == '-') i = 1;
    if (i == s.size()) return false;
    for (; i < s.size(); ++i) {
        if (s[i] == '.') { if (dot) return false; dot = true; }
        else if (!std::isdigit(static_cast<unsigned char>(s[i]))) return false;
    }
    return dot;
}

static bool isCharLiteral(const std::string &s) {
    return s.size() == 1 && !std::isdigit(static_cast<unsigned char>(s[0]));
}

static void printChar(double d) {
    std::cout << "char: ";
    if (std::isnan(d) || d < 0 || d > 127) {
        std::cout << "impossible" << std::endl;
        return;
    }
    char c = static_cast<char>(d);
    if (c < 32 || c > 126)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << c << "'" << std::endl;
}

static void printInt(double d) {
    std::cout << "int: ";
    if (std::isnan(d) || d < static_cast<double>(std::numeric_limits<int>::min()) ||
        d > static_cast<double>(std::numeric_limits<int>::max())) {
        std::cout << "impossible" << std::endl;
        return;
    }
    std::cout << static_cast<int>(d) << std::endl;
}

static void printFloat(double d) {
    std::cout << "float: ";
    if (std::isnan(d)) { std::cout << "nanf" << std::endl; return; }
    if (std::isinf(d)) { std::cout << (d < 0 ? "-inff" : "+inff") << std::endl; return; }
    float f = static_cast<float>(d);
    std::cout << std::fixed << std::setprecision((std::floor(d) == d && d > -1e6 && d < 1e6) ? 1 : 6) << f << 'f' << std::endl;
}

static void printDouble(double d) {
    std::cout << "double: ";
    if (std::isnan(d)) { std::cout << "nan" << std::endl; return; }
    if (std::isinf(d)) { std::cout << (d < 0 ? "-inf" : "+inf") << std::endl; return; }
    std::cout << std::fixed << std::setprecision((std::floor(d) == d && d > -1e6 && d < 1e6) ? 1 : 6) << d << std::endl;
}

void ScalarConverter::convert(const std::string &literal) {
    // Pseudo literals first
    if (isPseudo(literal)) {
        double d;
        if (literal == "nan" || literal == "nanf") d = std::numeric_limits<double>::quiet_NaN();
        else if (literal == "+inf" || literal == "+inff" || literal == "inf" || literal == "inff") d = std::numeric_limits<double>::infinity();
        else d = -std::numeric_limits<double>::infinity();
        printChar(d);
        printInt(d);
        printFloat(d);
        printDouble(d);
        return;
    }

    if (isCharLiteral(literal)) {
        char c = literal[0];
        double d = static_cast<unsigned char>(c);
        printChar(d);
        printInt(d);
        printFloat(d);
        printDouble(d);
        return;
    }

    char *end = 0;
    errno = 0;
    double d = 0.0;

    if (isInt(literal)) {
        long l = std::strtol(literal.c_str(), &end, 10);
        d = static_cast<double>(l);
    } else if (isFloat(literal)) {
        std::string core = literal.substr(0, literal.size()-1);
        d = std::strtod(core.c_str(), &end);
    } else if (isDouble(literal)) {
        d = std::strtod(literal.c_str(), &end);
    } else {
        // Attempt generic strtod parse
        d = std::strtod(literal.c_str(), &end);
        if (!end || *end != '\0') {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }
    }

    printChar(d);
    printInt(d);
    printFloat(d);
    printDouble(d);
}
