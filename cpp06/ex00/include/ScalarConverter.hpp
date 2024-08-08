#pragma once

#include <string>

class ScalarConverter
{
    public:
        static void convert(const std::string &str);
    private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &toCopy);
        ScalarConverter &operator=(const ScalarConverter &toCopy);
};
