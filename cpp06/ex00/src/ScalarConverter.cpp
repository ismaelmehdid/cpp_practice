#include "../include/ScalarConverter.hpp"

#include <iostream>
#include <string>

static void convert_string_and_display(std::string &str)
{
    std::cout << "char: ";
    try {
        int res = std::stoi(str);
    } catch (std::exception &e){
        std::cout << "impossible" << std::endl;
    }
    if (res < 0 || res > 127) {
        std::cout << "impossible" << std::endl;
    } else if (res >= 0 && res <= 31) {
        std::cout << "Non displayable" << std::endl;
    } else {
        std::cout << (char)res << std::endl;
    }
}

void ScalarConverter::convert(std::string &str)
{
    convert_string_and_display(str);
}
