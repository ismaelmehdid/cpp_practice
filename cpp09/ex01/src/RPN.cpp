#include "../include/RPN.hpp"

#include <string>
#include <stack>
#include <sstream>

enum element_type {
    OPERATOR,
    NUMBER
};

static element_type get_element_type(std::string &element)
{
    if (element.size() == 1) {
        if (std::isdigit(element[0])) {
            return NUMBER;
        } else if (element[0] == '+' || element[0] == '-' || element[0] == '/' || element[0] == '*') {
            return OPERATOR;
        } else {
            throw InvalidElement();
        }
    } else {
        size_t starting_index = 0;
        if (element[0] == '-' || element[0] == '+') {
            starting_index = 1;
        }
        for (size_t i = starting_index; i < element.size(); i++) {
            if (!std::isdigit(element[i])) {
                throw InvalidElement();
            }
        }
        return NUMBER;
    }
}

static void performOperation(std::stack<double> &stack, std::string &element)
{
    if (stack.size() < 2) {
        throw InvalidOperationFormat();
    }

    char operator_sign = element[0];
    int temp2 = stack.top();
    stack.pop();
    int temp1 = stack.top();
    stack.pop();

    switch (operator_sign)
    {
    case '+':
        stack.push(temp1 + temp2);
        break;
    case '-':
        stack.push(temp1 - temp2);
        break;
    case '/':
        if (temp2 == 0) {
            throw DivisionByZero();
        }
        stack.push(temp1 / temp2);
        break;
    case '*':
        stack.push(temp1 * temp2);
        break;
    default:
        throw InvalidElement();
    }
}

double rpn(const std::string &input)
{
    if (input.empty()) {
        throw InvalidOperationFormat();
    }

    std::stack<double> stack;
    std::istringstream iss(input);
    std::string element;

    while (iss >> element)
    {
        element_type type = get_element_type(element);
        if (type == NUMBER) {
            char *end;
            long value = std::strtol(element.c_str(), &end, 10);

            if (end == element.c_str() || *end != '\0' || errno == ERANGE) {
                throw InvalidElement();
            }
            stack.push(value);
        } else {
            performOperation(stack, element);
        }
    }
    if (stack.size() != 1) {
        throw InvalidOperationFormat();
    }
    return stack.top();
}

//===----------------------------------------------------------------------===//
//                       Exceptions 
//===----------------------------------------------------------------------===//

const char *InvalidElement::what() const throw()
{
    return "Error: Invalid element in your input";
}

const char *InvalidOperationFormat::what() const throw()
{
    return "Error: Invalid operation format";
}

const char *DivisionByZero::what() const throw()
{
    return "Error: You can't divide a number by 0";
}
