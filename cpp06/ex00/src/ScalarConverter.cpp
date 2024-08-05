#include "../include/ScalarConverter.hpp"

#include <iostream>
#include <string>
#include <regex>


void ScalarConverter::convert(std::string &str)
{
    (void)str;
    std::regex charRegex("(-[0-9]*\\.[0-9]+)");
    std::regex intRegex("");
    std::regex floatRegex("");
    std::regex doubleRegex("");
}
