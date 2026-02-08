#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T>
void iter(T *array, const std::size_t length, void (*function)(T &))
{
    if (!array || !function)
        return;
    for (std::size_t i = 0; i < length; ++i)
        function(array[i]);
}

template <typename T>
void iter(T *array, const std::size_t length, void (*function)(const T &))
{
    if (!array || !function)
        return;
    for (std::size_t i = 0; i < length; ++i)
        function(array[i]);
}

template <typename T>
void iter(const T *array, const std::size_t length, void (*function)(const T &))
{
    if (!array || !function)
        return;
    for (std::size_t i = 0; i < length; ++i)
        function(array[i]);
}

#endif
