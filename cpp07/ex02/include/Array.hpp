#pragma once

#include <iostream>

// Templates functions are compiled only if called
template <typename T>
class Array
{
    class OutOfBound : public std::exception
    {
        public:
            const char *what() const throw();
    };
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &toCopy);
        Array &operator=(const Array &toCopy);
        T &operator[](unsigned int index) throw(OutOfBound);
        ~Array();
        unsigned int size() const;
    private:
        const unsigned int _length;
        T *_array;
};

#include "../src/Array.tpp"