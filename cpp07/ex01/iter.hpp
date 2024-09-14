#pragma once

#include <iostream>

template <typename T, typename U>
void iter(T *arr, size_t arr_len, void (*func)(U &))
{
    if (!arr || !func)
        return ;
    for (size_t i = 0; i < arr_len; i++)
        func(arr[i]);
}
