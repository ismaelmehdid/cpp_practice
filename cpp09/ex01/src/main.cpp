#include <iostream>

#include "../include/RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cout << "Error: The program must take one argument ONLY." << std::endl;
        return 1;
    }
    try {
        std::cout << rpn(argv[1]) << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
