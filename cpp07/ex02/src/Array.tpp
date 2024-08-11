#include "../include/Array.hpp"

template <typename T>
Array<T>::Array() : _length(1)
{
    try {
        _array = new T[1];
        _array[0] = T();
    } catch (std::bad_alloc &e) {
        std::cerr << "Failed to allocate memory: " << e.what() << std::endl;
        _array = nullptr;
    }
    //std::cout << "A default array has been created." << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : _length(n)
{
    try {
        _array = new T[_length]; // if n = 0 _array will point to nothing
        for (unsigned int i = 0; i < _length; i++) {
            _array[i] = T();
        }
    } catch (std::bad_alloc &e) {
        std::cerr << "Failed to allocate memory: " << e.what() << std::endl;
        _array = nullptr;
    }

    //std::cout << "An array of size " << _length << " has been created" << std::endl
}

template <typename T>
Array<T>::Array(const Array &toCopy) : _length(toCopy._length)
{
    if (this != &toCopy) {
        try {
            _array = new T[_length];
            for (unsigned int i = 0; i < _length; i++) {
                _array[i] = toCopy._array[i];
            }
        } catch (std::bad_alloc &e) {
            std::cerr << "Failed to allocate memory: " << e.what() << std::endl;
            _array = nullptr;
        }
    }
    //std::cout << "Array copy constructor called." << std::endl;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &toCopy)
{
    if (this != &toCopy) {
        _length = toCopy._length;
        _array = new T[_length];
        for (unsigned int i = 0; i < _length; i++) {
            _array[i] = toCopy._array[i];
        }
    }
    //std::cout << "Array assignment operator overload called." << std::endl;
    return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int index) throw(OutOfBound)
{
    if (index >= _length || index < 0) {
        throw OutOfBound();
    }
    return _array[index];
}

template <typename T>
Array<T>::~Array()
{
    //std::cout << "An array of size " << _length << " has been destroyed" << std::endl;
    delete [] _array;
}

template <typename T>
unsigned int Array<T>::size() const
{
    return _length;
}

template <typename T>
const char *Array<T>::OutOfBound::what() const throw()
{
    return "Out of bounds.";
}
