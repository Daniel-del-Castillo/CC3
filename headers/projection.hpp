#pragma once

#include <array>

// This function represents the projection basic function.
template<unsigned SIZE1, unsigned SIZE2>
std::array<unsigned, 1> projection(const std::array<unsigned, SIZE2>& array)  {
    static_assert(SIZE1 <= SIZE2 && SIZE1 > 0);
    std::array<unsigned, 1> result;
    result[0] = array[SIZE1 - 1];
    return result;
}

