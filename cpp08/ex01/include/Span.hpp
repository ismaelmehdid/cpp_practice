#pragma once

#include <vector>

class Span
{
    class NoSpanCanBeFound : public std::exception
    {
        public:
			const char *what() const throw();
    };

    class TooManyElements : public std::exception
    {
        public:
			const char *what() const throw();
    };

    public:
        Span();
        Span(unsigned int n);
        ~Span();
        Span(const Span &toCopy);
        Span &operator=(const Span &toCopy);

        void    addNumber(int n) throw(TooManyElements);
        int     shortestSpan() throw(NoSpanCanBeFound);
        int     longestSpan() throw(NoSpanCanBeFound);
        void    fill_random(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        void    display();
        std::vector<int>::iterator begin();
        std::vector<int>::iterator end();

    private:
        unsigned int        _nbrOfElements;
        unsigned int        _currentIndex;
        std::vector<int>    _vector;
        static bool         _seeded;
};
