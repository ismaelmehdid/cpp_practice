#include "../include/ScalarConverter.hpp"

#include <iostream>
#include <string>
#include <iomanip>

enum scalar_type {
    SCALAR_CHAR,
    SCALAR_INT,
    SCALAR_FLOAT,
    SCALAR_DOUBLE,
    SCALAR_UNKNOWN
} t_scalar_type ;

//===----------------------------------------------------------------------===//

ScalarConverter::ScalarConverter() { }

ScalarConverter::~ScalarConverter() { }

ScalarConverter::ScalarConverter(const ScalarConverter &toCopy)
{
    (void)toCopy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &toCopy)
{
    (void)toCopy;
    return *this;
}

//===----------------------------------------------------------------------===//

static void print_impossible()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

static bool is_a_char(const std::string &str)
{
    if (str.size() == 1 && !std::isdigit(str[0]))
        return (true);
    return (false);
}

static bool is_an_int(const std::string &str)
{
    size_t start_index = 0;
    if (str[0] == '-' || str[0] == '+') {
        if (str.size() == 1) {
            return (false);
        }
        start_index = 1;
    }
    for (size_t i = start_index; i < str.size(); i++) {
        if (!std::isdigit(str[i])) {
            return (false);
        }
    }
    return (true);
}

static bool is_a_float(const std::string &str)
{
    if (str == "-inff" || str == "+inff" || str == "nanf")
        return (true);
    size_t start_index = 0;
    if (str[0] == '-' || str[0] == '+') {
        if (str.size() == 1) {
            return false;
        }
        start_index = 1;
    }
    bool has_digit = false;
    bool has_decimal_point = false;
    bool has_trailing_f = false;
    for (size_t i = start_index; i < str.size(); i++) {
        char c = str[i];
        if (std::isdigit(c)) {
            has_digit = true;
        } else if (c == '.') {
            if (has_decimal_point) {
                return (false);
            }
            has_decimal_point = true;
        } else if (c == 'f' || c == 'F') {
            if (i != str.size() - 1) {
                return (false);
            }
            has_trailing_f = true;
        }
    }
    if (has_trailing_f && !has_digit) {
        return false;
    }
    return has_digit; // at least one digit must be present
}

static bool is_a_double(const std::string &str)
{
    if (str == "nan" || str == "+inf" || str == "-inf")
        return true;
    size_t start_index = 0;
    if (str[0] == '-' || str[0] == '+') {
        if (str.size() == 1)
            return false;
        start_index = 1;
    }
    bool has_digit = false;
    bool has_decimal_point = false;
    for (size_t i = start_index; i < str.size(); i++) {
        char c = str[i];
        if (std::isdigit(c)) {
            has_digit = true;
        } else if (c == '.') {
            if (has_decimal_point) {
                return false;
            }
            has_decimal_point = true;
        } else {
            return false;
        }
    }
    return has_digit;
}

static scalar_type get_scalar_type(const std::string &str)
{
    if (is_a_char(str)) {
        std::cout << "char" << std::endl;
        return (SCALAR_CHAR);
    }
    if (is_an_int(str)) {
        std::cout << "int" << std::endl;
        return (SCALAR_INT);
    }
    if (is_a_double(str)) {
        std::cout << "double" << std::endl;
        return (SCALAR_DOUBLE);
    }
    if (is_a_float(str)) {
        std::cout << "float" << std::endl;
        return (SCALAR_FLOAT);
    }
    return (SCALAR_UNKNOWN);
}

static void from_char_to_others(const std::string &str)
{
    bool non_displayable = false;
    char char_value = str[0];
    if ((char_value >= 0 && char_value <= 31) || char_value == 127) {
        non_displayable = true;
    }
    int int_value = static_cast<int>(char_value);
    float float_value = static_cast<float>(char_value);
    double double_value = static_cast<double>(char_value);
    if (non_displayable)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: " << char_value << std::endl;
    std::cout << "int: " << int_value << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(3) << float_value << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(3) << double_value << std::endl;
}

static void from_int_to_others(const std::string &str)
{
    try {
        int int_value = std::stoi(str);
        if (int_value < std::numeric_limits<char>::min() || int_value > std::numeric_limits<char>::max()) {
            std::cout << "char: impossible" << std::endl;
        } else if ((int_value >= 0 && int_value <= 31) || int_value == 127) {
            std::cout << "char: Non displayable" << std::endl;
        } else {
            char char_value = static_cast<char>(int_value);
            std::cout << "char: " << char_value << std::endl;
        }
        float float_value = static_cast<float>(int_value);
        double double_value = static_cast<double>(int_value);
        std::cout << "int: " << int_value << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(3) << float_value << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(3) << double_value << std::endl;
    } catch (std::exception &e) {
        (void)e;
        print_impossible();
    }
}

static void from_float_to_others(const std::string &str)
{
    try {
        float float_value = std::stof(str);
        if (float_value < std::numeric_limits<char>::min() || float_value > std::numeric_limits<char>::max()) {
            std::cout << "char: impossible" << std::endl;
        } else if ((float_value >= 0 && float_value <= 31) || float_value == 127) {
            std::cout << "char: Non displayable" << std::endl;
        } else {
            char char_value = static_cast<char>(float_value);
            std::cout << "char: " << char_value << std::endl;
        }
        if (float_value < std::numeric_limits<int>::min() || float_value > std::numeric_limits<int>::max()) {
            std::cout << "int: impossible" << std::endl;
        } else {
            int int_value = static_cast<int>(float_value);
            std::cout << "int: " << int_value << std::endl;
        }
        double double_value = static_cast<double>(float_value);
        std::cout << "float: " << std::fixed << std::setprecision(3) << float_value << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(3) << double_value << std::endl;
    } catch (std::exception &e) {
        (void)e;
        print_impossible();
    }
}

static void from_double_to_others(const std::string &str)
{
    try {
        double double_value = std::stod(str);
        if (double_value < std::numeric_limits<char>::min() || double_value > std::numeric_limits<char>::max()) {
            std::cout << "char: impossible" << std::endl;
        } else if ((double_value >= 0 && double_value <= 31) || double_value == 127) {
            std::cout << "char: Non displayable" << std::endl;
        } else {
            char char_value = static_cast<char>(double_value);
            std::cout << "char: " << char_value << std::endl;
        }
        if (double_value < std::numeric_limits<int>::min() || double_value > std::numeric_limits<int>::max()) {
            std::cout << "int: impossible" << std::endl;
        } else {
            int int_value = static_cast<int>(double_value);
            std::cout << "int: " << int_value << std::endl;
        }
        if (double_value < std::numeric_limits<float>::min() || double_value > std::numeric_limits<float>::max()) {
            std::cout << "float: impossible" << std::endl;
        } else {
            float float_value = static_cast<float>(double_value);
            std::cout << "float: " << std::fixed << std::setprecision(3) << float_value << "f" << std::endl;
        }
        std::cout << "double: " << std::fixed << std::setprecision(3) << double_value << std::endl;
    } catch (std::exception &e) {
        (void)e;
        print_impossible();
    }
}

void ScalarConverter::convert(const std::string &str)
{
    if (str.empty()) {
        print_impossible();
        return ;
    }
    scalar_type scalar_type = get_scalar_type(str);
    switch (scalar_type)
    {
    case SCALAR_CHAR:
        from_char_to_others(str);
        break;
    case SCALAR_INT:
        from_int_to_others(str);
        break;
    case SCALAR_FLOAT:
        from_float_to_others(str);
        break;
    case SCALAR_DOUBLE:
        from_double_to_others(str);
        break;
    default:
        print_impossible();
        break;
    }
}
