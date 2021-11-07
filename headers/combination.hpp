#pragma once

#include <array>
#include <algorithm>

// This function represents the combination basic function.
template<unsigned SIZE1, unsigned SIZE2>
std::array<unsigned, SIZE1 + SIZE2> combination(
    const std::array<unsigned, SIZE1>& array1,
    const std::array<unsigned, SIZE2>& array2
) noexcept {
    std::array<unsigned, SIZE1 + SIZE2> result;
    std::copy(array1.begin(), array1.end(), result.begin());
    std::copy(array2.begin(), array2.end(), result.begin() + SIZE1);
    return result;
}

