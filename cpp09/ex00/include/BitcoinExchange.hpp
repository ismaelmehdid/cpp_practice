#pragma once

#include <exception>
#include <iostream>

class Date
{
    public:
        Date(unsigned int year, unsigned int month, unsigned int day);
        Date(const Date &toCopy);
        Date &operator=(const Date &toCopy);
        bool operator<(const Date &other) const;
        bool operator!=(const Date &other) const;

        unsigned int _year;
        unsigned int _month;
        unsigned int _day;

        class InvalidDateException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

    private:
        Date();
};

std::ostream& operator<<(std::ostream& os, const Date& dt);

class InvalidFileFormat : public std::exception
{
    public:
        virtual const char *what() const throw();
};

class NegativeValue : public std::exception
{
    public:
        virtual const char *what() const throw();
};

class BadValue : public std::exception
{
    public:
        virtual const char *what() const throw();
};

class TooLargeNumber : public std::exception
{
    public:
        virtual const char *what() const throw();
};
