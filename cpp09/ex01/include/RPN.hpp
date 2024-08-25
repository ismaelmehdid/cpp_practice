#pragma once

#include <string>

class InvalidElement : public std::exception
{
    public:
		virtual const char *what() const throw();
};

class InvalidOperationFormat : public std::exception
{
    public:
		virtual const char *what() const throw();
};

class DivisionByZero : public std::exception
{
    public:
		virtual const char *what() const throw();
};

double rpn(const std::string &input);