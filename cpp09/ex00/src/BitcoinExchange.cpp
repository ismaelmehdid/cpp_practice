#include "../include/BitcoinExchange.hpp"

Date::Date() : _year(1), _month(1), _day(1) {}

Date::Date(unsigned int year, unsigned int month, unsigned int day)
{
    if (year < 1 || month < 1 || month > 12 || day < 1 || day > 31) {
        throw InvalidDateException();
    }
    if (month == 2) { // check for leap year
        bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (day > (isLeapYear ? 29 : 28)) {
            throw InvalidDateException();
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30) {
            throw InvalidDateException();
        }
    }
    _day = day;
    _month = month;
    _year = year;
}

Date::Date(const Date &toCopy)
{
    _day = toCopy._day;
    _month = toCopy._month;
    _year = toCopy._year;
}

//===----------------------------------------------------------------------===//
//                       Exception
//===----------------------------------------------------------------------===//

const char *Date::InvalidDateException::what() const throw()
{
    return "Invalid date.";
}

const char *InvalidFileFormat::what() const throw()
{
    return "Invalid file format.";
}

const char *NegativeValue::what() const throw()
{
    return "Error: not a positive number.";
}

const char *BadValue::what() const throw()
{
    return "Error: bad value.";
}

const char *TooLargeNumber::what() const throw()
{
    return "Error: too large number.";
}

//===----------------------------------------------------------------------===//
//                       Operators overload
//===----------------------------------------------------------------------===//

std::ostream& operator<<(std::ostream& os, const Date& dt)
{
    os << dt._year << '/' << dt._month << '/' << dt._day;
    return os;
}

bool Date::operator<(const Date &other) const
{
    if (_year != other._year) {
        return _year < other._year;
    }
    if (_month != other._month) {
        return _month < other._month;
    }
    return _day < other._day;
}

Date &Date::operator=(const Date &toCopy)
{
    if (this != &toCopy) {
        _year = toCopy._year;
        _month = toCopy._month;
        _day = toCopy._day;
    }
    return *this;
}

bool Date::operator!=(const Date &other) const
{
    return _year == other._year && _month == other._month && _day == other._day; 
}
