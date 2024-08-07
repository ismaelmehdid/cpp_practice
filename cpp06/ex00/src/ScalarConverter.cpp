#include "../include/ScalarConverter.hpp"

#include <iostream>
#include <string>

enum scalar_type {
    SCALAR_CHAR,
    SCALAR_INT,
    SCALAR_FLOAT,
    SCALAR_DOUBLE
} t_scalar_type ;

static void print_of_unknown_scalar_type()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

static scalar_type get_scalar_type(const std::string &str)
{
    if (str == "-inff" || str == "+inff" || str == "nanf")
        return (SCALAR_FLOAT);
    if (str == "-inf" || str == "+inf" || str == "nan")
        return (SCALAR_DOUBLE);
}

void ScalarConverter::convert(const std::string &str)
{
    scalar_type scalar_type = get_scalar_type(str);
    switch (scalar_type)
    {
        case SCALAR_CHAR:
            break;
        case SCALAR_INT:
            break;
        case SCALAR_FLOAT:
            break;
        case SCALAR_DOUBLE:
            break;
        default:
            print_of_unknown_scalar_type();
            return ;
    }
}
