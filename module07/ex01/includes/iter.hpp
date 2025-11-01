#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

// Function pointer version (const)
template <typename T>
void iter(T* array, std::size_t length, void (*f)(T const &)) {
    if (!array || !f) return;
    for (std::size_t i = 0; i < length; ++i)
        f(array[i]);
}

// Overload for non-const callback (allows modifying elements)
template <typename T>
void iter(T* array, std::size_t length, void (*f)(T &)) {
    if (!array || !f) return;
    for (std::size_t i = 0; i < length; ++i)
        f(array[i]);
}

#endif