#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <cstddef>
#include <iostream>
#include <ctime>
#include <cstdlib>

// Simple dynamic array template with bounds checking
// Requirements per 42 CPP07 ex02

template <typename T>
class Array {
public:
    // Constructors
    Array() : _size(0), _data(NULL) {}

    Array(unsigned int n) : _size(n), _data(NULL) {
        if (_size > 0) {
            _data = new T[_size];
        }
    }

    Array(const Array& other) : _size(other._size), _data(NULL) {
        if (_size > 0) {
            _data = new T[_size];
            for (unsigned int i = 0; i < _size; ++i)
                _data[i] = other._data[i];
        }
    }

    Array& operator=(const Array& other) {
        if (this != &other) {
            // Allocate new block before deleting old to be exception-safe
            T* newData = NULL;
            if (other._size > 0) {
                newData = new T[other._size];
                for (unsigned int i = 0; i < other._size; ++i)
                    newData[i] = other._data[i];
            }
            delete [] _data;
            _data = newData;
            _size = other._size;
        }
        return *this;
    }

    ~Array() { delete [] _data; }

    // Element access with bounds checking
    T& operator[](int index) {
        if (index < 0 || static_cast<unsigned int>(index) >= _size)
            throw std::out_of_range("Array index out of range");
        return _data[index];
    }

    const T& operator[](int index) const {
        if (index < 0 || static_cast<unsigned int>(index) >= _size)
            throw std::out_of_range("Array index out of range");
        return _data[index];
    }

    unsigned int size() const { return _size; }

private:
    unsigned int _size;
    T* _data;
};

#endif // ARRAY_HPP
