#include "../include/ScalarConverter.hpp"

#include <iostream>


// 1. Get the type of the value passed in string with regex
// 2. Static cast to the good type to display the value in the right format



int main(int argc, char **argv)
{
    if (argc == 2) {
        std::string user_input = argv[1];
        ScalarConverter::convert(user_input);
    } else {
        std::cout << "\033[31mWrong arguments.\033[0m" << std::endl;
        std::cout << "\033[32mNeed ./ex00 toConvert\033[0m" << std::endl;
    }

}
