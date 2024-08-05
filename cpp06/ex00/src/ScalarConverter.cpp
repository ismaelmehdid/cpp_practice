#include "../include/ScalarConverter.hpp"

#include <iostream>
#include <string>
#include <regex.h>

#define CHAR_REGEX ""
#define INT_REGEX ""
#define FLOAT_REGEX ""
#define DOUBLE_REGEX ""


void ScalarConverter::convert(std::string &str)
{
    (void)str;
    regex_t charRegex;
    regex_t intRegex;
    regex_t floatRegex;
    regex_t doubleRegex;

    if (regcomp(&charRegex, CHAR_REGEX, 0) != 0 ||
        regcomp(&intRegex, INT_REGEX, 0) != 0 ||
        regcomp(&floatRegex, FLOAT_REGEX, 0) != 0 ||
        regcomp(&doubleRegex, DOUBLE_REGEX, 0) != 0)
    {
        std::cerr << "Error while compiling regex" << std::endl;
        return ;
    }
}
