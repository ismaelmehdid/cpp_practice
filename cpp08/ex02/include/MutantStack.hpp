#pragma once

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        typedef typename std::deque<T>::iterator iterator;
        typedef typename std::deque<T>::const_iterator const_iterator;

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