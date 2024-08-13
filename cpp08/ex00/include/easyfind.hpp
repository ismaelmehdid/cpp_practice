#pragma once

#include <algorithm>
#include <iostream>

template<typename T>
void easyfind(T &container, int toFind)
{
    typename T::iterator res = std::find(container.begin(), container.end(), toFind);
    if (res != container.end()) {
        std::cout << toFind << " has been found." << std::endl;
    } else {
        std::cout << toFind << " hasn't been found." << std::endl;
    }
}