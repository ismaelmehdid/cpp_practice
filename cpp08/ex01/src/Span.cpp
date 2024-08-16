#include "../include/Span.hpp"

#include <vector>
#include <iostream>
#include <numeric>
#include <time.h>

bool Span::_seeded = false;

//===----------------------------------------------------------------------===//
//                       Constructors/Destructor
//===----------------------------------------------------------------------===//

Span::Span() : _nbrOfElements(0), _currentIndex(0), _vector(std::vector<int>())
{
    if (!_seeded) {
        srand(time(NULL));
        _seeded = true;
    }
    std::cout << "An empty span has been created." << std::endl;
}

Span::Span(unsigned int n) : _nbrOfElements(n), _currentIndex(0), _vector(std::vector<int>(n))
{
    if (!_seeded) {
        srand(time(0));
        _seeded = true;
    }
    std::cout << "A span of size " << n << " has been created." << std::endl;
}

Span::Span(const Span &toCopy)
{
    std::cout << "A span has been copied." << std::endl;
    _nbrOfElements = toCopy._nbrOfElements;
    _vector = toCopy._vector;
}

Span::~Span()
{
    std::cout << "A span of size " << _nbrOfElements << " has been destroyed." << std::endl;
}

//===----------------------------------------------------------------------===//
//                       Member functions
//===----------------------------------------------------------------------===//

void Span::addNumber(int n) throw(TooManyElements)
{
    if (_currentIndex >= _nbrOfElements) {
        throw TooManyElements();
    }
    _vector[_currentIndex++] = n;
}

int Span::shortestSpan() throw(NoSpanCanBeFound)
{
    if (_currentIndex < 2) {
        throw NoSpanCanBeFound();
    }
    std::vector<int> sorted = _vector;
    std::sort(sorted.begin(), sorted.end());

    std::vector<int> all_differences(sorted.size());
    std::adjacent_difference(sorted.begin(), sorted.end(), all_differences.begin()); // compute all difference in the sorted array

    //all_differences.begin() + 1 as the first difference is sorted[0] - sorted[0]
    return *std::min_element(all_differences.begin() + 1, all_differences.end());

    return 0;
}

int Span::longestSpan() throw(NoSpanCanBeFound)
{
    if (_currentIndex < 2) {
        throw NoSpanCanBeFound();
    }

    int minElement = *std::min_element(_vector.begin(), _vector.end());
    int maxElement = *std::max_element(_vector.begin(), _vector.end());

    return maxElement - minElement;
}

void    Span::fill_random(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    for (std::vector<int>::iterator it = begin; it != end; it++) {
        *it = rand() - RAND_MAX / 2;
    }
    _currentIndex = _vector.size() - 1;
}

std::vector<int>::iterator Span::begin()
{
    return _vector.begin();
}

std::vector<int>::iterator Span::end()
{
    return _vector.end();
}

void Span::display()
{
    for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

//===----------------------------------------------------------------------===//
//                       Operator overload
//===----------------------------------------------------------------------===//

Span &Span::operator=(const Span &toCopy)
{
    if (this != &toCopy) {
        _nbrOfElements = toCopy._nbrOfElements;
        _vector = toCopy._vector;
    }
    return *this;
}

//===----------------------------------------------------------------------===//
//                       Exceptions
//===----------------------------------------------------------------------===//

const char *Span::NoSpanCanBeFound::what() const throw()
{
    return "No span could be found.";
}

const char *Span::TooManyElements::what() const throw()
{
    return "Too many elements.";
}