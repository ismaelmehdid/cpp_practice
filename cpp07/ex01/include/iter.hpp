#pragma once

#include <cstddef>

template <typename T, typename Func>
void iter(T *array, size_t length, Func func)
{
    if (!array)
        return ;
    for (size_t i = 0; i < length; i++) {
        func(&array[i]);
    }
}
