#include "../include/iter.hpp"

#include <iostream>

static void increment(int *value)
{
    if (!value)
        return ;
    (*value)++;
}

template <typename T>
static void print_value(T *value)
{
    if (!value)
        return ;
    std::cout << *value << " ";
}

static void scream_it(std::string *string)
{
    if (!string)
        return ;
    (*string).append("!");
}

int main(void)
{
    //===---------------------------------------------===//
    int values[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << "Before: " << std::endl;
    iter(values, 10, print_value<int>);

    std::cout << std::endl;

    iter(values, 10, increment); // or: iter<int, void (*)(int*)>(values, 10, increment);
    std::cout << "After: " << std::endl;
    iter(values, 10, print_value<int>);

    std::cout << std::endl;
    //===---------------------------------------------===//

    std::cout << std::endl;

    //===---------------------------------------------===//
    std::string string_values[4] = {"hello", "that's", "me", "bob"};
    std::cout << "Before: " << std::endl;
    iter(string_values, 4, print_value<std::string>);

    std::cout << std::endl;

    iter(string_values, 4, scream_it);
    std::cout << "After: " << std::endl;
    iter(string_values, 4, print_value<std::string>);

    std::cout << std::endl;
    //===---------------------------------------------===//
    return 0;
}