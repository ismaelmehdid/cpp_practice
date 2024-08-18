#pragma once

#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:

        MutantStack() : std::stack<T>() {
            std::cout << "A MutantStack has been created." << std::endl;
        }

        MutantStack(const MutantStack &toCopy) : std::stack<T>(toCopy) {
            std::cout << "Copy constructor of MutantStack called." << std::endl;
        }

        MutantStack &operator=(const MutantStack &toCopy) {
            if (this != &toCopy) {
                std::stack<T>::operator=(toCopy);
            }
            return *this;
        }

        ~MutantStack() {
            std::cout << "A MutantStack has been destroyed." << std::endl;
        }

        typedef typename std::deque<T>::iterator iterator;              // read and write
        typedef typename std::deque<T>::const_iterator const_iterator;  // read only

        iterator begin() {
            return this->c.begin();
        }

        const_iterator begin() const {
            return this->c.begin();
        }

        iterator end() {
            return this->c.end();
        }

        const_iterator end() const {
            return this->c.end();
        }
};